//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: equip_action.cpp
//
// ����: player�� �ൿ��(���� ���� �ൿ��)
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "environment.h"
#include "display.h"
#include "key.h"
#include "player.h"
#include "beam.h"
#include "monster_texture.h"
#include "option_manager.h"

void Equip_Weapon()
{
	if(you.s_lunatic)
	{
		printlog("���⿡ �۽��� ���·� ���⸦ �ٲ� �� ����!",true,false,false,CL_danger);
		return;
	}
	if (you.s_evoke_ghost) {
		printlog("���� ���¿��� ���⸦ �ٲ� �� ����. ", true, false, false, CL_normal);
		return;
	}
	if (you.drowned)
	{
		printlog("���� ���� ���¿��� ���⸦ �ٲ� �� ����!", true, false, false, CL_danger);
		return;
	}

	view_item(IVT_EQ_WEAPON,"���� ���⸦ �����Ͻðڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput();
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			changedisplay(DT_GAME);
			you.equip(key_,ET_WEAPON);
			break;
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
			view_item(IVT_SELECT,"���� ���⸦ �����Ͻðڽ��ϱ�?");
		else if(key_ == '-')
		{
			if(!you.unequip(ET_WEAPON))
			{				
				printlog("���ֿ� �ɷ� �־ ��� ���� �� ����.",true,false,false,CL_normal);
			}
			break;
		}
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);

}


void weapon_swap()
{
	if (you.s_lunatic)
	{
		printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
		return;
	}
	if (you.s_evoke_ghost) {
		printlog("���� ���¿��� ��� �ٲ� �� ����. ", true, false, false, CL_normal);
		return;
	}

	item* aitem_ = you.GetItem('a');
	item* bitem_ = you.GetItem('b');
	if (aitem_ && !aitem_->isRightType(ET_WEAPON))
		aitem_ = NULL;
	if (bitem_ && !bitem_->isRightType(ET_WEAPON))
		bitem_ = NULL;
	bool equipAitem_ = false;
	//������ ���Ⱑ a�� �ƴϸ� a�� a�� b�� �ٲ�
	//a�� �Ǽ��� ���� ��¼��?

	if (you.equipment[ET_WEAPON])
	{
		if(you.equipment[ET_WEAPON]->id == 'a')
			equipAitem_ = false;
		else
		{
			equipAitem_ = true;
			you.already_swap = true;
		}

	}
	else {
		if (you.already_swap)
		{
			equipAitem_ = false;
		}
		else
		{
			equipAitem_ = true;
			you.already_swap = true;
		}

	}

	if(equipAitem_)
	{
		if (aitem_)
			you.equip('a', ET_WEAPON);
		else if (you.equipment[ET_WEAPON])
			you.unequip(ET_WEAPON);
	}
	else
	{
		if (bitem_)
			you.equip('b', ET_WEAPON);
		else if (you.equipment[ET_WEAPON])
			you.unequip(ET_WEAPON);
	}
	you.SetPrevAction('\'');
}
void Equip_Armor()
{
	if(you.s_lunatic)
	{
		printlog("���⿡ �۽��� ���·� ���� �ٲ� �� ����!",true,false,false,CL_danger);
		return;
	}
	if (you.s_evoke_ghost) {
		printlog("���� ���¿��� ���� �ٲ� �� ����. ", true, false, false, CL_normal);
		return;
	}
	if (you.drowned)
	{
		printlog("���� ���� ���¿��� ���� �ٲ� �� ����!", true, false, false, CL_danger);
		return;
	}
	view_item(IVT_EQ_ARMOR,"���� ���� �����ϰڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput();
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			changedisplay(DT_GAME);
			you.equiparmor(key_);
			break;
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
			view_item(IVT_SELECT,"���� ���� �����ϰڽ��ϱ�?");
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}


void Unequip_Armor()
{	
	if(you.s_lunatic)
	{
		printlog("���⿡ �۽��� ���·� ���� ���� �� ����!",true,false,false,CL_danger);
		return;
	}
	if (you.s_evoke_ghost) {
		printlog("���� ���¿��� ���� ���� �� ����. ", true, false, false, CL_normal);
		return;
	}
	view_item(IVT_UEQ_ARMOR,"���� ���� ���ڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput();
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			
			changedisplay(DT_GAME);
			you.unequiparmor(key_);
			break;
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
			view_item(IVT_SELECT,"���� ���� ���ڽ��ϱ�?");
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}



void Equip_Jewelry()
{	
	if(you.s_lunatic)
	{
		printlog("���⿡ �۽��� ���·� ��ű��� �� �� ����!",true,false,false,CL_danger);
		return;
	}
	if (you.s_evoke_ghost) {
		printlog("���� ���¿��� ��ű��� �� �� ����. ", true, false, false, CL_normal);
		return;
	}
	view_item(IVT_EQ_JEWELRY,"���� ��ű��� �����ϰڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput();
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			changedisplay(DT_GAME);
			you.equipjewerly(key_);
			break;
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
			view_item(IVT_SELECT,"���� ��ű��� �����ϰڽ��ϱ�?");
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}


void Unequip_Jewelry()
{	
	if(you.s_lunatic)
	{
		printlog("���⿡ �۽��� ���·� ��ű��� ���� �� ����!",true,false,false,CL_danger);
		return;
	}
	if (you.s_evoke_ghost) {
		printlog("���� ���¿��� ��ű��� ���� �� ����. ", true, false, false, CL_normal);
		return;
	}
	view_item(IVT_UEQ_JEWELRY,"���� ��ű��� ���ڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput();
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			changedisplay(DT_GAME);
			you.unequipjewerly(key_);
			break;
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
			view_item(IVT_SELECT,"���� ��ű��� ���ڽ��ϱ�?");
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}




