//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: scroll.cpp
//
// ����: �η縶��
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "key.h"
#include "smoke.h"
#include "monster_texture.h"
#include "throw.h"
#include "spellcard.h"
#include "environment.h"
#include "skill_use.h"
#include "rand_shuffle.h"
#include "option_manager.h"
#include "soundmanager.h"
#include "weapon.h"
#include <algorithm>
extern HANDLE mutx;

char *scroll_uniden_string[SCT_MAX]=
{
	"ASASVQE�� ���ִ� ",
	"EFIIEQN�� ���ִ� ",
	"QEWFQFF�� ���ִ� ",
	"DIQHQNA�� ���ִ� ",
	"IVNUXTO�� ���ִ� ",
	"MDIMIKU�� ���ִ� ",
	"AFIQHQW�� ���ִ� ",
	"POIUGAW�� ���ִ� ",
	"MVDOQUR�� ���ִ� ",
	"TFJEOTT�� ���ִ� ",
	"XNEPBIQ�� ���ִ� ",
	"JUYBLNM�� ���ִ� ",
	"UNQIFNV�� ���ִ� ",
	"LVIWBAA�� ���ִ� ",
	"RWMVXCO�� ���ִ� ",
	"OFQXLFE�� ���ִ� ",
	"DQFQEFS�� ���ִ� ",
	"BAHJDQU�� ���ִ� ",
	"WQGOKOU�� ���ִ� ",
	"EIQJIWE�� ���ִ� "
};

const char *scroll_iden_string[SCT_MAX]=
{	
	"�����̵��� ",
	"�ĺ��� ",
	"���� ",
	"���������� ",
	"�������� ",
	"���������� ",
	"�����̵��� ",
	"����Ž���� ",
	"���Ⱝȭ�� ",
	"���Ⱝȭ�� ",
	"����ȭ�� ",
	"�Ȱ��� ",
	"����Ž���� ",
	"��ű������� ",
	"������ ",
	"���� ",
	"����ī�������� ",
	"������ ",
	"������ ",
	"���������� "
};



bool identity_scroll(bool pre_iden_); 
void random_identity_scroll();
bool curse_weapon_scroll(bool pre_iden_);
bool curse_armour_scroll(bool pre_iden_);
bool remove_curse_scroll(bool pre_iden_);
bool blink_scroll(bool pre_iden_);
bool enchant_weapon_1_scroll(bool pre_iden_);
bool enchant_weapon_2_scroll(bool pre_iden_);
bool enchant_armour_scroll(bool pre_iden_, bool waste_);
bool fog_scroll(bool pre_iden_);
bool detect_curse_scroll(bool pre_iden_);
bool curse_jewelry_scroll(bool pre_iden_); 
bool skill_silence(int pow, bool short_, unit* order, coord_def target);
bool skill_soul_shot(int power, unit* order, coord_def target);
bool skill_santuary(int pow, bool short_, unit* order, coord_def target);
bool recharging_scroll(bool pre_iden_, bool ablity_, bool waste_);
bool amnesia_scroll(bool pre_iden_);
bool brand_weapon_scroll(bool pre_iden_);




scroll_type goodbadscroll(int good_bad)
{
	if(good_bad==2)
	{
		scroll_type list_[7] = {SCT_BLINK, SCT_ENCHANT_WEAPON_1/*SCT_ENCHANT_WEAPON_2*/, SCT_ENCHANT_ARMOUR, SCT_FOG,
			SCT_CHARGING, SCT_MAPPING,SCT_AMNESIA};
		return list_[randA(6)];
	}
	else if(good_bad==3)
	{
		scroll_type list_[4] = {SCT_SILENCE,SCT_SOUL_SHOT,SCT_SANTUARY, SCT_BRAND_WEAPON};
		return list_[randA(3)];
	}
	else //if(good_bad==1)
	{
		scroll_type list_[3] = {SCT_TELEPORT, SCT_IDENTIFY, SCT_REMOVE_CURSE/*SCT_DETECT_CURSE*/};
		return list_[randA(2)];
	}/*
	else
	{
		scroll_type list_[4] = {SCT_NONE, SCT_CURSE_WEAPON, SCT_CURSE_ARMOUR, SCT_CURSE_JEWELRY};
		return list_[randA(3)];
	}*/


}
int isGoodScroll(scroll_type kind)
{	
	switch(kind)
	{
	case SCT_SOUL_SHOT:
	case SCT_SANTUARY:
		return 3;
	case SCT_TELEPORT:
	case SCT_IDENTIFY:
	case SCT_REMOVE_CURSE:
	case SCT_BLINK:
		return 2;
	case SCT_ENCHANT_WEAPON_1:
	case SCT_ENCHANT_WEAPON_2:
	case SCT_ENCHANT_ARMOUR:
	case SCT_FOG:
	case SCT_MAPPING:
	case SCT_DETECT_CURSE:
	case SCT_SILENCE:
	case SCT_CHARGING:
	case SCT_AMNESIA:
	case SCT_BRAND_WEAPON:
		return 1;
	case SCT_NONE:
		return 0;
	case SCT_CURSE_WEAPON:		
	case SCT_CURSE_ARMOUR:
	case SCT_CURSE_JEWELRY:
		return -1;
	}
	return 1;
}




