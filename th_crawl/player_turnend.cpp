//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: player_.cpp
//
// ����: player���� �Լ�
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "player.h"
#include "unit.h"
#include "environment.h"
#include "beam.h"
#include "item.h"
#include "dump.h"
#include "potion.h"
#include "scroll.h"
#include "key.h"
#include "save.h"
#include "skill_use.h"
#include "weapon.h"
#include "god.h"
#include "note.h"
#include "spellcard.h"
#include "alchemy.h"
#include "tensi.h"
#include "replay.h"
#include "rect.h"
#include "soundmanager.h"
#include "tribe.h"
extern players you;
extern HANDLE mutx;

bool CheckMonsterPassive(int turn)
{
	for (auto it = env[current_level].mon_vector.begin(); it != env[current_level].mon_vector.end(); it++)
	{
		if (you.GetPunish(GT_KANAKO))
		{
			if (it->isLive() && it->GetId() == MON_ONBASIRA && !it->isUserAlly() && distan_coord(you.position, it->position) <= 2)
			{
				you.SetSlaying(-3);
				you.SetNoneMove(1);
			}
		}
		if (it->isLive() && it->GetId() == MON_ANCHOR && !it->isUserAlly() && distan_coord(you.position, it->position) <= 2)
		{
			you.SetNoneMove(1);
		}
	}
	return true;
}

