//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: wiz.cpp
//
// ����: ���ڵ���!!
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "environment.h"
#include "display.h"
#include "smoke.h"
#include "key.h"
#include "mon_infor.h"

#include "spellcard.h"
#include "skill_use.h"
#include "weapon.h"
#include "map.h"
#include "evoke.h"
#include "god.h"
#include "tribe.h"


extern HANDLE mutx;
wiz_infor wiz_list;


bool skill_summon_bug(int pow, bool short_, unit* order, coord_def target);

void wiz_mode()
{

	if(wiz_list.wizard_mode != 1)
	{

		
		printlog("#### ���! ���ڵ���� ��������� �ȵǸ� ��̸� ū������ ����߸��ϴ�. ### ",true,false,false,CL_danger);
		printlog("��¥�� ų����? (Y/N) ",false,false,false,CL_danger);

		
		int key_ = waitkeyinput();
		switch(key_)
		{
		case 'Y':
			enterlog();
			break;
		default:
			printlog("���ڵ��带 ���",true,false,false,CL_help);
			return;
		}

	}



	printlog("<���ڵ���> ��� ��ɾ�?  ( ? - ���� )",true,false,false,CL_help);
	wiz_list.wizard_mode = 1;
	while(1)
	{
		int key_ = waitkeyinput();
	
		changedisplay(DT_GAME);
		switch (key_)
		{
		case 'D': //�ʹ�����
			for (int i = 0; i < DG_MAX_X; i++)
				for (int j = 0; j < DG_MAX_Y; j++)
					env[current_level].magicmapping(i, j);
			break;
		case 'f': //����
			//for(int i = -1;i<2;i++)
			//	for(int j = -1;j<2;j++)
			//		env[current_level].MakeSmoke(coord_def(i+you.position.x,j+you.position.y),img_fog_fire,SMT_NORMAL,10,0,&you);
			MakeCloud(you.position, img_fog_thunder, SMT_ELEC, rand_int(8, 10), rand_int(80, 120), 0, 5, &you);
			break;
		case 'A':
		{
			printlog("p-���� s-��ũ�� e-�ߵ��� v-����ī�� r-���� b-å a-�� R-����� f-��ô����", true, false, false, CL_help);
			printlog("��� �������� ����?", false, false, false, CL_help);
			key_ = waitkeyinput();
			switch (key_)
			{
			case 'p':
			{
				int list[] = { PT_WATER,	PT_HEAL, PT_POISON,	PT_HEAL_WOUND, PT_MIGHT, PT_HASTE, PT_CONFUSE,
					PT_SLOW, PT_PARALYSIS, PT_CLEVER, PT_AGILITY, PT_MAGIC, PT_LEVETATION, PT_POWER,
					PT_DOWN_STAT, PT_RECOVER_STAT, PT_ALCOHOL };
				enterlog();
				printlog("a-�� b-ġ�� c-�� d-ü��ȸ�� e-�� f-���� g-ȥ�� h-���� i-����", true, false, false, CL_help);
				printlog("j-���� k-��ø l-���� m-���� n-�Ŀ� o-�ɷ�ġ���� p-�ɷ�ġȸ�� q-��", true, false, false, CL_help);
				printlog("��� ������ ����?", false, false, false, CL_help);
				key_ = waitkeyinput();
				if (key_ >= 'a' && key_ <= 'q')
				{
					for (int i = 0; i < 10; i++)
					{
						item_infor t;
						makeitem(ITM_POTION, 0, &t, list[key_ - 'a']);
						env[current_level].MakeItem(you.position, t);
						enterlog();
					}
				}
				else {
					printlog(" ���", true, false, false, CL_help);
				}
			}
			return;
			case 's':
			{
				int list[] = { SCT_TELEPORT,SCT_IDENTIFY,SCT_NONE,SCT_CURSE_WEAPON,SCT_CURSE_ARMOUR,SCT_REMOVE_CURSE,
					SCT_BLINK,SCT_MAPPING,SCT_ENCHANT_WEAPON_1,	SCT_ENCHANT_ARMOUR,SCT_FOG,SCT_DETECT_CURSE,
					SCT_CURSE_JEWELRY,SCT_SILENCE,SCT_SOUL_SHOT,SCT_CHARGING,SCT_AMNESIA, SCT_SANTUARY, SCT_BRAND_WEAPON };
				enterlog();
				printlog("a-���� b-�ĺ� c-���� d-�������� e-������ f-�������� g-�����̵� h-��������", true, false, false, CL_help);
				printlog("i-���Ⱝȭ j-����ȭ k-���� l-���ְ��� m-��ű����� n-���� o-���� p-��������", true, false, false, CL_help);
				printlog("q-���� r-���� s-��������", true, false, false, CL_help);
				printlog("��� ��ũ���� ����?", false, false, false, CL_help);
				key_ = waitkeyinput();
				if (key_ >= 'a' && key_ <= 's')
				{
					for (int i = 0; i < 10; i++)
					{
						item_infor t;
						makeitem(ITM_SCROLL, 0, &t, list[key_ - 'a']);
						env[current_level].MakeItem(you.position, t);
						enterlog();
					}
				}
				else {
					printlog(" ���", true, false, false, CL_help);
				}
			}
			return;
			case 'e':
			{
				int list[] = { EVK_PAGODA,EVK_AIR_SCROLL,EVK_DREAM_SOUL,EVK_BOMB, EVK_GHOST_BALL, EVK_SKY_TORPEDO, EVK_MAGIC_HAMMER };
				enterlog();
				printlog("a-��ž b-����η縶�� c-��ȥ d-������ e-������ģ f-���߾�� g-�����ġ", true, false, false, CL_help);
				printlog("��� �ߵ����� ����?", false, false, false, CL_help);
				key_ = waitkeyinput();
				if (key_ >= 'a' && key_ <= 'g')
				{
					item_infor t;
					makeitem(ITM_MISCELLANEOUS, 0, &t, list[key_ - 'a']);
					env[current_level].MakeItem(you.position, t);
					enterlog();
				}
				else {
					printlog(" ���", true, false, false, CL_help);
				}
			}
			return;
			case 'v':
			{
				int list[] = { SPC_V_FIRE,SPC_V_ICE,SPC_V_EARTH,SPC_V_AIR,SPC_V_INVISIBLE,SPC_V_METAL, SPC_V_SUN };
				enterlog();
				printlog("a-ȭ�� b-�ñ� c-���� d-��� e-���� f-�ݼ� g-�¾�", true, false, false, CL_help);
				printlog("��� ����ī�带 ����?", false, false, false, CL_help);
				key_ = waitkeyinput();
				if (key_ >= 'a' && key_ <= 'g')
				{
					item_infor t;
					makeitem(ITM_SPELL, 0, &t, list[key_ - 'a']);
					env[current_level].MakeItem(you.position, t);
					enterlog();
				}
				else {
					printlog(" ���", true, false, false, CL_help);
				}
			}
			return;
			case 'r':
			{
				int list[] = { RGT_STR,RGT_DEX,RGT_INT,RGT_HUNGRY,RGT_FULL,RGT_TELEPORT,RGT_POISON_RESIS,
					RGT_FIRE_RESIS,	RGT_ICE_RESIS,RGT_SEE_INVISIBLE/*,RGT_GRAZE*/,RGT_LEVITATION,RGT_INVISIBLE,
					RGT_MANA,RGT_MAGACIAN,RGT_AC,RGT_EV,RGT_CONFUSE_RESIS,	RGT_ELEC_RESIS,RGT_MAGIC_RESIS };
				enterlog();
				printlog("a-�� b-��ø c-���� d-��� e-������ f-�����̵� g-������ h-ȭ������", true, false, false, CL_help);
				printlog("i-�ñ����� j-������ k-���� l-���� m-���� n-������ o-���", true, false, false, CL_help);
				printlog("p-ȸ�� q-ȥ������ r-�������� s-�������� !-��Ƽ��Ʈ", true, false, false, CL_help);
				printlog("��� ������ ����?", false, false, false, CL_help);
				key_ = waitkeyinput();
				if (key_ >= 'a' && key_ <= 's')
				{
					item_infor t;
					makeitem(ITM_RING, 0, &t, list[key_ - 'a']);
					env[current_level].MakeItem(you.position, t);
					enterlog();
				}
				else if (key_ == '!')
				{
					item_infor t;
					makeitem(ITM_RING, randA(9) ? 1 : -1, &t);
					t.artifact = true;
					item *it_ = env[current_level].MakeItem(you.position, t);
					MakeArtifact(it_, it_->curse ? -1 : 1);
					enterlog();

				}
				else {
					printlog(" ���", true, false, false, CL_help);
				}
			}
			return;
			case 'b':
			{
				item_infor t;
				makeitem(ITM_BOOK, 0, &t, -1);
				env[current_level].MakeItem(you.position, t);
			}
			return;
			case 'a':
			{
				item_infor t;
				item_type atype_ = (item_type)rand_int(ITM_ARMOR_BODY_FIRST, ITM_ARMOR_BODY_LAST - 1);
				if (randA(1) == 0)
					atype_ = (item_type)rand_int(ITM_ARMOR_HEAD, ITM_ARMOR_BOOT);
				makeitem(atype_, randA(2) ? 0 : (randA(3) ? 1 : -1), &t);
				if (randA(1))
					t.artifact = true;
				item *it_ = env[current_level].MakeItem(you.position, t);
				if (t.artifact)
					MakeArtifact(it_, it_->curse ? -1 : 1);
			}
			return;
			case 'R':
			{
				int list[] = { AMT_PERFECT, AMT_BLOSSOM, AMT_TIMES, AMT_FAITH, AMT_WAVE, AMT_SPIRIT, AMT_GRAZE,
					AMT_WEATHER, AMT_OCCULT };
				enterlog();
				printlog("a-�������� b-����� c-���� d-�ž� e-���� f-�ŷ� g-�׷����� h-����", true, false, false, CL_help);
				printlog("i-����Ʈ", true, false, false, CL_help);
				printlog("��� ������ ����?", false, false, false, CL_help);
				key_ = waitkeyinput();
				if (key_ >= 'a' && key_ <= 'i')
				{
					item_infor t;
					makeitem(ITM_AMULET, 0, &t, list[key_ - 'a']);
					env[current_level].MakeItem(you.position, t);
					enterlog();
				}
				else {
					printlog(" ���", true, false, false, CL_help);
				}
			}
			return;
			case 'f':
			{
				item_infor t;
				makeitem(ITM_THROW_TANMAC, 0, &t, -1);
				env[current_level].MakeItem(you.position, t);
			}
			return;
			default:
				printlog(" ���", true, false, false, CL_help);
				return;
			}

		}
		case 'H':
			you.HpUpDown(you.GetMaxHp(), DR_EFFECT);
			if(!you.pure_mp)
				you.MpUpDown(you.max_mp);
			you.PowUpDown(500, true);
			break;
		case 'g':
			printlog("���� ������ Ư���� �����Ǿ���. ����� ������ �帧�� �ٷ� �� �ְ� �Ǿ���.", true, false, false, CL_small_danger);
			you.SetProperty(TPT_GRAZE_CONTROL, 1);
			break;
		case 'P':
			you.system_exp.value = 0;
			if (you.system_exp.value <= 0) {
				you.system_exp.value = 0;
				item* _item = you.equipment[ET_NECK];
				if (_item && _item->type == ITM_AMULET) {
					chargingFinish((amulet_type)_item->value1, 1);
					if (you.system_exp.value <= 0) {
						if (isCanCharge((amulet_type)_item->value1)) {
							printlog("������ ���� ��� ä������! ���� ���Ҷ� v�� �ߵ��� �� �ִ�.", true, false, false, CL_white_puple);
						}
						else {
							printlog("������ ���� ��� ä������!", true, false, false, CL_white_puple);
						}
					}
				}
			}
			break;
		case 'X':
			you.GetExp(you.GetNeedExp(you.level - 1) - you.exper);
			break;
		case '>': //������ �̵�
			if (!environment::isLastFloor(current_level))
			{
				deque<monster*> dq;
				env[current_level + 1].EnterMap(0, dq);
				//you.resetLOS(false);
			}
			break;
		case '<': //������ �̵�	
			if (!environment::isFirstFloor(current_level))
			{
				deque<monster*> dq;
				env[current_level - 1].EnterMap(0, dq);
				//you.resetLOS(false);
			}
			break;
		case 'n':
		{
			item_infor t;
			makeitem(ITM_ETC, 0, &t, EIT_CAT_TREE);
			env[current_level].MakeItem(you.position, t);
		}
		return;
		case 'G': //�����̵�	
		{
			deque<monster*> dq;
			dungeon_level next_ = TEMPLE_LEVEL;
			printlog("d - ���� t - ���� l - �Ȱ��� ȣ��  m - �䱫�� ��  s - ȫ����  b - ȫ����������", true, false, false, CL_help);
			printlog("u - ȫ�������� a - �̱����׸� e - ������ y - �������� p - ���±� h - ������", true, false, false, CL_help);
			printlog("r - ���� ���� o - ���� ����  k - ����  z - �����̽Ż� ! - ������ ����", true, false, false, CL_help);
			printlog("��� �������� �̵��غ���? (�빮�ڷ� ��������)", false, false, false, CL_help);
			key_ = waitkeyinput();
			switch (key_)
			{
			case 'd':
				next_ = (dungeon_level)0;
				break;
			case 'D':
				next_ = MAX_DUNGEUN_LEVEL;
				break;
			case 't':
			case 'T':
				next_ = TEMPLE_LEVEL;
				break;
			case 'l':
				next_ = MISTY_LAKE_LEVEL;
				break;
			case 'L':
				next_ = MISTY_LAKE_LAST_LEVEL;
				break;
			case 'm':
				next_ = YOUKAI_MOUNTAIN_LEVEL;
				break;
			case 'M':
				next_ = YOUKAI_MOUNTAIN_LAST_LEVEL;
				break;
			case 's':
				next_ = SCARLET_LEVEL;
				break;
			case 'S':
				next_ = SCARLET_LEVEL_LAST_LEVEL;
				break;
			case 'b':
			case 'B':
				next_ = SCARLET_LIBRARY_LEVEL;
				break;
			case 'u':
			case 'U':
				next_ = SCARLET_UNDER_LEVEL;
				break;
			case 'a':
			case 'A':
				next_ = BAMBOO_LEVEL;
				break;
			case 'e':
			case 'E':
				next_ = EIENTEI_LEVEL;
				break;
			case 'h':
				next_ = SUBTERRANEAN_LEVEL;
				break;
			case 'H':
				next_ = SUBTERRANEAN_LEVEL_LAST_LEVEL;
				break;
			case 'y':
				next_ = YUKKURI_LEVEL;
				break;
			case 'Y':
				next_ = YUKKURI_LAST_LEVEL;
				break;
			case 'p':
				next_ = DEPTH_LEVEL;
				break;
			case 'P':
				next_ = DEPTH_LAST_LEVEL;
				break;
			case 'r':
			case 'R':
				next_ = DREAM_LEVEL;
				break;
			case 'o':
			case 'O':
				next_ = MOON_LEVEL;
				break;
			case 'k':
			case 'K':
				next_ = PANDEMONIUM_LEVEL;
				break;
			case 'z':
				next_ = HAKUREI_LEVEL;
				break;
			case 'Z':
				next_ = HAKUREI_LAST_LEVEL;
				break;
			case '!':
				next_ = ZIGURRAT_LEVEL;
				break;
			default:
				printlog(" ���", true, false, false, CL_help);
				return;
			}
			enterlog();
			env[next_].EnterMap(0, dq);
			printlog("����� �����Դ�.", true, false, false, CL_normal);
			//you.resetLOS(false);
			break;
		}
		case 'R': //�� �����	
		{
			deque<monster*> dq;
			env[current_level].ClearFloor();
			env[current_level].make = false;
			env[current_level].EnterMap(0, dq);
			break;
		}
		case 'b':
			you.Blink(40);
			break;
		case 's':
			//skill_summon_bug(10,false,&you,you.position);		
			if (you.equipment[ET_WEAPON] && !you.equipment[ET_WEAPON]->isArtifact())
			{
				you.equipment[ET_WEAPON]->value5 = WB_CURSE;
				you.equipment[ET_WEAPON]->value6 = -1;
			}
			else
			{
				printlog("������ ���� �ʴ´�.", true, false, false, CL_normal);
			}
			break;
		case 'w': //��������
		{
			int next_ = DG_TEMPLE_FIRST;
			printlog("a - �Ȱ� b - õ�չ��� c - ��û", true, false, false, CL_help);
			printlog("��� ������ �����Ұǰ�?", false, false, false, CL_help);
			wiz_list.wizard_mode = true;
			key_ = waitkeyinput();
			switch (key_)
			{
			case 'a':
			case 'A':
				you.SetWeather(1, 100);
				break;
			case 'b':
			case 'B':
				you.SetWeather(2, 100);
				break;
			case 'c':
			case 'C':
				you.SetWeather(3, 100);
				break;
			default:
				break;
			}

		}
		break;
		case 'p':
		{
			dungeon_tile_type next_ = DG_TEMPLE_FIRST;
			printlog("B - ����     K - ī����  W - ������   A - �̳븮��",true,false,false,CL_help);
			printlog("M - �̸�       P - ��Ű    G - �����   Z - ������  H - ����     Y - ��ī�� ",true,false,false,CL_help);
			printlog("E - ���̸�     U - ������  S - ���丮   T - �ٽ�    R - ������   L - ����", true, false, false, CL_help);
			printlog("I - ����       O - ��Ű��  J - ��ȣ     X - �ҿ�&�ÿ�", true, false, false, CL_help);
			printlog("� ������ �����?",false,false,false,CL_help);
			key_ = waitkeyinput();
			switch (key_)
			{
			case 'x':
			case 'X':
				next_ = DG_TEMPLE_JOON_AND_SION;
				break;
			case 'b':
			case 'B':
				next_ = DG_TEMPLE_BYAKUREN;
				break;
			case 'k':
			case 'K':
				next_ = DG_TEMPLE_KANAKO;
				break;
			case 'w':
			case 'W':
				next_ = DG_TEMPLE_SUWAKO;
				break;
			case 'a':
			case 'A':
				next_ = DG_TEMPLE_MINORIKO;
				break;
			case 'm':
			case 'M':
				next_ = DG_TEMPLE_MIMA;
				break;
			case 'p':
			case 'P':
				next_ = DG_TEMPLE_SHINKI;
				break;
			case 'g':
			case 'G':
				next_ = DG_TEMPLE_YUUGI;
				break;
			case 'z':
			case 'Z':
				next_ = DG_TEMPLE_SHIZUHA;
				break;
			case 'h':
			case 'H':
				next_ = DG_TEMPLE_HINA;
				break;
			case 'y':
			case 'Y':
				next_ = DG_TEMPLE_YUKARI;
				break;
			case 'e':
			case 'E':
				next_ = DG_TEMPLE_EIRIN;
				break;
			case 'u':
			case 'U':
				next_ = DG_TEMPLE_YUYUKO;
				break;
			case 's':
			case 'S':
				next_ = DG_TEMPLE_SATORI;
				break;
			case 't':
			case 'T':
				next_ = DG_TEMPLE_TENSI;
				break;
				case 'r':
				case 'R':
				next_ = DG_TEMPLE_SEIJA;
				break;
			case 'L':
			case 'l':
				next_ = DG_TEMPLE_LILLY;
				break;
				case 'i':
				case 'I':
					next_ = DG_TEMPLE_MIKO;
					break;
				case 'o':
				case 'O':
					next_ = DG_TEMPLE_OKINA;
					break;
				case 'j':
				case 'J':
					next_ = DG_TEMPLE_JUNKO;
					break;
			default:
				printlog(" ���", true, false, false, CL_help);
				return;
			}
			enterlog();
			env[current_level].changeTile(you.position, next_);
		}
		break;
		case 'W':
			if (you.s_the_world)
			{
				you.s_the_world = 0;
			}
			else
			{
				you.s_the_world = -1;
			}
			break;
		case 'm': 
		{
			int id_ = 0;
			char temp[100];
			sprintf_s(temp, 100, "���͸����(0~%d) :", MON_MAX - 1);
			printlog(temp, false, false, false, CL_help);


			while (true) {
				deletelog();
				sprintf_s(temp, 100, "%d (%s)", id_, mondata[id_].name.name.c_str());
				printlog(temp, false, false, true, CL_normal);

				key_ = waitkeyinput(true);
				switch (key_) {
				case 'k':
				case VK_UP:
					id_ += 10;
					break;
				case 'j':
				case VK_DOWN:
					id_ -= 10;;
					break;
				case 'h':
				case VK_LEFT:
					id_--;
					break;
				case 'l':
				case VK_RIGHT:
					id_++;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					id_ = key_ - '0' + id_*10;
					break;
				case VK_RETURN:
					if (monster* mon_ = BaseSummon(id_, 100, false, false, 2, &you, you.position, SKD_OTHER, -1))
					{
						mon_->state.SetState(MS_SLEEP);
						mon_->flag &= ~M_FLAG_SUMMON;
						mon_->ReturnEnemy();
					}
					enterlog();
					return;
				case VK_BACK:
					id_ = id_ / 10;
					break;
				case VK_ESCAPE://esc
					enterlog();
					printlog("���� ������ ���", true, false, false, CL_help);
					return;
				}
				if (id_ < 0)
					id_ = 0;
				if (id_ >= MON_MAX)
					id_ = MON_MAX - 1;

			}
		}
		break;
		case '.':
			for (int i = randA(3) + 1; i>0; i--)
			{
				BaseSummon(MON_ONBASIRA, rand_int(10, 30), true, false, 2, NULL, you.position, SKD_OTHER, -1);
			}
			printarray(true, false, false, CL_help, 1, "ī���ڴ� ��ſ��� �¹ٽö� �ȾҴ�!");
			env[current_level].MakeNoise(you.position, 16, NULL);
			break;
		case '^':
			if(you.god != GT_SEIJA)
				you.PietyUpDown(10);
			you.GiftCount(10);
			break;
		case 'o':
			you.hp = 1;
			break;
		case 'q':
		{
			D3DCOLOR color_[] = { CL_normal, CL_warning, CL_small_danger, CL_danger, CL_magic, CL_help, CL_alchemy };
			int j = 0;
			for (int i = 0; i < 27; i++) {
				char temp[100];
				printlog(itoa(need_skill_exp(i, 100), temp, 10), false, false, false, color_[j]);
				printlog(" ", false, false, false, CL_normal);
				if (i == 13)
					enterlog();
				if (i % 5 == 4)
					j++;
			}
			enterlog();
		}
			break;
		case 'C':
			{
				for(vector<monster>::iterator it = env[current_level].mon_vector.begin(); it != env[current_level].mon_vector.end(); it++)
				{
					if(it->isLive() && !(it->flag & M_FLAG_UNHARM))
						it->dead(PRT_PLAYER,false);
				}
				for(list<item>::iterator it = env[current_level].item_list.begin(); it != env[current_level].item_list.end(); it++)
				{
					it->position = you.position;
				}
			}
			break;
		case 'E':
			{
				int prevexp_=0, exp_ = 0;
				for(int i = 0; i <= map_list.dungeon_enter[MISTY_LAKE].floor; i++)
				{
					env[i].MakeMap(true);				
					for(vector<monster>::iterator it = env[i].mon_vector.begin(); it != env[i].mon_vector.end(); it++)
					{
						if(it->isLive())
							it->dead(PRT_PLAYER,false);
					}
				}
				exp_ = you.exper;
				char temp[200];
				sprintf_s(temp,200,"�Ϲݴ��� %d������ ����:%d (����ġ�� %d)",map_list.dungeon_enter[MISTY_LAKE].floor+1, you.level,exp_-prevexp_);
				printlog(temp,true,false,false,CL_normal);
				prevexp_ = exp_;
				 
				for(int i = MISTY_LAKE_LEVEL; i <= MISTY_LAKE_LAST_LEVEL; i++)
				{
					env[i].MakeMap(true);				
					for(vector<monster>::iterator it = env[i].mon_vector.begin(); it != env[i].mon_vector.end(); it++)
					{
						if(it->isLive())
							it->dead(PRT_PLAYER,false);
					}
				}
				exp_ = you.exper;
				sprintf_s(temp,200,"�Ȱ�ȣ��Ŭ���� ����:%d (����ġ�� %d)", you.level,exp_-prevexp_);
				printlog(temp,true,false,false,CL_normal);
				prevexp_ = exp_;


				for(int i = map_list.dungeon_enter[MISTY_LAKE].floor+1; i <= MAX_DUNGEUN_LEVEL; i++)
				{
					env[i].MakeMap(true);				
					for(vector<monster>::iterator it = env[i].mon_vector.begin(); it != env[i].mon_vector.end(); it++)
					{
						if(it->isLive())
							it->dead(PRT_PLAYER,false);
					}
				}
				exp_ = you.exper;
				sprintf_s(temp,200,"�������� Ŭ���� ����:%d (����ġ�� %d)", you.level,exp_-prevexp_);
				printlog(temp,true,false,false,CL_normal);
				prevexp_ = exp_;


				for(int i = YOUKAI_MOUNTAIN_LEVEL; i <= YOUKAI_MOUNTAIN_LAST_LEVEL; i++)
				{
					env[i].MakeMap(true);				
					for(vector<monster>::iterator it = env[i].mon_vector.begin(); it != env[i].mon_vector.end(); it++)
					{
						if(it->isLive())
							it->dead(PRT_PLAYER,false);
					}
				}
				exp_ = you.exper;
				sprintf_s(temp,200,"�䱫�ǻ� Ŭ���� ����:%d (����ġ�� %d)", you.level,exp_-prevexp_);
				printlog(temp,true,false,false,CL_normal);
				prevexp_ = exp_;

				for(int i = SCARLET_LEVEL; i <= SCARLET_LEVEL_LAST_LEVEL; i++)
				{
					env[i].MakeMap(true);				
					for(vector<monster>::iterator it = env[i].mon_vector.begin(); it != env[i].mon_vector.end(); it++)
					{
						if(it->isLive())
							it->dead(PRT_PLAYER,false);
					}
				}
				exp_ = you.exper;
				sprintf_s(temp,200,"ȫ���� Ŭ���� ����:%d (����ġ�� %d)", you.level,exp_-prevexp_);
				printlog(temp,true,false,false,CL_normal);
				prevexp_ = exp_;
			}
			break;
		case 'B':
			god_punish(you.god);
			break;
		case 'e':
			char temp[100];
			sprintf_s(temp, 100, "������ǥ: <%d, %d> ", you.position.x, you.position.y);
			printlog(temp, true, false, false, CL_magic);
			break;
		case '?'://����

			WaitForSingleObject(mutx, INFINITE);
			deletesub();
			printsub("                             --- ���ڵ��� Ŀ�ǵ� ��� ---",true,CL_normal);
			printsub("",true,CL_normal);
			printsub(" X      - 1������                         ",true,CL_normal);
			printsub(" H      - ü�� ���� �Ŀ� ȸ��             ",true,CL_normal);
			printsub(" G      - ����̵�                        ",true,CL_normal);
			printsub(" p      - ���� ����                       ",true,CL_normal);
			printsub(" ^      - �žӽ� 10����                   ",true,CL_normal);
			printsub(" >      - �Ʒ������� ��������             ",true,CL_normal);
			printsub(" <      - �������� �ö󰡱�               ",true,CL_normal);
			printsub(" A      - �����ۻ���(��Ÿ)                ",true,CL_normal);
			printsub(" w      - ��������                        ", true, CL_normal);
			printsub(" W      - �ð�����                        ",true,CL_normal);
			printsub(" D      - ��������                        ",true,CL_normal);
			printsub(" b      - ��ũ                          ",true,CL_normal);
			printsub(" R      - ���� �� �籸��                  ", true, CL_normal);
			printsub(" m      - ���� ����                     ", true, CL_normal);
			printsub("                                          ",true,CL_normal);
			printsub(" �̿��� Ŀ�ǵ�� �Ҿ����ϴ� ����õ        ",true,CL_normal);
			changedisplay(DT_SUB_TEXT);
			ReleaseMutex(mutx);
			continue;
		default:
			printlog("���� ��ɾ�",true,false,false,CL_help);
			break;
		}
	return;
	}
}