bool readscroll(scroll_type kind, bool pre_iden_, bool waste_)
{
	if (you.s_pure_turn && you.s_pure >= 10)
	{
		if (kind != SCT_ENCHANT_WEAPON_1 &&
			kind != SCT_ENCHANT_WEAPON_2 &&
			kind != SCT_ENCHANT_ARMOUR &&
			kind != SCT_IDENTIFY &&
			kind != SCT_BRAND_WEAPON &&
			kind != SCT_REMOVE_CURSE &&
			kind != SCT_AMNESIA)
		{
			printlog("����� �η縶���� ȿ���� ����ϱ⿣ �ʹ� ��ȭ�Ǿ��ִ�.", true, false, false, CL_normal);
			iden_list.scroll_list[kind].iden = 3;
			return !pre_iden_;
		}
	}


	switch(kind)
	{
	case SCT_TELEPORT:		
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		iden_list.scroll_list[kind].iden = 3;
		ReleaseMutex(mutx);
		if(!you.Tele_check(pre_iden_, false))
			return false;
		WaitForSingleObject(mutx, INFINITE);
		bool return_ = you.SetTele(rand_int(3,6));
		return return_;
		}
	case SCT_IDENTIFY:
		{
		ReleaseMutex(mutx);
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = true;
		if(waste_)
			random_identity_scroll();
		else
			return_ = identity_scroll(pre_iden_);
		WaitForSingleObject(mutx, INFINITE);
		return return_;
		}
	case SCT_NONE:
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		printlog("�� �η縶���� ���ִ� ���� ��������.",true,false,false,CL_normal);
		iden_list.scroll_list[kind].iden = 3;
		return true;
		}
	case SCT_CURSE_WEAPON:		
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = curse_weapon_scroll(pre_iden_);
		return return_;
		}
	case SCT_CURSE_ARMOUR:	
		{
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = curse_armour_scroll(pre_iden_);
		return return_;
		}
	case SCT_REMOVE_CURSE:
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = remove_curse_scroll(pre_iden_);
		return return_;
		}
	case SCT_BLINK:
		{
		ReleaseMutex(mutx);
		bool return_ = blink_scroll(waste_ ? false : pre_iden_);
		if (return_) {
			soundmanager.playSound("blink");
		}
		iden_list.scroll_list[kind].iden = 3;
		WaitForSingleObject(mutx, INFINITE);
		return return_;
		}
	case SCT_MAPPING:
		 {
			if (waste_) //����ÿ� �ǹ̰� ����
				return true;
			iden_list.scroll_list[kind].iden = 3;
			if(env[current_level].isBamboo())
			{				
				printlog("����Ž���� �̱��� �׸����� ȿ���� ���� ���Ѵ�.",true,false,false,CL_normal);
				if(pre_iden_){
					return false;
				}
				else{
					return true;
				}
			}
			else
			{
				env[current_level].MakeMapping(100);	
				printlog("����� ���� ���� �����س´�.",true,false,false,CL_normal);
			}
			return true;
		 }
	case SCT_ENCHANT_WEAPON_1:
		{
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = enchant_weapon_1_scroll(pre_iden_);
		return return_;
		}
	case SCT_ENCHANT_WEAPON_2:
		{
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = enchant_weapon_2_scroll(pre_iden_);
		return return_;
		}
	case SCT_ENCHANT_ARMOUR:
		{
		ReleaseMutex(mutx);
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = enchant_armour_scroll(pre_iden_, waste_);
		WaitForSingleObject(mutx, INFINITE);
		return return_;
		}
	case SCT_FOG:
		{
		bool return_ = fog_scroll(pre_iden_);
		iden_list.scroll_list[kind].iden = 3;
		return return_;
		}
	case SCT_DETECT_CURSE:
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		bool return_ = detect_curse_scroll(pre_iden_);
		iden_list.scroll_list[kind].iden = 3;
		return return_;
		}
	case SCT_CURSE_JEWELRY:
		{
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = curse_jewelry_scroll(pre_iden_);
		return return_;
		}
	case SCT_SILENCE:
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		skill_silence(75, false, &you, you.position);
		iden_list.scroll_list[kind].iden = 3;
		return true;
		}
	case SCT_SOUL_SHOT://�߰�
		{
		iden_list.scroll_list[kind].iden = 3;
		if(you.power >= 100)
		{
			ReleaseMutex(mutx);
			changedisplay(DT_GAME);
			you.PowUpDown(-100,true);
			printlog("��! ",false,false,false,CL_white_blue);
			soundmanager.playSound("soul_shot");
			skill_soul_shot(0, &you, you.position);
			WaitForSingleObject(mutx, INFINITE);
		}
		else
		{
			if (!waste_) //����ÿ� �ǹ̰� ����
				printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
		}
		return true;
		}
	case SCT_SANTUARY:
	{
		//if (waste_) //����ÿ� �ǹ̰� ����
		//	return true;
		iden_list.scroll_list[kind].iden = 3;
		if (you.power >= 100)
		{
			ReleaseMutex(mutx);
			changedisplay(DT_GAME);
			you.PowUpDown(-100, true);
			skill_santuary(75, false, &you, you.position);
			WaitForSingleObject(mutx, INFINITE);
		}
		else
		{
			printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.", true, false, false, CL_normal);
		}
		return true;
	}
	case SCT_CHARGING:
		{
		ReleaseMutex(mutx);
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = recharging_scroll(pre_iden_, false, waste_);
		WaitForSingleObject(mutx, INFINITE);
		return return_;
		}
	case SCT_AMNESIA:
		{
		if (waste_) //����ÿ� �ǹ̰� ����
			return true;
		ReleaseMutex(mutx);
		iden_list.scroll_list[kind].iden = 3;
		bool return_ = amnesia_scroll(pre_iden_);
		WaitForSingleObject(mutx, INFINITE);
		return return_;
		}
	case SCT_BRAND_WEAPON:
		{
			iden_list.scroll_list[kind].iden = 3;
			bool return_ = brand_weapon_scroll(pre_iden_);
			return return_;
		}
	}
	return true;
}