interupt_type players::TurnEnd(bool *item_delete_)
{
	you.maybeAction();
	WaitForSingleObject(mutx, INFINITE);
	inter = IT_NONE;
	env[current_level].CheckFloor();
	int delay_ = GetDelay();
	if((s_pure_haste || s_haste || alchemy_buff == ALCT_HASTE || GetBuffOk(BUFFSTAT_HASTE)) && !s_slow)
		delay_ = delay_*0.7f;
	else if(s_slow && !(s_pure_haste || s_haste || alchemy_buff == ALCT_HASTE || GetBuffOk(BUFFSTAT_HASTE)))
		delay_ = delay_*1.5f;

	if(GetStatPanalty()) //�����г�Ƽ
	{
		delay_ = delay_*2.0f;
	}

	if(as_penalty > GetPenaltyMinus(3))
		delay_ *= 2;


	if(s_the_world!=0)
		delay_ = 0;
	prev_action = ACTT_NONE;



	if(s_tele || teleport_curse)
	{
		if(s_tele == 1 || (teleport_curse && !randA(400)))
		{
			Teleport();
			soundmanager.playSound("blink");
			printlog("���ڱ� ��� �ֺ��� ��ȭ�ߴ�.",false,false,false,CL_normal);
			SetInter(IT_TELE);
		}
		if(s_tele)
			s_tele--;
	}


	for(list<buff_class>::iterator it=buff_list.begin();it!=buff_list.end();)
	{
		list<buff_class>::iterator temp = it;
		it++;
		if(temp->turn>0){
			temp->turn--;
		}
		if(temp->turn==0)
		{
			UpDownBuff(temp->stat,-1*temp->value);
			buff_list.erase(temp);
		}
	}

	

	if(s_autumn>0)
	{
		s_autumn --;
	}
	else if(s_autumn<0)
	{
		s_autumn++;
	}


	ReleaseMutex(mutx);
	if(you.s_the_world==0 || you.s_the_world==1)
		env[current_level].ActionSmoke(delay_);
	env[current_level].ActionFloor(delay_);
	if(you.s_the_world==0 || you.s_the_world==1)
	{
		env[current_level].ActionMonsterSpecial(delay_);
		if(env[current_level].ActionSmokeEffect())
		{
			inter = IT_SMOKE;
		}
	}
	WaitForSingleObject(mutx, INFINITE);
	SetInter(resetLOS());
	sight_reset = false;
	turn++;
	if(delay_){
		real_turn+=delay_;
		if(player_move){
			prev_real_turn = delay_;
			player_move = false;
		}
		else
			prev_real_turn+=delay_;
	}
	ReleaseMutex(mutx);
	if(env[current_level].ActionItem(delay_))
	{//�������� ���� �����Ǿ���.
		if(item_delete_)
			(*item_delete_) = true;
	}
	if(env[current_level].ActionEvent(delay_))
			SetInter(IT_EVENT);
	WaitForSingleObject(mutx, INFINITE);
	bool p_del = false;
	for(list<item>::iterator it = item_list.begin();it!=item_list.end();)
	{
		if(it->type == ITM_FOOD && it->value1 == 0)
		{
			it->value3--;
			if(it->value3 == 0)
			{
				list<item>::iterator temp = it;
				it++;
				if(!p_del)
				{
					printlog("�κ��丮�� �ִ� P���� �������. ",false,false,false,CL_normal);
					p_del = true;
				}
				DeleteItem(temp);
			}
			else
				it++;
		}
		else if(it->type >=ITM_WEAPON_FIRST && it->type<ITM_WEAPON_LAST && it->value6 > 0)
		{
			it->value6--;
			if(it->value6 == 0)
			{
				switch(it->value5)
				{
				case WB_FIRE:			
					printlog("���Ⱑ Ÿ������ ���� �����. ",true,false,false,CL_normal);
					break;
				case WB_COLD:			
					printlog("���⿡�� ������ �ñⰡ ���ƴ�. ",true,false,false,CL_normal);
					break;		
				case WB_POISON:			
					printlog("���̻� ���⿡�� ���� �������� �ʴ´�. ",true,false,false,CL_normal);	
					break;	
				case WB_CURSE:		
					printlog("���⿡�� ������ ���� ��������. ",true,false,false,CL_normal);	
					break;
				case WB_WEATHER	:
					printlog("���⿡�� ����� ����� ���̻� ���������ʴ´�. ",true,false,false,CL_normal);	
					break;
				case WB_AUTUMN:
					printlog("����� ���̻� �����غ����� �ʴ´�. ",true,false,false,CL_normal);	
					break;
				case WB_MANA_REGEN:
					printlog("������ �帧�� �������. ",true,false,false,CL_white_blue);	
					break;
				case WB_FAST_CAST:
					printlog("�Ӹ�ȸ���� �ٽ� ��������. ",true,false,false,CL_white_blue);	
					break;
				case WB_PROTECT:
					AcUpDown(0,-5);
					printlog("��ȣ�� �������. ",true,false,false,CL_white_blue);	
					break;
				default:			
					printlog("��� ����� ���׿� �ɷ��ִ�. ",true,false,false,CL_danger);	
					break;		
				}
				it->value5 = 0;
			}
			it++;
		}
		else
			it++;
	}
	if(alchemy_buff == ALCT_POISON_BODY)
	{
		for(auto it = env[current_level].mon_vector.begin();it != env[current_level].mon_vector.end(); it++)
		{
			if((you.position.x-it->position.x)*(you.position.x-it->position.x)+(you.position.y-it->position.y)*(you.position.y-it->position.y)<=2)
			{		
				if(!it->isUserAlly())
					it->SetPoison(5+randA(5), 50, false);
			}
		}
	}

	ReleaseMutex(mutx);
	env[current_level].ActionMonster(delay_);
	WaitForSingleObject(mutx, INFINITE);
	if(sight_reset) //���Ͱ� ���� ������ �þ߰� ���� ��찡 ������
		SetInter(resetLOS()); //������ ������ ���� ���� �۾��̹Ƿ� �ʿ��Ҷ��� �ҷ�����
	env[current_level].ClearShadow();
	ReleaseMutex(mutx);
	if(s_poison)
	{
		if(poison_percent(s_poison))
		{
			int damage_;
			damage_ = HpUpDown(-poison_damage(s_poison),DR_POISON);
			if(damage_==-1)
			{
				printlog("���� �������� �ް� �ִ�. ",false,false,false,CL_normal);
				if(GetHp()<30)
					SetInter(IT_POISON);
			}
			else if(damage_>=-4)
			{
				printlog("���� ���� �������� �ް� �ִ�. ",false,false,false,CL_small_danger);
				if(GetHp()<100)
					SetInter(IT_POISON);
			}
			else
			{
				printlog("�ſ� ���� ���� �������� �ް� �ִ�. ",false,false,false,CL_danger);
				SetInter(IT_POISON);
			}
		}
		s_poison--;
		if(!s_poison)
			printlog("���� ġ��Ǿ���. ",false,false,false,CL_good);
		else if(s_poison%30 == 0)
			printlog("������ �ణ ȸ���Ǿ���. ",false,false,false,CL_good);
	}
	WaitForSingleObject(mutx, INFINITE);
	if(s_might)
	{
		s_might--;
		if(!s_might)
		{
			printlog("���� ������� ���ƿԴ�. ",false,false,false,CL_blue);
			StatUpDown(-5, STAT_STR);
			SetInter(IT_STAT);
		}
	}
	if(s_clever)
	{
		s_clever--;
		if(!s_clever)
		{
			printlog("������ ������� ���ƿԴ�. ",false,false,false,CL_blue);
			StatUpDown(-5, STAT_INT);
			SetInter(IT_STAT);
		}
	}
	if(s_agility)
	{
		s_agility--;
		if(!s_agility)
		{
			printlog("��ø�� ������� ���ƿԴ�. ",false,false,false,CL_blue);
			StatUpDown(-5, STAT_DEX);
			EvUpDown(0,-5);
			SetInter(IT_STAT);
		}
	}
	{
		if(s_str < m_str && randA_1(20000) <= delay_)
		{
			s_str++;
			printlog("�Ҿ���� ���� ȸ���Ǿ���. ",false,false,false,CL_blue);
		}	
		else if(s_dex < m_dex && randA_1(20000) <= delay_)
		{
			s_dex++;
			printlog("�Ҿ���� ��ø�� ȸ���Ǿ���. ",false,false,false,CL_blue);
		}
		else if(s_int < m_int && randA_1(20000) <= delay_)
		{
			s_int++;
			printlog("�Ҿ���� ������ ȸ���Ǿ���. ",false,false,false,CL_blue);
		}
	}
	if(s_haste)
	{
		s_haste--;
		if(!s_pure_haste && !s_haste && alchemy_buff != ALCT_HASTE)
		{
			printlog("�ӵ��� ������� ���ƿԴ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
		if(s_haste == 10 && s_pure_haste <= 10 && (alchemy_buff != ALCT_HASTE || alchemy_time<10))
		{
			printlog("�ӵ��� ���ƿ��� �ִ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if (s_pure_haste)
	{
		s_pure_haste--;
		if (!s_pure_haste && !s_haste && alchemy_buff != ALCT_HASTE)
		{
			printlog("���ǰ� �������. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
		if (s_pure_haste == 10 && s_haste <= 10 && (alchemy_buff != ALCT_HASTE || alchemy_time < 10))
		{
			printlog("���ǰ� ������� �ִ�. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}

		if (s_pure_haste)
		{
			bool least_one = false;
			for (vector<monster>::iterator it = env[current_level].mon_vector.begin(); it != env[current_level].mon_vector.end(); it++)
			{
				if (it->isLive() && env[current_level].isInSight(it->position) && !it->isUserAlly())
				{
					least_one = true;
					break;
				}
			}
			if (!least_one) {
				s_pure_haste = 0;
				printlog("�þ߳��� ���� ����� ���ǰ� �������. ", false, false, false, CL_blue);
				SetInter(IT_STAT);
			}
		}

	}
	if(s_wind)
	{
		s_wind--;
		if(!s_wind)
		{
			printlog("��ſ��� �����ִ� �ٶ��� ����������. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_knife_collect)
	{
		s_knife_collect--;
		if(!s_knife_collect)
		{
			printlog("���̻� ź���� �ڵ����� ȸ������ �ʴ´�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_drunken)
	{
		s_drunken--;
		if(!s_drunken)
		{
			printlog("����� �������� ���ȴ�. ",false,false,false,CL_white_blue);
			SetInter(IT_STAT);
		}
	}
	if(env[current_level].isViolet(you.position))
		you.SetLunatic(2);
	if(s_lunatic)
	{
		s_lunatic--;
		if(!s_lunatic)
		{
			printlog("����� ����� ������. ",false,false,false,CL_white_blue);
			SetInter(IT_STAT);
		}
	}
	if ((you.god == GT_JOON_AND_SION || you.GetPunish(GT_JOON_AND_SION)) && you.god_value[GT_JOON_AND_SION][0] != 0 &&
		you.god_value[GT_JOON_AND_SION][1] >= 0)
	{
		you.god_value[GT_JOON_AND_SION][1]--;
		if (you.god_value[GT_JOON_AND_SION][1] <= 0)
		{
			printlog("����� ���ǰ� ������. ", false, false, false, CL_joon_and_sion);
			if(!you.GetPunish(GT_JOON_AND_SION)) 
			{
				if (you.god_value[GT_JOON_AND_SION][0] == 1) {
					if (you.power >= 300)
						you.PowUpDown(-(you.power - 300));
				}
				you.god_value[GT_JOON_AND_SION][1] = -1;
				you.gift_count = GetGodGiftTime(god);
			}
			else {
				you.god_value[GT_JOON_AND_SION][1] = 0;
			}
			you.god_value[GT_JOON_AND_SION][0] = 0;
			//you.Ability(SKL_JOON_AND_SION_1, true, false);
			you.Ability(SKL_JOON_AND_SION_2, true, true);
			you.Ability(SKL_JOON_AND_SION_3, true, true);
			you.Ability(SKL_JOON_AND_SION_4, true, true);
			you.Ability(SKL_JOON_AND_SION_OFF, true, true);
			SetInter(IT_STAT);
		}
	}
	if(alchemy_time)
	{



		alchemy_time--;
		
		if(alchemy_time == 0)
		{
			alchemyonoff(alchemy_buff,false);
			SetInter(IT_STAT);
			alchemy_buff= ALCT_NONE;
		}
		else if(alchemy_time == 10)
		{
			alchemyalmostoff(alchemy_buff);
		}


	}


	if(s_confuse)
	{
		s_confuse--;
		if(!s_confuse)
		{
			printlog("ȥ���������� �������. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_slow)
	{
		s_slow--;
		if(!s_slow)
		{
			printlog("�ӵ��� ������� ���ƿԴ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_frozen)
	{
		s_frozen--;
		if(!s_frozen)
		{
			printlog("���پ��� ���� ��Ҵ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	ReleaseMutex(mutx);
	if(s_elec)
	{
		int power_=min(SpellCap(SPL_SHOCK),you.GetSpellPower(SpellSchool(SPL_SHOCK,0),SpellSchool(SPL_SHOCK,1),SpellSchool(SPL_SHOCK,2)));

		//WaitForSingleObject(mutx, INFINITE);
		if(randA(5)<2)
			skill_elec_passive(power_,&you);
		//ReleaseMutex(mutx);
		s_elec--;
		if(!s_elec)
		{
			printlog("������ �����. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	WaitForSingleObject(mutx, INFINITE);
	if(s_paralyse)
	{
		s_paralyse--;
		if(!s_paralyse)
		{
			printlog("�ٽ� ������ �� �ְ� �Ǿ���. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_levitation)
	{
		s_levitation--;
		if(!s_levitation)
		{
			if (env[current_level].dgtile[you.position.x][you.position.y].tile == DG_SEA)
			{
				printlog("����� �� ���� ��������. ", false, false, false, you.isSwim()? CL_blue :CL_danger);
			}
			else if(env[current_level].dgtile[you.position.x][you.position.y].tile == DG_LAVA){
				printlog("����� ��� ���� ��������. ", false, false, false, CL_danger);
			}
			else {
				printlog("���� �ε巴�� �����ߴ�. ", false, false, false, CL_blue);
			}
			int temp = you.Ability(SKL_LEVITATION_OFF,false,true,1);
			if(temp)
				you.Ability(SKL_LEVITATION,false,false,temp);
			SetInter(IT_STAT);
		}
		if(s_levitation == 10)
		{
			printlog("���� ���ſ����� �ִ�. ",false,false,false,CL_small_danger);
			SetInter(IT_STAT);
		}
	}
	if(s_graze)
	{
		s_graze--;
		if(!s_graze)
		{
			printlog("�� �̻� �׷���� ���� �ʴ´�. ",false,false,false,CL_blue);
			int temp = you.Ability(SKL_GRAZE_OFF,false,true,1);
			if(temp)
				you.Ability(SKL_GRAZE,false,false,temp);
			SetInter(IT_STAT);
		}
		if(s_graze == 10)
		{
			printlog("�׷���� ���������ִ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_silence)
	{
		s_silence--;

		if((s_silence-5)/2 < s_silence_range)
		{
			env[current_level].MakeSilence(position, s_silence_range, false);
			s_silence_range = (s_silence-5)/2 >0 ? (s_silence-5)/2 : 0;
			env[current_level].MakeSilence(position, s_silence_range, true);
		}

		if(!s_silence)
		{
			printlog("�Ҹ��� ����� ������ �������. ",false,false,false,CL_blue);
			env[current_level].MakeSilence(position, s_silence_range, false);
			SetInter(IT_STAT);
		}
	}
	if(s_sick)
	{
		s_sick--;
		if(!s_sick)
		{
			printlog("���� ���Ҵ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_veiling)
	{
		s_veiling--;
		if(!s_veiling)
		{
			printlog("�ְ��� �ٶ��� ����������. ",false,false,false,CL_blue);
			s_value_veiling = 0;
			SetInter(IT_STAT);
		}
	}
	if(s_invisible)
	{
		s_invisible--;
		if(!s_invisible)
		{
			printlog("���� �ٽ� ������������. ",false,false,false,CL_blue);
			int temp = you.Ability(SKL_INVISIBLE_OFF,false,true,1);
			if(temp)
				you.Ability(SKL_INVISIBLE,false,false,temp);
			SetInter(IT_STAT);
		}
		if(s_invisible == 10)
		{
			printlog("����� ������ ���� �����̰��ִ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_superman)
	{
		s_superman--;
		s_swift = 0;
		if(!s_superman)
		{
			printlog("����� ���̻� �ٸ��� �������ʴ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
		if(s_superman == 5)
		{
			printlog("����� �ٸ��� ���ſ������ִ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	
	ReleaseMutex(mutx);
	if(s_eirin_poison_time)
	{
		s_eirin_poison_time--;
		if(s_eirin_poison_time == 11)
		{			
			printlog("ġ���� ���� ���ۿ��� ���۵Ǿ���!",true,false,false,CL_danger);
			enterlog();
			SetInter(IT_STAT);
		}
		if(s_eirin_poison_time>0 && s_eirin_poison_time<=10)
		{
			int damage_ = min(s_eirin_poison,(s_eirin_poison/s_eirin_poison_time+1));
			HpUpDown(GetHp() <= damage_ ? -(GetHp() - 1) : -damage_, DR_EFFECT);
			s_eirin_poison -= damage_;
			SetInter(IT_POISON);		
			if(s_eirin_poison<=0)
			{
				s_eirin_poison = 0;
				s_eirin_poison_time = 0;
			}
		}
		//s_eirin_poison;
	}
	
	WaitForSingleObject(mutx, INFINITE);

	if(s_exhausted)
	{
		s_exhausted--;
	}	
	if(s_stasis)
	{
		s_stasis--;
		if(!s_stasis)
		{
			printlog("���� ���ذ� Ǯ�ȴ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(force_turn)
	{
		force_turn--;
		if(!force_turn)
		{
			printlog("������ ������� ���ƿԴ�. ",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}

	}
	if (s_super_graze)
	{
		s_super_graze--;
		if (!s_super_graze)
		{
			printlog("����� �ټ� ȸ�Ǵ� ������. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
		if (s_super_graze == 3)
		{
			printlog("����� �ټ� ȸ�ǰ� ���������ִ�. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}

	if (s_night_sight_turn>0)
	{
		s_night_sight_turn--;
		if (!s_night_sight_turn)
		{
			printlog("����� �߸����� ȸ���Ǿ���. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}
	if (s_sleep > 0)
	{
		if(randA(1))
			s_sleep--;
		if (!s_sleep)
		{
			printlog("����� ������ ����. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}
	if (s_sleep < 0)
	{
		s_sleep++;
		if (!s_sleep)
		{
			printlog("����� �ῡ�� ����. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}

	}
	if (you.s_pure_turn>0)
	{
		you.s_pure_turn--;
		if (!you.s_pure_turn)
		{
			you.s_pure = 0;
			printlog("����� �Ͻ��� ��ȭ�� �����Ǿ���. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}
	if (you.s_evoke_ghost)
	{
		ReleaseMutex(mutx);

		int level_ = you.GetSkillLevel(SKT_EVOCATE, true);
		level_ = max(level_, you.level / 3 + you.GetSkillLevel(SKT_EVOCATE, true) * 2 / 3);

		int power_decre_ = 12 - level_ / 3;
		you.PowUpDown(-power_decre_);

		if (GetProperty(TPT_PURE_POWER)) {
			if (randA(2) == 0) {
				you.HpUpDown(-1, DR_GHOST);
			}
		}
		if (you.power <= 0) {
			soundmanager.playSound("ufo");
			you.s_evoke_ghost = 0;
			printlog("����� �Ŀ��� ���� �Ҹ�Ǿ� ����ȭ�� �����Ǿ���. ", false, false, false, CL_danger);
			SetInter(IT_STAT);
		}

		WaitForSingleObject(mutx, INFINITE);

	}
	if (you.s_weather_turn>0)
	{
		if (you.s_weather == 2) //õ�չ���
		{
			if (randA(9) == 0) { //���� Ȯ���� ��ó�� ������ �����ȴ�.
				monster* mon_ = env[current_level].getRandomMonster(true);
				if (mon_) {
					rand_rect_iterator rand(mon_->position, 1, 1, false);
					while (!rand.end()) {
						coord_def pos_ = (*rand);
						if (env[current_level].isSight(pos_) && env[current_level].isInSight(pos_))
						{
							ReleaseMutex(mutx);
							soundmanager.playSound("elec");
							int damage_ = you.GetMaxHp() / 3;
							attack_infor temp_att(randC(3, damage_ / 3), damage_, 99, &you, you.GetParentType(), ATT_ELEC_BLAST, name_infor("����", false));
							BaseBomb(pos_, &img_blast[2], temp_att);
							env[current_level].MakeNoise(pos_, 20, NULL);
							WaitForSingleObject(mutx, INFINITE);
							break;
						}
						rand++;
					}
				}
			}
			else if (randA(1) == 0) //�Ϲ������� �������� ������
			{
				rand_rect_iterator rand(position, 8, 8, true);

				while (!rand.end()) {
					coord_def pos_ = (*rand);
					if (pow((float)abs(position.x - pos_.x), 2) + pow((float)abs(position.y - pos_.y), 2)<=64) {
						if (env[current_level].isSight(pos_) && env[current_level].isInSight(pos_))
						{
							ReleaseMutex(mutx);
							soundmanager.playSound("elec");
							int damage_ = you.GetMaxHp() / 3;
							attack_infor temp_att(randC(3, damage_ / 3), damage_, 99, &you, you.GetParentType(), ATT_ELEC_BLAST, name_infor("����", false));
							BaseBomb(pos_, &img_blast[2], temp_att);
							env[current_level].MakeNoise(pos_, 20, NULL);
							WaitForSingleObject(mutx, INFINITE);
						}
						break;
					}
					rand++;
				}
			}

		}
		you.s_weather_turn--;
		if (!you.s_weather_turn)
		{
			you.s_weather = 0;
			resetLOS();
			printlog("������ ������� ���ƿԴ�. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}
	if (you.s_weather == 3 && you.s_weather_turn > 0) {
		s_glow = 1;
	}
	else if (s_glow)
	{
		s_glow--;
		if (!s_glow)
		{
			printlog("����� ������ ������ ���� �����. ", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_slaying)
	{
		s_slaying = 0;
	}
	if (s_none_move)
	{
		s_none_move = 0;
	}
	if(s_spellcard)
	{
		s_spellcard--;
		//if(!s_spellcard)
		//{
		//	printlog("���� �극��ũ!",true,false,false,CL_danger);
		//	if(equipment[ET_NECK])
		//	{
		//		passive_spellcard((spellcard_passive_type)equipment[ET_NECK]->value3, equipment[ET_NECK]->value4, -1, 0);
		//	}
		//	else
		//	{
		//		printlog("[BUG]����ī�带 �������� ä�� ���缱��",true,false,false,CL_danger);
		//	}
		//	SetInter(IT_STAT);
		//}
		//if(s_spellcard == 5)
		//{
		//	printlog("����ī���� �ð��� ���� �� ��������.",false,false,false,CL_small_danger);
		//	SetInter(IT_STAT);
		//}
	}

	if(s_swift>0)
	{
		s_swift--;
		if(!s_swift)
		{
			printlog("����� �� �̻� �ٸ��� �������ʴ�.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
		if(s_swift == 10)
		{
			printlog("����� �ٸ��� ���ſ������ִ�.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if (s_swift<0)
	{
		s_swift++;
		if (!s_swift)
		{
			printlog("����� �� �̻� �ٸ��� �������ʴ�.", false, false, false, CL_white_blue);
			SetInter(IT_STAT);
		}
		if (s_swift == -5)
		{
			printlog("����� �ٸ��� ���ƿ��� �ִ�.", false, false, false, CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_mana_regen)
	{
		s_mana_regen--;
		if(!s_mana_regen)
		{
			printlog("����ȸ���ӵ��� ������ �Ǿ���.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_ghost>1)
	{
		s_ghost--;
		
		if(s_ghost == 1)
		{
			printlog("������ �󵵰� ������ �Ǿ���.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_mirror)
	{
		s_mirror--;

		if(!s_mirror)
		{
			printlog("������ �ݻ簡 ������.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}

	}
	if(s_dimension)
	{
		s_dimension--;
		
		if(s_dimension == 0)
		{			
			resetLOS(false);
			printlog("������ ������� ���ƿԴ�.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_timestep)
	{
		s_timestep--;

		if(s_timestep == 0)
		{
			printlog("����� ������ ���´�. ���� �ῡ�� �� ����. ",false,false,false,CL_swako);
			you.SetSlow(rand_int(4,6));
			SetInter(IT_STAT);
		}
	}
	if(s_paradox)
	{
		s_paradox--;
		if(s_paradox == 0)
		{			
			printlog("���ð�� �������.",false,false,false,CL_blue);
			SetInter(IT_STAT);
		}
	}
	if(s_the_world)
	{
		s_the_world--;

		if(s_the_world == 1)
		{
			printlog("�׸��� �ð��� �����̱� �����Ѵ�...",false,false,false,CL_small_danger);
			SetInter(IT_STAT);
		}

	}

	if(battle_count)
	{
		battle_count--;
		if(battle_count == 0)
		{
			ChangeBattleCount(false);
		}
	}

	if(!s_sick)
	{
		if(HpRecover(delay_) && inter == IT_NONE)
			SetInter(IT_HP_RECOVER);
	}
	if(MpRecover(delay_) && inter == IT_NONE)
		SetInter(IT_MP_RECOVER);
	

	PowDecrease(delay_);
	if(god != GT_NONE)
		god_turn++;
	ReleaseMutex(mutx);
	CheckPunish(delay_);
	GodAccpect_turn(god_turn);
	CheckMonsterPassive(god_turn);
	
	if(GetMp() == GetMaxMp())
	{
		s_mana_delay = 0;
		MpRecoverDelay(0,true);
	}


	WaitForSingleObject(mutx, INFINITE);
	prev_position.set(position.x,position.y);
	TraningStealth();


	ReleaseMutex(mutx);
	//SetInter(HungerApply());
	WaitForSingleObject(mutx, INFINITE);
	tension_turn = false;
	if(wiz_list.wizard_mode == 1)
		CheckTension();
	enterlog();



	ReleaseMutex(mutx);


	if (env[current_level].dgtile[you.position.x][you.position.y].tile == DG_SEA &&
		!you.isFly() && !you.isSwim())
	{
		drowned = true;
		int damage_ = you.GetMaxHp() / 10;
		you.damage(attack_infor(damage_ + 1, damage_ + 1, 99, &you, you.GetParentType(), ATT_DROWNING, name_infor("����", true)), true);
		SetInter(IT_DAMAGE);
	}	
	else if (env[current_level].dgtile[you.position.x][you.position.y].tile == DG_LAVA &&
		!you.isFly())
	{
		drowned = true;
		int damage_ = you.GetMaxHp() / 3;
		you.damage(attack_infor(damage_ + 1, damage_ + 1, 99, &you, you.GetParentType(), ATT_CLOUD_FIRE, name_infor("���", true)), true);

		damage_ = you.GetMaxHp() / 10;
		you.damage(attack_infor(damage_ + 1, damage_ + 1, 99, &you, you.GetParentType(), ATT_DROWNING, name_infor("����", true)), true);
		SetInter(IT_DAMAGE);
	}
	else
	{
		drowned = false;
	}


	if(s_paralyse || you.s_sleep < 0)
	{
		you.time_delay += you.GetNormalDelay();
		SetInter(TurnEnd());
	}
	return inter;
}
bool players::TraningStealth()
{	
	int panlty = equipment[ET_ARMOR]?-equipment[ET_ARMOR]->value2:0;
	if(!randA((200+150*panlty)/*/(bonus?2:1)*/))
	{
		//SkillTraining(SKT_STEALTH,1);
		return true;
	}
	return false;
}


bool players::isEnemyMonster(const monster* monster_info)
{
	return !monster_info->isUserAlly();
}	
bool players::isSightnonblocked(coord_def c)
{
	bool intercept = false;
	for(int i=RT_BEGIN;i!=RT_END;i++)
	{
		int length_ = 8;
		beam_iterator it(position,c,(round_type)i);
		while(!intercept && !it.end())
		{
						
			coord_def check_pos_ = (*it);
						
			if(you.s_dimension)
			{
				if(abs(god_value[GT_YUKARI][0] - check_pos_.x)>8)
					check_pos_.x += (god_value[GT_YUKARI][0] - check_pos_.x)>0?17:-17;
				if(abs(god_value[GT_YUKARI][1] - check_pos_.y)>8)
					check_pos_.y += (god_value[GT_YUKARI][1] - check_pos_.y)>0?17:-17;
			}


			if(length_ == 0) //�þ߰� �� �޾Ҵ�.
			{
				intercept = true;
				break;
			}
			if(!env[current_level].isMove(check_pos_,true,true))
			{
				intercept = true;
				break;
			}
			it++;
			length_--;
		}
		if(intercept == false)
			break;
		else if(i == RT_END - 1)
		{
			return false; //���ݺҰ����� ��ġ
		}
		else
			intercept = false;
	}
	return true;
}
bool players::isMemorizeSpell(int spell_)
{
	for(int i=0;i<52;i++)
	{
		if(MemorizeSpell[i] == spell_)
			return true;
	}
	return false;
}
bool players::CanMemorizeSpell(int spell_)
{

	if(spell_ <= SPL_NONE || spell_ > SPL_MAX)
		return false;
	int skill_level_ = SpellLevel((spell_list)spell_);
	
	//if(you.skill[SKT_SPELLCASTING].level == 0)
	//{
	//	return false;
	//}
	if(you.level<skill_level_)
	{
		return false;
	}
	if(you.remainSpellPoiont<skill_level_)
	{
		return false;
	}
	return true;
}
parent_type players::GetParentType()
{
	return PRT_PLAYER;
}
interupt_type players::SetInter(interupt_type inter_)
{
	if(inter < inter_)
		inter = inter_;
	return inter;
}



void deadlog()
{
	{
		char temp[200];	
		if(you.dead_order && you.dead_order->order)
			sprintf_s(temp,200,"%s���� �׾���.",you.dead_order->order->GetName()->name.c_str());
		else if(you.dead_reason == DR_HUNGRY)
			sprintf_s(temp,200,"�����׾���.");
		else if(you.dead_reason == DR_QUIT)
			sprintf_s(temp,200,"������ �����ߴ�.");
		else if(you.dead_reason == DR_ESCAPE)
			sprintf_s(temp,200,"������ Ż���ߴ�.");
		else if(you.dead_reason == DR_POISON)
			sprintf_s(temp,200,"���� �ߵ��Ǿ� �׾���.");
		else if(you.dead_reason == DR_EFFECT)
			sprintf_s(temp,200,"���ۿ뿡 ���� �׾���.");
		else
			sprintf_s(temp,200,"�׾���.");
		AddNote(you.turn,CurrentLevelString(),temp,CL_normal);
	}
}


void resurectionlog(char* reason)
{
	char temp[200];
	sprintf_s(temp, 200, "%s�� ���ؼ� ��Ȱ�ߴ�.", reason);
	AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
}

int caculScore();


void GameOver()
{
	StopCurrentBGM();
	bool replay_mode_ = ReplayClass.ReplayMode();
	

	if(game_over)
		return;

	if(isNormalGame())
	{
		char temp[256];
		sprintf_s(temp,256,"%d    ���� %d�� %s %s %s \"%s\"",caculScore(),you.level,tribe_type_string[you.tribe],job_type_string[you.job],you.GetCharNameString()->c_str(), you.user_name.name.c_str());


		ReplayClass.StopReplay(temp);

	}
	else if(isArena())
	{
		{
			char temp[256];
			sprintf_s(temp,256,"�Ʒ��� ���� %d",you.level);
			ReplayClass.StopReplay(temp);
		}
	}
	else if (isSprint())
	{
		char temp[256];
		sprintf_s(temp, 256, "%d    ���� %d�� %s %s %s \"%s\"", caculScore(), you.level, tribe_type_string[you.tribe], job_type_string[you.job], you.GetCharNameString()->c_str(), you.user_name.name.c_str());


		ReplayClass.StopReplay(temp);
	}
	else
	{
		ReplayClass.DeleteRpy();
	}




	if(you.dead_reason != DR_ESCAPE)
		printlog("�׾���...",true,false,false,CL_normal);
	else
		printlog("������ Ż���ߴ�.",true,false,false,CL_normal);

	printlog("------------������------------",true,false,false,CL_normal);

	deadlog();
	string dump_;
	bool dump_ok = false;

	if(isNormalGame() || isSprint())
	{
		for(list<item>::iterator it = you.item_list.begin(); it != you.item_list.end();it++)
		{
			it->Identify();
		}
		WaitForSingleObject(mutx, INFINITE);
		if(!replay_mode_)
			dump_ok = Dump(1,&dump_);
		if((wiz_list.wizard_mode != 2 || you.dead_reason == DR_ESCAPE || you.dead_reason == DR_QUIT) && !replay_mode_)
			delete_file();
		ReleaseMutex(mutx);




	}
	while(1)
	{
		int select = waitkeyinput();
		if(select==VK_RETURN)
		{
			break;
		}
	}
	if(isNormalGame() || isSprint())
	{
		iteminfor(true);
		waitkeyinput(true);
		changedisplay(DT_GAME);
	

		if(dump_ok)
		{
			FILE *fp = fopen(dump_.c_str(),"rt");

			if(fp)
			{
				char temp[256];
			
				WaitForSingleObject(mutx, INFINITE);
				ReleaseMutex(mutx);
				deletesub();
				changedisplay(DT_SUB_TEXT);
				for(int i=0;i<26;i++)
				{
					fgets(temp,256,fp);
					//fscanf(fp,"%s",temp);				
					printsub(temp,true,CL_normal);
				}			
				printsub("",true,CL_magic);
				if(you.dead_reason == DR_ESCAPE && you.haveOrb())
				{
					if(wiz_list.wizard_mode == 1)
						printsub("�÷������ּż� �����մϴ�! ������ ���ڵ������ �����غ��ô�!",true,CL_magic);
					else if(wiz_list.wizard_mode == 2)
						printsub("�÷������ּż� �����մϴ�! ������ ���̺���� �����غ��ô�!",true,CL_magic);
					else
						printsub("Ŭ���� ���ϵ帳�ϴ�! �׸��� �÷������ּż� �����մϴ�!",true,CL_magic);
				}
				printsub("",true,CL_help);
				printsub("����� ������ morgue������ ����Ǿ��ֽ��ϴ�.",true,CL_help);
				printsub("",true,CL_help);
				printsub("�����Ͻ÷��� Enter�� ESC�� ��������.",true,CL_help);
				bool end_ = false;
				while(!end_)
				{
					int key_ = waitkeyinput(true);
					switch(key_)
					{
					default:
						break;
					case VK_RETURN:
					case VK_ESCAPE:
						end_ = true;
						break;
					}
				}
				fclose(fp);
			}

		}


	}

	game_over = true;
}


bool poison_percent(int value)
{
	if(value<15)
		return randA(4)==1;
	else if(value<30)
		return randA(2)==1;
	else if(value<45)
		return randA(2)>0;
	else
		return 1;
}
int poison_damage(int value)
{
	if(value<50)
		return 1;
	else if(value<100)
		return randA(1)+1;
	else if(value<125)
		return randA(2)+1;
	else
		return randA(3)+1;
}