void save_mode()
{
	
	if(wiz_list.wizard_mode == 0)
	{

		
		printlog("#### ���! �� ���� �¶������������ �ȵ˴ϴ�! ġƮ�� ��޵˴ϴ�! ### ",true,false,false,CL_danger);
		printlog("#### ���̺�� ���̵���, ��������ÿ� ����˴ϴ�. ### ",true,false,false,CL_danger);
		printlog("��¥�� ų����? (Y/N) ",false,false,false,CL_danger);
			
		int key_ = waitkeyinput();
		switch(key_)
		{
		case 'Y':
			enterlog();
			break;
		default:
			printlog("���̺꺸����带 ���",true,false,false,CL_help);
			return;
		}


		wiz_list.wizard_mode = 2;
	}
	else if(wiz_list.wizard_mode == 1)
	{		
		printlog("���ڵ��忡�� ���̺꺸������ �̵��ϴ��� ��������� �����ʽ��ϴ�.",true,false,false,CL_danger);
		printlog("�ٲܲ���? (Y/N) ",false,false,false,CL_danger);


		int key_ = waitkeyinput();
		switch(key_)
		{
		case 'Y':
			enterlog();
			break;
		default:
			printlog("���",true,false,false,CL_help);
			return;
		}

		wiz_list.wizard_mode = 2;
	}
	else  if(wiz_list.wizard_mode == 2)
	{	
		printlog("�̹� ����� ���̺꺸������. �� ��忡�� ���̺������� ���������ʴ´�. ",true,false,false,CL_normal);
	}

	return;

}