void random_identity_scroll()
{
	//�������� ���ַ� ��ũ�� �ڵ� �ĺ�
	random_extraction<item *> rand_;

	list<item>::iterator it;
	for (it = you.item_list.begin(); it != you.item_list.end(); it++)
	{
		if (!it->isiden())
			rand_.push(&(*it));
	}
	if (rand_.GetSize() > 0) {
		item* rand_item = rand_.pop();
		if (rand_item != NULL)
		{
			rand_item->Identify();
			char temp[2];
			sprintf_s(temp,2, "%c", rand_item->id);
			printlog(temp, false, false, false, rand_item->item_color());
			printlog(" - ", false, false, false, rand_item->item_color());
			printlog(rand_item->GetName(), true, false, false, rand_item->item_color());
		}
	}
}

bool identity_scroll(bool pre_iden_)
{
	if(iden_list.scroll_list[SCT_IDENTIFY].iden == 3)
		view_item(IVT_UNIDEN,"���� �������� �ĺ��ðڽ��ϱ�?");
	else
		view_item(IVT_SELECT,"���� �����ۿ� ����Ͻðڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			item *item_ = you.GetItem(key_);
			if(item_)
			{
				if(!item_->isiden())
				{
					item_->Identify();
					char temp[2];
					sprintf_s(temp,2,"%c",item_->id);
					printlog(temp,false,false,false,item_->item_color());
					printlog(" - ",false,false,false,item_->item_color());
					printlog(item_->GetName(),true,false,false,item_->item_color());
					return true;
				}
			}
		}
		else if(key_ == VK_DOWN)//-----�̵�Ű-------
		{
			changemove(32);  //��
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //�Ʒ�
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-option_mg.getHeight());
		}
		else if(key_ == VK_NEXT)
		{
			changemove(option_mg.getHeight());
		}						//-----�̵�Ű��-------
		else if(key_ == '*')
		{	
			if(iden_list.scroll_list[SCT_IDENTIFY].iden == 3)
				view_item(IVT_SELECT,"���� �������� �ĺ��ðڽ��ϱ�?");
			else
				view_item(IVT_SELECT,"���� �����ۿ� ����Ͻðڽ��ϱ�?");
		}
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
	if(pre_iden_){
		return false;
	}
	else{
		return true;
	}
}


