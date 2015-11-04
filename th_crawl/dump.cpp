//////////////////////////////////////////////////////////////////////////////////////////////////
//
// 파일이름: dump.cpp
//
// 내용: 덤프하자
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <direct.h>
#include <stdio.h>
#include <time.h>
#include "player.h"
#include "display.h"
#include "environment.h"
#include "skill_use.h"
#include "note.h"
#include "god.h"

extern const char *version_string;



extern display_manager DisplayManager;
bool Dump(int type)
{
	char temp[100];
	mkdir("morgue");
	FILE *fp;  
	struct tm *t;
	time_t now;
	time(&now);
	t=localtime(&now);

	sprintf_s(temp,100,"morgue/%s-%04d%02d%02d-%02d%02d%02d.txt",you.user_name.name.c_str(),1900+t->tm_year,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
	fp = fopen(temp,"wt");
	
	fprintf_s(fp,"동방크롤 %s 덤프 파일\n\n",version_string);
	if(type == 1)
	{
		fprintf_s(fp,"레벨 %d의 %s %s %s \"%s\" (HP %d/%d)\n",you.level,tribe_type_string[you.tribe],job_type_string[you.job],you.GetCharNameString()->c_str(), you.user_name.name.c_str(),you.hp,you.max_hp);
		fprintf_s(fp,"             %s에서 ",CurrentLevelString());
		switch(you.dead_reason)
		{
			case DR_NONE:
				fprintf_s(fp,"알수없는 이유");
				if(you.dead_order)
				{
					fprintf_s(fp,"(%d 데미지", you.dead_order->damage);
					if(you.dead_order->order)
						fprintf_s(fp,",%s", you.dead_order->order->GetName()->name.c_str());
					fprintf_s(fp,")", you.dead_order->damage);
				}
				fprintf_s(fp,"에 의해 죽었다.\n");
				break;
			case DR_HITTING:
				if(you.dead_order)
				{
					if(you.dead_order->order)
						fprintf_s(fp,"%s", you.dead_order->order->GetName()->name.c_str());
					switch(you.dead_order->type)
					{
						case ATT_NONE:
						case ATT_SMITE:
						default:
							if(you.dead_order->order)
								fprintf_s(fp,"에 의해 ");
							fprintf_s(fp,"죽었다.");
							break;
						case ATT_NOISE:
							if(you.dead_order->order)
								fprintf_s(fp,"의 굉음에 의해 ");
							fprintf_s(fp,"고막이 터져죽었다.");
							break;
						case ATT_NORMAL:
						case ATT_S_POISON:
						case ATT_NORMAL_HIT:
							if(you.dead_order->order)
								fprintf_s(fp,"에게 ");
							fprintf_s(fp,"맞아죽었다.");
							break;
						case ATT_VAMP:
							if(you.dead_order->order)
								fprintf_s(fp,"에게 ");
							fprintf_s(fp,"빨려죽었다.");
							break;
						case ATT_WALL:
							if(you.dead_order->order)
								fprintf_s(fp,"에게 ");
							else
								fprintf_s(fp,"벽에 ");
							fprintf_s(fp,"부딪혀 죽었다.");
							break;
						case ATT_STONE_TRAP:
							fprintf_s(fp,"바위에 새끼발가락을 찧여 죽었다.");
							break;
						case ATT_THROW_NORMAL:
						case ATT_THROW_WATER:
							if(you.dead_order->order)
								fprintf_s(fp,"에게 ");
							fprintf_s(fp,"피탄당했다.");
							break;
						case ATT_FIRE:
						case ATT_THROW_FIRE:
						case ATT_CLOUD_FIRE:
							if(you.dead_order->order)
								fprintf_s(fp,"에 의해 ");
							fprintf_s(fp,"불타죽었다,");
							break;
						case ATT_COLD:
						case ATT_THROW_COLD:
						case ATT_CLOUD_COLD:
							if(you.dead_order->order)
								fprintf_s(fp,"에 의해 ");
							fprintf_s(fp,"얼어죽었다.");
							break;
					}
					fprintf_s(fp,"(%d 데미지)\n", you.dead_order->damage);
				}
				else
					fprintf_s(fp,"알수없는 데미지에 의해 죽었다.\n");
				break;
			case DR_POISON:
				fprintf_s(fp,"독에 중독되어 죽었다.\n");
				break;
			case DR_POTION:	
				fprintf_s(fp,"물약에 의해\n");
				if(you.dead_order)
					fprintf_s(fp,"(%d 데미지)", you.dead_order->damage);
				fprintf_s(fp,"에 의해 죽었다.\n");
				break;
			case DR_QUIT:
				fprintf_s(fp,"게임을 포기했다.\n");
				break;
			case DR_HUNGRY:
				fprintf_s(fp,"굶어죽었다.\n");
				break;
			case DR_MIRROR:
				if(you.dead_order)
				{
					if(you.dead_order->order)
					{
						fprintf_s(fp,"%s", you.dead_order->order->GetName()->name.c_str());
						fprintf_s(fp,"의 ");
					}

				}
				fprintf_s(fp,"반사데미지로 죽었다.");
				if(you.dead_order)
				{
					fprintf_s(fp,"(%d 데미지)\n", you.dead_order->damage);
				}
				break;

			case DR_EFFECT:
				fprintf_s(fp,"부작용에 의해 죽었다.\n");
				break;
			case DR_ESCAPE:
				if(you.haveGoal())
					fprintf_s(fp,"%d개의 쪽지를 들고 탈출하는데 성공했다.\n", you.haveGoal());
				else
					fprintf_s(fp,"성과없이 탈출했다.\n");
				break;
		}		
		fprintf_s(fp,"             ");
		fprintf_s(fp,"최종턴 %d\n\n",you.turn);

	}

	fprintf_s(fp,"%s (%s %s %s)      턴: %d      ",you.user_name.name.c_str(),tribe_type_string[you.tribe],job_type_string[you.job],you.GetCharNameString()->c_str(),you.turn);

	if(you.god == GT_NONE)
	{
		fprintf_s(fp,"무신앙\n\n");
	}
	else
	{
		fprintf_s(fp,"신앙: %s %c%c%c%c%c%c\n\n",GetGodString(you.god),pietyLevel(you.piety)>=1?'*':'.',pietyLevel(you.piety)>=2?'*':'.',pietyLevel(you.piety)>=3?'*':'.',pietyLevel(you.piety)>=4?'*':'.',pietyLevel(you.piety)>=5?'*':'.',pietyLevel(you.piety)>=6?'*':'.');
	}
	fprintf_s(fp,"HP: %4d/%4d             AC:%4d             힘  :%4d\n",you.hp,you.max_hp,you.ac,you.s_str);
	fprintf_s(fp,"MP: %4d/%4d             EV:%4d             민첩:%4d\n",you.mp,you.max_mp,you.ev,you.s_dex);
	fprintf_s(fp,"                          SH:%4d             지능:%4d\n\n",you.sh,you.s_int);
	int resist_ = you.fire_resist;
	int resist2_ = you.confuse_resist;
	fprintf_s(fp,"화염저항: %c %c %c      혼란저항: %c           무기: " ,resist_>=1?'+':(resist_<=-1?'-':'.'),resist_>=2?'+':(resist_<=-2?'-':'.'),resist_>=3?'+':(resist_<=-3?'-':'.'),resist2_>=1?'+':(resist2_<=-1?'-':'.'));
	if(you.equipment[ET_WEAPON])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_WEAPON]->id,you.equipment[ET_WEAPON]->GetName().c_str());
	else
		fprintf_s(fp,"맨손\n");
	resist_ = you.ice_resist;
	resist2_ = you.invisible_view;
	fprintf_s(fp,"냉기저항: %c %c %c      투명보기: %c           탄막: " ,resist_>=1?'+':(resist_<=-1?'-':'.'),resist_>=2?'+':(resist_<=-2?'-':'.'),resist_>=3?'+':(resist_<=-3?'-':'.'),resist2_>=1?'+':(resist2_<=-1?'-':'.'));
	if(you.throw_weapon)
		fprintf_s(fp,"%c) %s\n",you.throw_weapon->id,you.throw_weapon->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");

	resist_ = you.poison_resist;
	resist2_ = you.power_keep;
	fprintf_s(fp,"독저항  : %c          파워유지: %c           몸통: " ,resist_>=1?'+':(resist_<=-1?'-':'.'),resist2_>=1?'+':(resist2_<=-1?'-':'.'));
	if(you.equipment[ET_ARMOR])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_ARMOR]->id,you.equipment[ET_ARMOR]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");


	resist_ = you.elec_resist;
	fprintf_s(fp,"전기저항: %c                                방패: ",resist_>=1?'+':(resist_<=-1?'-':'.'));
	if(you.equipment[ET_SHIELD])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_SHIELD]->id,you.equipment[ET_SHIELD]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");	

	fprintf_s(fp,"                                           머리: ");
	if(you.equipment[ET_HELMET])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_HELMET]->id,you.equipment[ET_HELMET]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");

	fprintf_s(fp,"                                           망토: ");
	if(you.equipment[ET_CLOAK])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_CLOAK]->id,you.equipment[ET_CLOAK]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");

	fprintf_s(fp,"                                           손  : ");
	if(you.equipment[ET_GLOVE])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_GLOVE]->id,you.equipment[ET_GLOVE]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");

	fprintf_s(fp,"                                           발  : ");
	if(you.equipment[ET_BOOTS])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_BOOTS]->id,you.equipment[ET_BOOTS]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");

	fprintf_s(fp,"                                           목걸이  : ");
	if(you.equipment[ET_NECK])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_NECK]->id,you.equipment[ET_NECK]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");		

	fprintf_s(fp,"                                           왼반지  : ");
	if(you.equipment[ET_LEFT])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_LEFT]->id,you.equipment[ET_LEFT]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");

	fprintf_s(fp,"                                           오른반지: ");      
	if(you.equipment[ET_RIGHT])
		fprintf_s(fp,"%c) %s\n",you.equipment[ET_RIGHT]->id,you.equipment[ET_RIGHT]->GetName().c_str());
	else
		fprintf_s(fp,"없음\n");


	fprintf_s(fp,"\n\n당신은 %s에 있다.\n",CurrentLevelString());

	fprintf_s(fp,"\n\n\n<인벤토리>\n"/*,you.item_weight,you.max_item_weight*/);

	
	list<item>::iterator first,end;
	first = you.item_list.begin();
	end = you.item_list.end();

	for(item_type_simple i = ITMS_FIRST ;i != ITMS_LAST ; i=(item_type_simple)(i+1))
	{
		bool exist = false;
		list<item>::iterator it;
		for(it = first; it!=end;it++)
		{
			if((*it).isSimpleType(i))
			{
				int equip = you.isequip(it);
				if(!exist)
				{
					fprintf_s(fp,"\n%s\n",GetItemTypeSting(i));
					exist = true;
				}
				fprintf_s(fp,"  %c - %s",(*it).id,(*it).GetName().c_str());
				if(equip)
					fprintf_s(fp,"%s",(equip==1?"(장착)":(equip==2?"(왼손)":"(오른손)")));
				fprintf_s(fp,"\n");
			}
		}
	}

	fprintf_s(fp,"\n\n\n<스킬>\n\n");

	int skt = 0;
	while(skt < SKT_MAX)
	{
		if(you.skill[skt].level)
			fprintf_s(fp,"  %4s %3d (%d%%)\n",skill_string((skill_type)skt),you.skill[skt].level,GetSkillPercent(you.skill[skt]));
		skt++;
	}


	fprintf_s(fp,"\n\n\n기억하고 있는 주문들\n");
	if(you.currentSpellNum)
		fprintf_s(fp,"\n%-34s %-20s","마법이름","학파");
	for(int i=0;i<52;i++)
	{
		if(you.MemorizeSpell[i])
		{
			spell_list spell_ = (spell_list)you.MemorizeSpell[i];
			fprintf_s(fp,"\n%c - %-30s %-20s",i<26?'a'+i:'A'+(i-26),SpellString(spell_),GetSpellSchoolString(spell_).c_str());
		}
	}
	if(you.currentSpellNum)
		fprintf_s(fp,"\n\n당신은 %d개의 마법을 배우고 있으며 %d의 마법 레벨이 남았다.\n",you.currentSpellNum,you.remainSpellPoiont);
	else
		fprintf_s(fp,"\n당신은 마법을 배우고 있지 않다.\n",you.currentSpellNum,you.remainSpellPoiont);



	
	fprintf_s(fp,"\n\n\n");


	if(!DisplayManager.text_log.text_list.empty())
	{
		list<text_dummy*>::iterator it;
		it = DisplayManager.text_log.text_list.end();
		it--;
		int view_length = DisplayManager.log_length;
		int i = 15;
		while(i)
		{
			if(it == DisplayManager.text_log.text_list.begin())
				break;
			it--;
			if((*it)->enter)
			{
				i--;
				if(i<=0)
				{
					it++;
					break;
				}
			}
		}
		float x = 0, y = 0;
		for(i = 0;i < view_length && it != DisplayManager.text_log.text_list.end();it++)
		{			
			
			fprintf_s(fp,"%s", (*it)->text.c_str());
			if((*it)->enter)
			{
				fprintf_s(fp,"\n", (*it)->text.c_str());
			}
		}
	}


	fprintf_s(fp,"\n\n\n");
	fprintf_s(fp,"%8s|%-18s|%s\n","턴","장소","내용");

	for(list<note_dummy>::iterator it = save_note.note_list.begin(); it != save_note.note_list.end(); it++)
	{
		fprintf_s(fp,"%8d|%-18s|%s\n",it->turn,it->place.c_str(),it->text.c_str());
	}

	fclose(fp);
	return true;
}