bool curse_weapon_scroll(bool pre_iden_)
{
	if(you.equipment[ET_WEAPON])
	{
		string before_name = you.equipment[ET_WEAPON]->GetName(); //���ֹޱ��� �̸�
		if(you.equipment[ET_WEAPON]->Curse(true,ET_WEAPON))
		{
			printlog("�����ϰ� �ִ� ",false,false,false,CL_small_danger);	
			printlog(before_name,false,false,false,CL_small_danger);	
			printlog(you.equipment[ET_WEAPON]->GetNameInfor().name_do(true),false,false,false,CL_small_danger);
			printlog("�˰� ������.",true,false,false,CL_small_danger);		
			return true;
		}
		else
		{
			if(pre_iden_){
				printlog("�� �������� ���ָ� �� �� �� ����.",true,false,false,CL_normal);
				return false;
			}
			else{
				printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
				return true;
			}
		}
	}
	else
	{
		if(pre_iden_){
			printlog("���⸦ ���� ���� �ʴ�.",true,false,false,CL_normal);
			return false;
		}
		else{
			printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
			return true;
		}
	}
}
bool curse_armour_scroll(bool pre_iden_)
{	
	deque<int> dq;
	for(int i=ET_ARMOR;i<ET_ARMOR_END;i++)
		dq.push_back(i);
	rand_shuffle(dq.begin(),dq.end());

	for(int i = 0; i<dq.size() ; i++)
	{
		if(you.equipment[dq[i]])
		{
			string before_name = you.equipment[dq[i]]->GetName(); //���ֹޱ��� �̸�
			if(you.equipment[dq[i]]->Curse(true,(equip_type)dq[i]))
			{
				printlog("�����ϰ� �ִ� ",false,false,false,CL_small_danger);		
				printlog(before_name,false,false,false,CL_small_danger);	
				printlog(you.equipment[dq[i]]->GetNameInfor().name_do(true),false,false,false,CL_small_danger);
				printlog("�˰� ������.",true,false,false,CL_small_danger);		
				return true;
			}
		}
	}
	if(pre_iden_){
		printlog("���ְ� �� �ִ� ���� ���� ���� �ʴ�.",true,false,false,CL_normal);
		return false;
	}
	else{
		printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
		return true;
	}
}

bool remove_curse_scroll(bool pre_iden_)
{

	bool iden_ = false;
	for(int i = ET_FIRST; i<ET_LAST ; i++)
	{
		if(you.equipment[i])
		{
			if(you.equipment[i]->isRightType((equip_type)i))
			{	
				if(you.equipment[i]->curse)
				{		
					if(iden_==false && you.GetPunish(GT_HINA) && randA(2))
					{
						printlog("������ ����� �׶��� �����ߴ�! ",false,false,false,CL_hina);						
						printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
						return true;
					}
					you.equipment[i]->curse = false;
					you.equipment[i]->identify_curse = true;
					iden_ = true;
				}

			}
		}
	}
	if(iden_)
	{
		printlog("�������ִ� ����� ���ְ� Ǯ�ȴ�.",true,false,false,CL_normal);
		return true;
	}
	else
	{
		if(pre_iden_){
			printlog("���ְ� �ɸ� ��� ����.",true,false,false,CL_normal);
			return false;
		}
		else{
			printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
			return true;
		}
	}
}


bool blink_scroll(bool pre_iden_)
{
	changedisplay(DT_GAME);
	if (current_level == ZIGURRAT_LEVEL ) {
		if (pre_iden_) {
			printlog("������ ���迡�� �����̵��� ��� �Ұ����ϴ�. ������ ���ž�? (y/n)", true, true, false, CL_small_danger);

			switch (waitkeyinput())
			{
			case 'Y':
			case 'y':
				break;
			case 'N':
			case 'n':
			case VK_ESCAPE:
				printlog("����Ͽ���.", true, true, false, CL_normal);
				return false;
			}
		}
		you.Blink(25);
		return true;
	}


	you.search_pos = you.position;
	you.search = true;
	bool is_move = false;
	Search_Move(coord_def(you.position.x,you.position.y), false,VT_BLINK);
	while(1)
	{
		switch(waitkeyinput())
		{
		case 'k':
			is_move = Search_Move(coord_def(you.position.x,you.position.y-1), false,VT_BLINK);  //��
			break;
		case 'j':
			is_move = Search_Move(coord_def(you.position.x,you.position.y+1), false,VT_BLINK); //�Ʒ�
			break;
		case 'h':
			is_move = Search_Move(coord_def(you.position.x-1,you.position.y), false,VT_BLINK); //����
			break;
		case 'l':
			is_move = Search_Move(coord_def(you.position.x+1,you.position.y), false,VT_BLINK); //������
			break;
		case 'b':
			is_move = Search_Move(coord_def(you.position.x-1,you.position.y+1), false,VT_BLINK);
			break;
		case 'n':
			is_move = Search_Move(coord_def(you.position.x+1,you.position.y+1), false,VT_BLINK);
			break;
		case 'y':
			is_move = Search_Move(coord_def(you.position.x-1,you.position.y-1), false,VT_BLINK);
			break;
		case 'u':
			is_move = Search_Move(coord_def(you.position.x+1,you.position.y-1), false,VT_BLINK);
			break;
		case VK_RETURN:
			if(is_move)
			{				
				if(!you.Tele_check(pre_iden_, true))
				{
					deletelog();
					you.search = false;
					return false;
				}
				if(you.control_blink(you.search_pos))
				{
					you.search = false;
					deletelog();
					return true;
				}
			}
			break;
		case VK_ESCAPE:	
			if(pre_iden_){
				printlog("������ �����̵��� ����Ͻðڽ��ϱ�? (y/n)",true,true,false,CL_help);
			}
			else{
				printlog("������ �����̵��� ����Ͻðڽ��ϱ�? ��ũ���� ������ϴ�! (y/n)",true,true,false,CL_help);
			}
			bool repeat_ = true;
			while(repeat_)
			{
				switch(waitkeyinput())
				{
				case 'Y':
				case 'y':
					deletelog();
					you.search = false;
					if(pre_iden_){
						return false;
					}
					else{
						return true;
					}
				case 'N':
				case 'n':
					repeat_ = false;
				}
			}
		}
	}

}


bool enchant_weapon_1_scroll(bool pre_iden_)
{
	if(you.equipment[ET_WEAPON])
	{
		string before_name = you.equipment[ET_WEAPON]->GetName();
		if(you.equipment[ET_WEAPON]->Enchant(ET_WEAPON, 1))
		{
			printlog("�����ϰ� �ִ� ",false,false,false,CL_good);	
			printlog(before_name,false,false,false,CL_good);	
			printlog(you.equipment[ET_WEAPON]->GetNameInfor().name_do(true),false,false,false,CL_good);
			printlog("���������� ������.",true,false,false,CL_good);
			you.equipment[ET_WEAPON]->curse = false;
			you.equipment[ET_WEAPON]->identify_curse = true;
			return true;
		}
		else
		{
			if(pre_iden_){
				printlog("�� �̻� ��ȭ �� �� ���� �����.",true,false,false,CL_normal);
				return false;
			}
			else{
				printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
				return true;
			}
		}
	}
	else
	{
		if(pre_iden_){
			printlog("����� ���Ⱑ ����.",true,false,false,CL_normal);
			return false;
		}
		else{
			printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
			return true;
		}
	}
}

bool enchant_weapon_2_scroll(bool pre_iden_)
{
	if(you.equipment[ET_WEAPON])
	{
		string before_name = you.equipment[ET_WEAPON]->GetName();
		if(you.equipment[ET_WEAPON]->Enchant(ET_WEAPON, 1))
		{
			printlog("�����ϰ� �ִ� ",false,false,false,CL_good);	
			printlog(before_name,false,false,false,CL_good);	
			printlog(you.equipment[ET_WEAPON]->GetNameInfor().name_do(true),false,false,false,CL_good);
			printlog("���������� ������.",true,false,false,CL_good);
			you.equipment[ET_WEAPON]->curse = false;
			you.equipment[ET_WEAPON]->identify_curse = true;
			return true;
		}
		else
		{
			if(pre_iden_){
				printlog("�� �̻� ��ȭ �� �� ���� �����.",true,false,false,CL_normal);
				return false;
			}
			else{
				printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
				return true;
			}
		}
	}
	else
	{
		if(pre_iden_){
			printlog("����� ���Ⱑ ����.",true,false,false,CL_normal);
			return false;
		}
		else{
			printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
			return true;
		}
	}
}



bool enchant_armour_scroll(bool pre_iden_, bool waste_)
{
	static int prev_key = 0;

	if (!waste_) {
		if (iden_list.scroll_list[SCT_ENCHANT_ARMOUR].iden == 3)
			view_item(IVT_ARMOR_ENCHANT, "���� ���� ��ȭ�Ͻðڽ��ϱ�?");
		else
			view_item(IVT_SELECT, "���� �����ۿ� ����Ͻðڽ��ϱ�?");
	}
	while(1)
	{
		int key_ = 0;

		if (!waste_) {
			key_ = waitkeyinput(true);
		}
		else if (prev_key != 0) {
			key_ = prev_key;
		}
		else
			return false;
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			prev_key = key_;
			item *item_ = you.GetItem(key_);
			if(item_)
			{
				string before_name = item_->GetName();
				if(item_->Enchant(ET_ARMOR, 1))
				{
					printlog(before_name,false,false,false,CL_good);	
					printlog(item_->GetNameInfor().name_do(true),false,false,false,CL_good);
					printlog("�ʷϻ����� ������.",true,false,false,CL_good);
					item_->curse = false;
					item_->identify_curse = true;
					return true;
				}
				else
				{
					if (!waste_) {
						changedisplay(DT_GAME);
					}
					if(pre_iden_){
						printlog("�� �������� ��ȭ�� �� ����.",true,false,false,CL_normal);
						return false;
					}
					else{
						printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
						return true;
					}
				}

			}
		}
		else if (waste_) {
			return false;
		}
		else if(key_ == VK_DOWN)//-----�̵�Ű-------
		{
			changemove(32);  //��
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //�Ʒ�
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-option_mg.getHeight());
		}
		else if(key_ == VK_NEXT)
		{
			changemove(option_mg.getHeight());
		}						//-----�̵�Ű��-------
		else if(key_ == '*')
		{	
			if(iden_list.scroll_list[SCT_ENCHANT_ARMOUR].iden == 3)
				view_item(IVT_SELECT,"���� ���� ��ȭ�Ͻðڽ��ϱ�?");
			else
				view_item(IVT_SELECT,"���� �����ۿ� ����Ͻðڽ��ϱ�?");
		}
		else if(key_ == VK_ESCAPE)
			break;
	}
	if (!waste_) {
		changedisplay(DT_GAME);
	}
	if(pre_iden_){
		return false;
	}
	else{
		return true;
	}
}


bool fog_scroll(bool pre_iden_)
{
	MakeCloud(you.position, img_fog_normal, SMT_FOG, rand_int(10,15), rand_int(8,12), 0,5, &you);
	return true;
}

bool detect_curse_scroll(bool pre_iden_)
{
	for(list<item>::iterator it = you.item_list.begin(); it != you.item_list.end() ; it++)
	{
		it->identify_curse = true;
	}
	printlog("�κ��丮�� ���ָ� Ž���ߴ�.",true,true,false,CL_normal);
	return true;
}
bool curse_jewelry_scroll(bool pre_iden_)
{
	deque<int> dq;
	for(int i=ET_JEWELRY;i<ET_JEWELRY_END;i++)
		dq.push_back(i);
	rand_shuffle(dq.begin(),dq.end());

	for(int i = 0; i<dq.size() ; i++)
	{
		if(you.equipment[dq[i]])
		{
			string before_name = you.equipment[dq[i]]->GetName(); //���ֹޱ��� �̸�
			if(you.equipment[dq[i]]->Curse(true,(equip_type)dq[i]))
			{
				printlog("�����ϰ� �ִ� ",false,false,false,CL_small_danger);		
				printlog(before_name,false,false,false,CL_small_danger);	
				printlog(you.equipment[dq[i]]->GetNameInfor().name_do(true),false,false,false,CL_small_danger);
				printlog("�˰� ������.",true,false,false,CL_small_danger);		
				return true;
			}
		}
	}
	if(pre_iden_){
		printlog("���ְ� �� �ִ� ��ű��� ����.",true,false,false,CL_normal);
		return false;
	}
	else{
		printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�.",true,false,false,CL_normal);
		return true;
	}
}
bool recharging_scroll(bool pre_iden_, bool ablity_, bool waste_)
{
	static int prev_key = 0;



	if (!waste_) {
		bool ok_ = false;
		for(auto it = you.item_list.begin();it != you.item_list.end(); it++)
		{
			if((*it).isSimpleType(ITMS_SPELL) && (*it).isChargable())
			{
				ok_ = true;
				break;
			}
		}
		if(!ok_)
		{
			printlog("����� ����ǰ�� ������ �� �ִ� ����ī�尡 ����.",true,false,false,CL_normal);
			if(pre_iden_)
				return false;
			else
				return true;
		}
		if (iden_list.scroll_list[SCT_CHARGING].iden == 3 || ablity_)
			view_item(IVT_SPELLCARD, "���� ����ī�带 �����Ͻðڽ��ϱ�?");
		else
			view_item(IVT_SELECT, "���� �����ۿ� ����Ͻðڽ��ϱ�?");
	}
	while(1)
	{
		int key_ = 0;

		if (!waste_) {
			key_ = waitkeyinput(true);
		}
		else if (prev_key != 0) {
			key_ = prev_key;
		}
		else
			return false;
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			prev_key = key_;
			item *item_ = you.GetItem(key_);
			if(item_)
			{
				if(item_->isChargable())
				{
					int charging_= SpellcardMaxCharge((spellcard_evoke_type)item_->value2) * rand_float(0.3f,0.7f);

					printlog(item_->GetName(),false,false,false,CL_good);	
					printlog(item_->GetNameInfor().name_do(true),false,false,false,CL_good);
					printlog("�����Ǿ���.",true,false,false,CL_good);

					item_->value1 += charging_;
					if(item_->value1>SpellcardMaxCharge((spellcard_evoke_type)item_->value2))
						item_->value1 = SpellcardMaxCharge((spellcard_evoke_type)item_->value2);
					item_->value3 = -2; 					

					return true;
				}
				else if (waste_) {
					return true;
				}
			}
		}
		else if (waste_) {
			return false;
		}
		else if(key_ == VK_DOWN)//-----�̵�Ű-------
		{
			changemove(32);  //��
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //�Ʒ�
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-option_mg.getHeight());
		}
		else if(key_ == VK_NEXT)
		{
			changemove(option_mg.getHeight());
		}						//-----�̵�Ű��-------
		else if(key_ == '*')
		{	
			if(iden_list.scroll_list[SCT_CHARGING].iden == 3 || ablity_)
				view_item(IVT_SPELLCARD,"���� ����ī�带 �����Ͻðڽ��ϱ�?");
			else
				view_item(IVT_SELECT,"���� �����ۿ� ����Ͻðڽ��ϱ�?");
		}
		else if(key_ == VK_ESCAPE)
		{
			break;
		}
	}
	if (!waste_) {
		changedisplay(DT_GAME);
	}
	if(pre_iden_){
		return false;
	}
	else{
		return true;
	}
}
bool amnesia_scroll(bool pre_iden_)
{
	

	if(you.currentSpellNum)
	{
		int i=0;
		view_spell("���� ������ �����ϼ���. ( ?Ű�� ������ �� �� �ִ�. )");
		//changedisplay(DT_SPELL);
		while(1)
		{
			int key_ = waitkeyinput(true);
			if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
			{
				int num = (key_ >= 'a' && key_ <= 'z')?(key_-'a'):(key_-'A'+26);
				if(spell_list spell_ = (spell_list)you.MemorizeSpell[num])
				{				
					
					changedisplay(DT_GAME);
					printarray(true,false,false,CL_help,2,SpellString(spell_)," ������ �ذڽ��ϱ�? (Y/N)");
					switch(waitkeyinput())
					{
					case 'Y':
					case 'y':
						{
							changedisplay(DT_GAME);
							WaitForSingleObject(mutx, INFINITE);
							you.MemorizeSpell[num] = 0;
							you.remainSpellPoiont+=SpellLevel(spell_);
							you.currentSpellNum--;
							ReleaseMutex(mutx);
							printarray(true,false,false,CL_normal,3,"����� ",SpellString(spell_)," ������ �ؾ���.");	
							return true;
						}
					case 'N':
					default:
						view_spell("���� ������ �����ϼ���.  ( ?Ű�� ������ �� �� �ִ�. )");
						//changedisplay(DT_SPELL);
						break;
					}
				}
			}
			else if(key_ == VK_ESCAPE)
				break;
		}
		changedisplay(DT_GAME);
	}
	else
	{
		printlog("���� �˰��ִ� ������ ����.",true,false,false,CL_normal);	
	}

	if(pre_iden_){
		return false;
	}
	else{
		return true;
	}
}


bool brand_weapon_scroll(bool pre_iden_)
{
	if (you.equipment[ET_WEAPON])
	{
		string before_name = you.equipment[ET_WEAPON]->GetName();
		if (you.equipment[ET_WEAPON] && (you.equipment[ET_WEAPON]->type >= ITM_WEAPON_FIRST && you.equipment[ET_WEAPON]->type<ITM_WEAPON_LAST) && !you.equipment[ET_WEAPON]->isArtifact())
		{
			random_extraction<int> random;
			random.push(WB_FIRE, 30);
			random.push(WB_COLD, 30);
			random.push(WB_POISON, 30);
			random.push(WB_MANA_REGEN, 10);
			random.push(WB_FAST_CAST, 10);
			random.push(WB_PROTECT, 20);
			int brand_ = random.pop();
			string weapon_string;

			switch (brand_)
			{
			case WB_FIRE:
				weapon_string = "�ұ濡 �۽ο���!";
				break;
			case WB_COLD:
				weapon_string = "�ѱ⸦ ���վ���!";
				break;
			case WB_POISON:
				weapon_string = "�͵��� �վ�´�!";
				break;
			case WB_MANA_REGEN:
				weapon_string = "������ ���հ��ִ�!";
				break;
			case WB_FAST_CAST:
				weapon_string = "�ź�ο� ���� �վ�� �ִ�!";
				break;
			case WB_PROTECT:
				weapon_string = "��ȣ�� ������ ���հ��ִ�!";
				break;
			}

			printarray(true, false, false, CL_magic, 3, you.equipment[ET_WEAPON]->GetName().c_str(), you.equipment[ET_WEAPON]->GetNameInfor().name_do(true), weapon_string.c_str());
			you.equipment[ET_WEAPON]->value5 = brand_;
			you.equipment[ET_WEAPON]->value6 = -1;
			printlog("����� ���⿡ ������ �ο��Ǿ���! ", false, false, false, CL_normal);
			return true;
		}
		else
		{
			if (pre_iden_) {
				printlog("�� ���⿣ ������ �ο��� �� ����. ", false, false, false, CL_normal);
				return false;
			}
			else {
				printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�. ", false, false, false, CL_normal);
				return true;
			}
		}
	}
	else
	{
		if (pre_iden_) {
			printlog("����� ���Ⱑ ����. ", false, false, false, CL_normal);
			return false;
		}
		else {
			printlog("�ƹ� �ϵ� �Ͼ���ʾҴ�. ", false, false, false, CL_normal);
			return true;
		}
	}
}