//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: iteminfor.cpp
//
// ����: �������� ��������
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "environment.h"
#include "display.h"
#include "key.h"
#include "player.h"
#include "beam.h"
#include "monster_texture.h"
#include "skill_use.h"
#include "weapon.h"
#include "armour.h"
#include "evoke.h"
#include "book.h"
#include "option_manager.h"
#include "tribe.h"
#include "dump.h"
#include "god.h"
#include <set>

extern HANDLE mutx;
extern int shieldPanaltyOfWeapon(item_type type, int weapon_kind);
void discard(list<item>::iterator it, int number);


string GetItemInfor(item *it, bool can_use_, set<char> *key);

void memorize_action(int spell_)
{
	changedisplay(DT_GAME);
	if(spell_ == SPL_NONE)
		printlog("�������� �ʴ� �����Դϴ�.",true,false,false,CL_normal);
	else
	{		
		bool ok_ = true;
		while(ok_)
		{
			printlog(SpellString((spell_list)spell_),false,false,false,CL_normal);
			printlog(" �ֹ��� �����ðڽ��ϱ�? (y/n)",false,false,false,CL_help);
			char temp[128];
			sprintf_s(temp,128," [����������: %d%% ���� ���� ����: %d]",100-you.GetSpellSuccess(spell_),you.remainSpellPoiont);

			printlog(temp,true,false,false,CL_warning);
			switch(waitkeyinput())
			{
			case 'Y':
			case 'y':
				you.Memorize(spell_);
				ok_ = false;
				break;
			case 'N':
			case 'n':
			case VK_ESCAPE:
				printlog("����ߴ�.",true,false,false,CL_help);
				ok_ = false;
				break;
			default:
				printlog("Y�� N�߿� �������ּ���.",true,false,false,CL_help);
				break;
			}
		}
	}
	return;

}

//true l�� r���� ũ��
bool compareAlphabet(char l_, char r_)
{
	bool l_small = l_ >= 'a' && l_ <= 'z';
	bool r_small = l_ >= 'a' && l_ <= 'z';
	if (l_small && !r_small)
		return false;
	else if(!l_small && r_small)
		return true;
	return l_ > r_;
}

void swap_list_items(list<item>& l, list<item>::iterator a, list<item>::iterator b)
{
	list<item>::iterator aPlus = a;
	++aPlus; // after position of a, will not be invalidated
	l.splice(b, l, a); // move a before b, invalidates a
	l.splice(aPlus, l, b); // move b before aPlus (where A was)
}


void iteminfor(bool gameover)
{
	view_item(IVT_INFOR,gameover?"����� ������":"���� �������� Ȯ���ϰڽ��ϱ�?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			item *item_ = you.GetItem(key_);
			if(item_)
			{
				while(1)
				{
					set<char> ket_list;
					WaitForSingleObject(mutx, INFINITE);
					SetText() = GetItemInfor(item_, !gameover, &ket_list);
					ReleaseMutex(mutx);
					changedisplay(DT_TEXT);
					int key_ = waitkeyinput(true);
					if(item_->type == ITM_BOOK && (key_ >= 'a' && key_ <= 'f'))
					{
						if(int spell_ = item_->GetValue(key_ - 'a'+1))
						{	
							WaitForSingleObject(mutx, INFINITE);
							SetText() = GetSpellInfor((spell_list)spell_);
							SetText() += "\n\n";
							SetText() += "m�� ������ ������ ����� �� �ֽ��ϴ�.\n";
							ReleaseMutex(mutx);
							int memory_ = waitkeyinput();

							if(memory_ == 'm')
							{
								memorize_action(spell_);
								return;
							}
							continue;
						}
					}
					else if (!ket_list.empty())
					{

						if (ket_list.count(key_) >= 1)
						{
							switch (key_)
							{
							case '=': //����Ű �ٲٱ�
							{
								changedisplay(DT_GAME);
								printlog("���� ���ĺ����� �ٲܰ���? (a-z, A-Z)", true, false, false, CL_help);
								{
									int alphabet_ = waitkeyinput();
									if ((alphabet_ >= 'a' && alphabet_ <= 'z') ||
										(alphabet_ >= 'A' && alphabet_ <= 'Z'))
									{
										list<item>::iterator old_;
										list<item>::iterator new_;
										for (old_ = you.item_list.begin(); old_ != you.item_list.end(); old_++)
										{
											if (old_->id == alphabet_)
											{
												break;
											}
										}
										for (new_ = you.item_list.begin(); new_ != you.item_list.end(); new_++)
										{
											if (new_->id == item_->id)
											{
												break;
											}
										}
										if (new_ == you.item_list.end())
											break;

										char temp[100];
										if (old_ != you.item_list.end())
										{
											old_->id = item_->id;
											new_->id = alphabet_;
											swap_list_items(you.item_list, old_, new_);

											sprintf_s(temp, 100, "%c", old_->id);
											printlog(temp, false, false, false, old_->item_color());
											printlog(" - ", false, false, false, old_->item_color());
											printlog(old_->GetName(), false, false, false, old_->item_color());
											printlog(", ", false, false, false, old_->item_color());
										}
										else
										{
											list<item>::iterator it;
											for (it = you.item_list.begin(); it != you.item_list.end(); it++)
											{
												if (compareAlphabet(it->id, alphabet_))
												{
													new_->id = alphabet_;
													you.item_list.splice(it, you.item_list, new_);
													break;
												}
											}
											if (it == you.item_list.end())
											{
												new_->id = alphabet_;
												you.item_list.splice(it, you.item_list, new_);
											}
										}
										sprintf_s(temp, 100, "%c", new_->id);
										printlog(temp, false, false, false, new_->item_color());
										printlog(" - ", false, false, false, new_->item_color());
										printlog(new_->GetName(), false, false, false, new_->item_color());
										printlog(" ", false, false, false, new_->item_color());
									}
								}
								return;
							}
							case 'w': //����	
								changedisplay(DT_GAME);
								if (you.s_lunatic)
								{
									printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.s_evoke_ghost) {
									printlog("���� ���¿��� �� �� ����. ", true, false, false, CL_normal);
									return;
								}

								if (item_->type >= ITM_WEAPON_FIRST &&item_->type < ITM_WEAPON_LAST)
								{
									if (you.drowned)
									{
										printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
										return;
									}
									you.equip(item_->id, ET_WEAPON);
								}
								else if (item_->type >= ITM_ARMOR_BODY_FIRST &&item_->type < ITM_ARMOR_LAST)
								{
									if (you.drowned)
									{
										printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
										return;
									}
									you.equiparmor(item_->id);
								}
								else if (item_->type == ITM_AMULET)
								{
									you.equipjewerly(item_->id);
								}
								else if (item_->type == ITM_RING)
								{
									you.equipjewerly(item_->id);
								}
								return;
							case 'u': //����
								changedisplay(DT_GAME);
								if (you.s_lunatic)
								{
									printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.s_evoke_ghost) {
									printlog("���� ���¿��� �� �� ����. ", true, false, false, CL_normal);
									return;
								}
								if (item_->type >= ITM_WEAPON_FIRST &&item_->type < ITM_WEAPON_LAST)
								{
									if (you.drowned)
									{
										printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
										return;
									}
									if (!you.unequip(ET_WEAPON))
									{
										printlog("���ֿ� �ɷ� �־ ��� ���� �� ����.", true, false, false, CL_normal);
									}
								}
								else if (item_->type >= ITM_ARMOR_BODY_FIRST &&item_->type < ITM_ARMOR_LAST)
								{
									if (you.drowned)
									{
										printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
										return;
									}
									you.unequiparmor(item_->id);
								}
								else if (item_->type == ITM_AMULET)
								{
									you.unequipjewerly(item_->id);
								}
								else if (item_->type == ITM_RING)
								{
									you.unequipjewerly(item_->id);
								}
								return;
							case 'f': //ź��
							{
								changedisplay(DT_GAME);
								you.throw_weapon = item_;
								char temp[100];
								sprintf_s(temp, 100, "%c", item_->id);
								printlog(temp, false, false, false, item_->item_color());
								printlog(" - ", false, false, false, item_->item_color());
								printlog(item_->GetName(), false, false, false, item_->item_color());
								printlog("(ź��) ", false, false, false, item_->item_color());
							}
								return;
							case 'q': //���ñ�
								changedisplay(DT_GAME);
								if (you.s_lunatic)
								{
									printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.s_evoke_ghost) {
									printlog("���� ���¿��� �� �� ����. ", true, false, false, CL_normal);
									return;
								}
								if (you.drowned)
								{
									printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.Drink(item_->id))
								{
									you.time_delay += you.GetNormalDelay();
									you.doingActionDump(DACT_USE, "����");
									changedisplay(DT_GAME);
									if (you.god == GT_EIRIN)
									{
										if (randA(2))
										{
											you.PietyUpDown(1);
											you.GiftCount(1);
										}
									}
									you.TurnEnd();
								}
								return;
							case 'e': //�Ա�
								changedisplay(DT_GAME);
								if (you.s_lunatic)
								{
									printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.s_evoke_ghost) {
									printlog("���� ���¿��� �� �� ����. ", true, false, false, CL_normal);
									return;
								}
								if (you.drowned)
								{
									printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								you.Eat(item_->id);
								return;
							case 'r': //�б�
								changedisplay(DT_GAME);
								if (you.s_lunatic)
								{
									printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.s_evoke_ghost) {
									printlog("���� ���¿��� �� �� ����. ", true, false, false, CL_normal);
									return;
								}
								if (you.drowned)
								{
									printlog("���� ���� ���¿��� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if(you.Read(item_->id))
								{
									you.doingActionDump(DACT_USE, "�η縶��");
									you.time_delay += you.GetNormalDelay();
									changedisplay(DT_GAME);
									you.TurnEnd();
								}
								return;
							case 'v': //�ߵ�
								changedisplay(DT_GAME);
								if (you.s_lunatic)
								{
									printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
									return;
								}
								if (you.s_evoke_ghost &&
									!(item_->type == ITM_MISCELLANEOUS && item_->value1 == EVK_GHOST_BALL)
									) {
									printlog("���ɻ��¿��� �� �� ����. ", true, false, false, CL_normal);
									return;
								}
								if (you.Evoke(item_->id))
								{
									you.time_delay += you.GetNormalDelay();
									you.TurnEnd();
								}
								return;
							case 'd': //������
							case 'D':
								{
									changedisplay(DT_GAME);
									if (you.s_lunatic)
									{
										printlog("���⿡ �۽��� ���·� �� �� ����!", true, false, false, CL_danger);
										return;
									}
									if (you.s_evoke_ghost) {
										printlog("���� ���¿��� �� �� ����. ", true, false, false, CL_normal);
										return;
									}
									bool discard_ = false;
									for (auto it = you.item_list.begin(); it != you.item_list.end(); it++)
									{
										if (&(*it) == item_)
										{
											if (you.possibleunequip(it))
											{
												discard(it, GetItemofNum(it, you.item_list.end()));
												discard_ = true;
												break;
											}
											else
											{
												break;
											}
										}
									}
									if (!discard_)
									{
										printlog("�������� �ʴ� ���Դϴ�.", true, false, false, CL_normal);
									}
									return;
								}
							}
						}
					}
					else
						waitkeyinput();
					break;
				}
				view_item(IVT_INFOR,gameover?"����� ������":"���� �������� Ȯ���ϰڽ��ϱ�?");
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
		else if(key_ == VK_ESCAPE || (key_ == VK_RETURN && gameover))
			break;
	}
	changedisplay(DT_GAME);
}

string GetItemInfor(item *it, bool can_use_, set<char> *key)
{
	string use_text_;
	
	string text_ = it->GetName();
	text_ += "\n\n";

	if (can_use_)
	{
		use_text_ += "(=)����Ű����, ";
		if (key) key->insert('=');
	}
	switch (it->type)
	{
		//case ITM_WEAPON_DAGGER:
		//	text_ += "�ܰ��� �������� ���� Į�̴�. ���� ����ϴµ� Ư�� ������ �����̴�.\n\
		//			  ������ ź������ ���� �͵� �����ϴ�.\n";
	case ITM_WEAPON_SHORTBLADE:
	case ITM_WEAPON_LONGBLADE:
	case ITM_WEAPON_MACE:
	case ITM_WEAPON_SPEAR:
	case ITM_WEAPON_AXE:
		//case ITM_WEAPON_BOW:
	{
		skill_type ski_ = SKT_MACE;
		switch (it->type)
		{
		case ITM_WEAPON_SHORTBLADE:
			text_ += "���� ª�� ���̴�. ���� �ӵ��� ������ �� �ִ�.\n";
			ski_ = SKT_SHORTBLADE;
			switch (it->value0)
			{
			case 0:
				text_ += "�޴��ϱ� ���� ���� �ܰ�. �������� �������� ������ ���� ���� �������µ� ȿ�����̴�.\n";
				break;
			case 1:
				text_ += "������ ����� ����ȭ�� �ܰ�. ���������ε� �� �� ������ ȿ���� ��������.\n";
				text_ += "��� �������� �ٽ� �ֿ��������� �̸� �ذ��� �� �ִٸ� ������ ��ô������ �ȴ�.\n";
				break;
			case 2:
				text_ += "�ٸ� �ܰ˿� ���ؼ� ���� ���������� �� �� ���� ������ ���� �� �����.\n";
				text_ += "���� �ܰ����� �������� �ϰ���� ����̶�� ���Ե� ���̴�.\n";
				break;
			}
			break;
		case ITM_WEAPON_LONGBLADE:
			text_ += "���� �� ����̴�. ��ų� ���鼭 ��븦 �����Ѵ�.\n";
			ski_ = SKT_LONGBLADE;
			switch (it->value0)
			{
			case 0:
				text_ += "����� �������� ������ Ư¡�̶��� ���� ������ ���� ���� ����� ��.\n";
				break;
			case 1:
				text_ += "����ٱ����� ���� ���ٴϴ� ���� ũ�� ���η����ִ� ���.\n";
				text_ += "���� �ξ� ũ�� ������ ������ ��˺��� �� ū �������� �ش�.\n";
				break;
			case 2:
				text_ += "���� �Ŵ��� �糯�� �޸� ��. ������ε� ����� ��Ⱑ �����.\n";
				text_ += "�� ũ�⿡ �ɸ´� �ı����� ���������� ����� �ٷ�⿣ ������ �ʿ��ϴ�.\n";
				break;
			case 3:
				text_ += "����� �������� ���� ����ϴ� �ձ׷��� ���� �޸� ��ô�� ����.\n";
				text_ += "������ ���������� ������ �� ȸ�������� �ٽ� �ڽſ��� ���ƿ� �� �� �ִ�.\n";
				text_ += "�̰� ���̶�� �� �� ������ �𸣰����� �տ� ��� ��ó���� ����� �� �ִ�.\n";
				break;
			}
			break;
		case ITM_WEAPON_MACE:
			text_ += "������ �б��.\n";
			switch (it->value0)
			{
			case 0:
				text_ += "�Ż��� ������� ���縦 �Ҷ� ����ϴ� ����뱸... ������\n";
				text_ += "������ �� ȯ������ ������� �������� ���ݵ����� ����ϴ� ���� ����.\n";
				text_ += "�׷��� ȿ������ ����� �ƴ����� ������ �õ��غ� ��ġ�� �ִ�.\n";
				break;
			case 1:
				text_ += "��������� ���� ���� �ٴϴ� ���ڷ�. �������� �÷��ְų� �׷� �뵵�� ����.\n";
				text_ += "���� ���ڷ縦 ������ ������ ������ ������� ���ڷ��� Ư���� �����ε� �ϴ�.\n";
				text_ += "�б�μ� ����ϴ°� �׳��� Ȱ���غ� �� �ִ�.\n";
				break;
			case 2:
				text_ += "�����̵��� ����Ѵٴ� ���. ���� �䱫�ϼ��� ����� ����Ϸ��� ǳ���� �ִµ��ϴ�.\n";
				text_ += "�׷��� ȿ�������������� ���� ����ô�� �ϰ� ���� ������̶�� ����غ��°� ���?\n";
				break;
			case 3:
				text_ += "������ ã�µ� ������ �شٰ� �Ͼ����� ��. �׷��� �̷� �Ӽ��� �̽��ε� �ʹ�.\n";
				text_ += "������ ã�µ� ������ ���������� �ٷ�� ���� �ݼ� ������ �������� �� �� �ִ�.\n";
				text_ += "������� �ٷ�µ� Ưȭ�Ǿ��־, ���п� �Բ���� ȿ���� ��������.\n";
				break;
			case 4:
				text_ += "���� �Ŵ��� ������� �̷� ���� ����� ���� �����ߴٴ°� �ű��� ������.\n";
				text_ += "���� �ͼ������� �ֵθ��µ��� ��û�� �ð��� �ɸ��� �ϴ�.\n";
				text_ += "���߱⵵ �����ʾƺ������� ����ٸ� ��û�� �������� �� �� �ִ�.\n";
				break;
			}
			ski_ = SKT_MACE;
			break;
		case ITM_WEAPON_SPEAR:
			text_ += "��ٶ� â�̴�. ���� �񷯼� ������ �� �ִ�.\n";
			ski_ = SKT_SPEAR;
			switch (it->value0)
			{
			case 0:
				text_ += "���� ū Ư¡�� ���� ����� â. ��µ� �� �� �ִ�.\n";
				break;
			case 1:
				text_ += "�����µ� Ưȭ�Ǿ��ִ� �Ŵ��� â. ���� ������ ������ ���� �� �ִ�.\n";
				text_ += "�������������� ����� ����� ���������� �ֵθ��⿣ ���������ʴ�.\n";
				break;
			case 2:
				text_ += "����� ���� ���ٴѴٴ� �Ŵ��� ��.\n";
				text_ += "�������� ����μ� ����ϱ⿣ ��������̴� ū �������� �ͼ������� ���� ���ϴ�.\n";
				break;
			case 3:
				text_ += "���� 3���޸� ��ٶ� �ۻ����� ��µ� Ưȭ�� â�̴�.\n";
				text_ += "������ ���� ������ ���� ������ �������ʴ´�.\n";
				break;
			case 4:
				text_ += "�볪���� ��Ƽ� ���� â. \n";
				text_ += "���� ����� âó�� �������� ������� ������ ����� �ִ�.\n";
				text_ += "����� �ٷ���� ����� ������ �ʿ��ϴ�.\n";
				break;
			}
			break;
		case ITM_WEAPON_AXE:
			text_ += "���� ���� �� �ִ� ����. �Ŵ��� ���� �����.\n";
			ski_ = SKT_AXE;
			switch (it->value0)
			{
			case 0:
				text_ += "�Ѽ����� �� �� �ִ� ���� �յ�����. ū ������ ������������ �ٷ�� ����.\n";
				break;
			case 1:
				text_ += "��ٶ� �ڷ翡 ū �������� �޸� �Ŵ��� ������.\n";
				break;
			case 2:
				text_ += "����� �������� ���� ���ٴϴ� �Ŵ��� ���̴�.\n";
				text_ += "���� ���������� �̷��� �ֵθ����� ���� �Ƿ��� �ʿ��ϴ�.\n";
				break;
			}
			break;
		}

		if (it->value5 && it->value6)
		{
			text_ += "\n\n";
			text_ += GetBrandInfor((weapon_brand)it->value5);
			text_ += "\n";
		}
		
		{
			//��ų���� �������ֱ�
			char temp[100];
			sprintf_s(temp, 100, "\n\n�� ����� %s ��ų�� ����Ͽ� ��������. (���� %s ��ų ���� : %d)", skill_string(ski_), skill_string(ski_), you.GetSkillLevel(ski_, true));
			text_ += temp;

			sprintf_s(temp,100, "\n���ݷ� : %d       ���߷� : %d", it->value2, it->value1);
			text_ += temp;
			sprintf_s(temp,100, "\n������ݼӵ� : %g    ( �⺻���ݼӵ� : %g       �ּҰ��ݼӵ� : %g )", max((it->value8)/100, (it->value7 - you.GetSkillLevel(ski_, true) / 2.0f)) / 10.0f, it->value7 / 10.0f, it->value8/10.0f);
			text_ += temp;
			if (shieldPanaltyOfWeapon(it->type, it->value0)) {
				sprintf_s(temp,100, "\n��, �� ����� ���и� ��ԵǸ� ���ݼӵ��� %g��ŭ �߰������� ��������.", shieldPanaltyOfWeapon(it->type, it->value0) / 10.0f);
				text_ += temp;
			}
		}


		if (it->can_throw)
		{
			char temp[100];
			sprintf_s(temp,100, "\n\n�� �������� ���� ����ε� ��밡�������� ������ ź�����ε� ����� �� �ִ�.");
			text_ += temp;
			sprintf_s(temp,100, "\n�� ��� ���� ��ô�ӵ��� %g�̴�. (���� ź�� ��ų ���� : %d)", you.GetThrowDelay((*it).type, false) / 10.0f, you.GetSkillLevel(SKT_TANMAC, true));
			text_ += temp;
		}

		{
			char temp[100];
			sprintf_s(temp,100, "\n\n�� �������� +9���� ��æƮ�� �����ϴ�.");
			text_ += temp;
		}


		if(can_use_)
		{
			if (you.equipment[ET_WEAPON] != it)
			{
				use_text_ += "(w)����, ";
				if (key) key->insert('w');
			}
			else
			{
				use_text_ += "(u)����, ";
				if (key) key->insert('u');
			}
			if (it->can_throw)
			{
				use_text_ += "(f)ź��, ";
				if (key) key->insert('f');
			}
		}
		break;
	}
	case ITM_THROW_TANMAC:
	{
		switch (it->value4)
		{
		default://���� �̰� �߸� ����
			text_ += "ź�� ������ �⺻�� �Ǵ� ź���̴�. ������ ������ �����.\n";
			text_ += "������ �̰� ���� ź���̶�� ���̴�.\n";
			break;
		case TMT_AMULET:
			text_ += "���̹��� ���� �� ġ���� �ƹķ����� ������ ȣ�ּ����� �پ��ִ�.\n";
			text_ += "Ư���� Ư¡�� ���� ź�������� ���� �������� �ڶ��̴�.\n";
			break;
		case TMT_POISON_NEEDLE:
			text_ += "�̰��� �����鼭 ��뿡�� ������ �������̴�.\n";
			text_ += "�������� ������ �� �����˿��� Ư���� ���� �߶����ִ°� ����.\n";
			break;
		case TMT_KIKU_COMPRESSER:
			text_ += "ı�ĵ��� �߸�ǰ�� �ϳ���. ���� ���� �����ϰ��ִ� ��ź�̴�.\n";
			text_ += "��뿡�� ������ ����Ǿ��ִ� ���� �ѹ��� ������.\n";
			text_ += "���� ���� ������ �� ���� �� ����.\n";
			break;
		case TMT_DOGGOJEO:
			text_ += "�ұ��� �·����� �����Ҷ� ����ߴٰ� �ϴ� ��� �ε��� ����.\n";
			text_ += "��ҿ� ����� ������ó�� �������� ���� ������ ������ ������ ����ȴ�.\n";
			text_ += "�ٸ� ź���� �ٸ��� ������ �����Ͽ� ������ �����ϴ�.\n";
			break;
		}
		char temp[100];
		sprintf_s(temp,100, "\n���ݷ� : %d       ���߷� : %d", it->value2, it->value1);
		text_ += temp;
		sprintf_s(temp,100, "\n���� ��ô�ӵ� : %g (���� ź�� ��ų ���� : %d)", you.GetThrowDelay((*it).type, false) / 10.0f, you.GetSkillLevel(SKT_TANMAC, true));
		text_ += temp;

		if (can_use_)
		{
			if (it->can_throw)
			{
				use_text_ += "(f)ź��, ";
				if (key) key->insert('f');
			}
		}
	}
	break;
	case ITM_ARMOR_BODY_ARMOUR_0:
	case ITM_ARMOR_BODY_ARMOUR_1:
	case ITM_ARMOR_BODY_ARMOUR_2:
	case ITM_ARMOR_BODY_ARMOUR_3:
	{
		switch (it->value5)
		{
		case AMK_NORMAL:
			text_ += "���ÿ� �Դ� ���� ��.\n";
			text_ += "õ�� �ƴ� ������ ���� �⺻�г�Ƽ�� ����� ��������. \n";
			text_ += "�׷��� �ּ��г�Ƽ�� �ٸ� �ʰ� �����ϹǷ� ���ʿ� �ͼ������� ������ ��������.\n\n";
			break;
		case AMK_MIKO:
			text_ += "������� �Դ� ��.\n";
			text_ += "���� ��ȣ�� �޾Ƽ� ������ ��ȣ���ش�. �԰��ִ� ���� ȥ�������� �����.\n\n";
			break;
		case AMK_WING:
			text_ += "����� ���ڵ��� �Դ´ٴ� ������.\n";
			text_ += "���⸦ ��������� Ư¡�� ������ �ִ�. �԰��ִ� ���� ���������� �����.\n\n";
			break;
		case AMK_KAPPA:
			text_ += "ı�ĵ��� ������ó�� �԰� �ִ� �Ķ��� ���̴�.\n";
			text_ += "���� �������� �ߵ� �� �ְ� ������ �Ǿ��ִ�. �԰��ִ� ���� �ñ������� �����.\n\n";
			break;
		case AMK_FIRE:
			text_ += "������ ����� �����ִ� ���̴�.\n";
			text_ += "�߰ſ� ������ �ߵ� �� ���� �� ����. �԰��ִ� ���� ȭ�������� �����.\n\n";
			break;
		case AMK_MAID:
			text_ += "ȫ������ ���̵���� �Դ� ��.\n";
			text_ += "ȫ���� ������ǥ Ư���� ������ ó���� �Ǿ��ִ�. �԰��ִ� ���� ���������� �ö󰣴�.\n\n";
			break;
		case AMK_POISON:
			text_ += "����� �ɹ��� ������ �԰� �ִ� �������� �� ����� Ŀ�� ���� �� ���� �� ����.\n";
			text_ += "����� ���� ����� ����� ��ȣ���ش�. �԰��ִ� ���� �������� �����.\n\n";
			break;
		case AMK_AUTUMN:
			text_ += "��ǳ���� ������� ��. �ǿܷ� ����ε� ���̴�.\n";
			text_ += "�����ϸ� �ϰ������� �ֺ��� ǳ�濡 ��ȭ�Ǿ ������ �ް��ϰ� �ö󰣴�.\n\n";
			break;
		}
		switch (it->type)
		{
		case ITM_ARMOR_BODY_ARMOUR_0:
			text_ += "�����̱� ���ϰ� õ���� �Ǿ��ִ� ��.\n";
			text_ += "���� �׷������ �������� ���� �ʰ����� �Ǿ��ִ�!\n";
			break;
		case ITM_ARMOR_BODY_ARMOUR_1:
			text_ += "���� ������ �Ǿ��ִ� ��.\n";
			text_ += "õ���� �����̱� ���������� �� ������.\n";
			break;
		case ITM_ARMOR_BODY_ARMOUR_2:
			text_ += "�罽�� �����ִ� ����.\n";
			text_ += "�� �ܴ������� �Ǳ����ε� ���ʺ��ٴ� ���ϴ�.\n";
			break;
		case ITM_ARMOR_BODY_ARMOUR_3:
			text_ += "��ö�� �� �Ǳ��� ���� ����.\n";
			text_ += "������ �������� ���������� ����� ������ å������.\n";
			break;
		}
		char temp[100];
		sprintf_s(temp,100, "\n\n�⺻ ���� : %d   �⺻ �г�Ƽ : %d   �ּ� �г�Ƽ : %d\n", it->value1, it->value2, it->value3);
		text_ += temp;
		sprintf_s(temp,100, "�г�Ƽ�� ���� ��ų�� �ø����� �پ��ϴ�. �ּ� �г�Ƽ���Ϸδ� ���ϼ� �����ϴ�.\n");
		text_ += temp;
		sprintf_s(temp,100, "���� ����� ����: %d     �г�Ƽ : %d (���� ���� ��ų ���� : %d)\n\n", 
			(it->isiden()?it->value4:0) + (int)(it->value1*(1.0f + you.GetSkillLevel(SKT_ARMOUR, true) / 15.0f)),
			min(it->value3, it->value2 + you.GetSkillLevel(SKT_ARMOUR, true) / 3), you.GetSkillLevel(SKT_ARMOUR, true));
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ��ŭ ȸ�ǿ� ����, ������������ �����մϴ�.\n");
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ�� %d���� ������ �г�Ƽ��ŭ �߰������� �������� �����մϴ�.\n", you.GetPenaltyMinus(1));
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ�� %d���� ������ �г�Ƽ��ŭ �̵��ӵ��� �����մϴ�.\n", you.GetPenaltyMinus(2));
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ�� %d���� ������ ��� �ൿ�� 2�� �����̵˴ϴ�.\n\n", you.GetPenaltyMinus(3));
		text_ += temp;
		sprintf_s(temp,100, "\n�� �������� +%d���� ��æƮ�� �����ϴ�.", it->value1);
		text_ += temp;


		if (can_use_)
		{
			if (you.equipment[ET_ARMOR] != it)
			{
				use_text_ += "(w)����, ";
				if (key) key->insert('w');
			}
			else
			{
				use_text_ += "(u)����, ";
				if (key) key->insert('u');
			}
		}
		break;
	}
	case ITM_ARMOR_SHIELD:
	{
		text_ += "����� ������ ���� ���� ����. ��չ��⸦ ��� ������ ������ �Ұ����ϴ�.\n";
		text_ += "����� ź���� ���� ��Ģ���� Ȱ�뵵 �����ϴ�.\n";
		char temp[100];
		sprintf_s(temp,100, "\n\n�⺻ ���� : %d   �⺻ �г�Ƽ : %d   �ּ� �г�Ƽ : %d\n", it->value1, it->value2, it->value3);
		text_ += temp;
		sprintf_s(temp,100, "�г�Ƽ�� ���� ��ų�� �ø����� �پ��ϴ�. �ּ� �г�Ƽ���Ϸδ� ���ϼ� �����ϴ�.\n"); 
		text_ += temp;
		sprintf_s(temp,100, "���� ����� ����: %d    �г�Ƽ : %d (���� ���� ��ų ���� : %d)\n\n",
			(it->isiden() ? it->value4 : 0) + (int)(it->value1*(1.0f + (you.s_dex / 5.0f + you.GetSkillLevel(SKT_SHIELD, true)) / 15.0f)*(you.GetProperty(TPT_SLAY)?1.2f:1.0f)),
			min(it->value3, it->value2 + you.GetSkillLevel(SKT_SHIELD, true) / 3), you.GetSkillLevel(SKT_SHIELD, true));
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ��ŭ ȸ�ǿ� ����, ����������, ������ �����մϴ�.\n");
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ�� %d���� ������ �г�Ƽ��ŭ �߰������� �������� �����մϴ�.\n", you.GetPenaltyMinus(1));
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ�� %d���� ������ �г�Ƽ��ŭ �̵��ӵ��� �����մϴ�.\n", you.GetPenaltyMinus(2));
		text_ += temp;
		sprintf_s(temp,100, "�հ� �г�Ƽ�� %d���� ������ ��� �ൿ�� 2�� �����̵˴ϴ�.\n\n", you.GetPenaltyMinus(3));
		text_ += temp;
		sprintf_s(temp,100, "�� �������� +%d���� ��æƮ�� �����ϴ�.", it->value1 <= 4 ? 3 : (it->value1 <= 8 ? 6 : 9));
		text_ += temp;

		if (can_use_)
		{
			if (you.equipment[ET_SHIELD] != it)
			{
				use_text_ += "(w)����, ";
				if (key) key->insert('w');
			}
			else
			{
				use_text_ += "(u)����, ";
				if (key) key->insert('u');
			}
		}
		break;
	}
	case ITM_ARMOR_HEAD:
	case ITM_ARMOR_CLOAK:
	case ITM_ARMOR_GLOVE:
	case ITM_ARMOR_BOOT:
	{
		switch (it->type)
		{
		case ITM_ARMOR_HEAD:
			text_ += "�Ӹ��� �� �� �ִ� ��ű�. �м��� �⺻\n";
			if (can_use_)
			{
				if (you.equipment[ET_HELMET] != it)
				{
					use_text_ += "(w)����, ";
					if (key) key->insert('w');
				}
				else
				{
					use_text_ += "(u)����, ";
					if (key) key->insert('u');
				}
			}
			break;
		case ITM_ARMOR_CLOAK:
			text_ += "���� �θ��� ������ ����.\n";
			if (can_use_)
			{
				if (you.equipment[ET_CLOAK] != it)
				{
					use_text_ += "(w)����, ";
					if (key) key->insert('w');
				}
				else
				{
					use_text_ += "(u)����, ";
					if (key) key->insert('u');
				}
			}
			break;
		case ITM_ARMOR_GLOVE:
			text_ += "�տ� �� �� �ִ� �尩�̴�. �尩�� ���ְ� �ɷ������� ������ ���� �� �� ����.\n";
			if (can_use_)
			{
				if (you.equipment[ET_GLOVE] != it)
				{
					use_text_ += "(w)����, ";
					if (key) key->insert('w');
				}
				else
				{
					use_text_ += "(u)����, ";
					if (key) key->insert('u');
				}
			}
			break;
		case ITM_ARMOR_BOOT:
			text_ += "���� ��ȣ�ϴ� �Ź�. ������ �ٴ��� �ǹ߷� �ٴϰ� ���������� �� ��������.\n";
			if (can_use_)
			{
				if (you.equipment[ET_BOOTS] != it)
				{
					use_text_ += "(w)����, ";
					if (key) key->insert('w');
				}
				else
				{
					use_text_ += "(u)����, ";
					if (key) key->insert('u');
				}
			}
			break;
		}
		char temp[100];
		sprintf_s(temp,100, "���� : %d", it->value1);
		text_ += temp;
		sprintf_s(temp,100, "\n\n�� �������� +2���� ��æƮ�� �����ϴ�.");
		text_ += temp;
	}
	break;
	case ITM_POTION:
	{
		if (iden_list.potion_list[it->value1].iden)
		{
			switch (it->value1)
			{
			case PT_WATER:
				text_ += "�ܼ��� ���� �����̴�.\n";
				break;
			case PT_HEAL:
				text_ += "ġ�� �����̴�. ���ø� ���� �������� �����̻󿡼� ȸ���ǰ� ü�µ� ȸ���ȴ�.\n";
				text_ += "ȿ���� ���� ��� ���ֵǴ� �ź��� ����\n";
				break;
			case PT_POISON:
				text_ += "���� ����ִ� �����̴�. ���ܿ� ���� ���� ���ø� ������ ���� �ɸ���.\n";
				break;
			case PT_HEAL_WOUND:
				text_ += "��ó�� ġ���ϴ� �����̴�. ������ ���������� ���� ü���� ġ���Ѵ�.\n";
				text_ += "�ٸ� �����̻��� ġ�������� ���Ѵ�.\n";
				break;
			case PT_MIGHT:
				text_ += "���������� ���� �ٷ��� �����ϰ� �Ǵ� ����. ���ݷµ� ��������.\n";
				break;
			case PT_HASTE:
				text_ += "���� �ӵ��� �����̰� �����ִ� ����. �̵�, �ൿ ��� 2����� �ȴ�.\n";
				break;
			case PT_CONFUSE:
				text_ += "���ø� ���ſ� ȥ���� �������ִ� ����.\n";
				text_ += "ȥ���� ������������� ���ڸ��� ���� ������ ��ٸ��� �͵� ����̴�.\n";
				break;
			case PT_SLOW:
				text_ += "�������� �������� ����. ��� �̵�, �ൿ�� 1/2����� �ȴ�.\n";
				break;
			case PT_PARALYSIS:
				text_ += "���ø� ���ϰ� ���� ����Ǵ� ����. �����ϴ�.\n";
				break;
			case PT_CLEVER:
				text_ += "���ø� �Ͻ������� ������ �������� ����.\n";
				text_ += "���ɰ� �Բ� ����������, �����Ŀ��� ���� �ö󰣴�.\n";
				break;
			case PT_AGILITY:
				text_ += "���ø� �Ͻ������� ��ø�� �������� ����.\n";
				text_ += "��ø�� �Բ� ȸ�ǵ� �ö󰣴�.\n";
				break;
			case PT_MAGIC:
				text_ += "���ø� ������ ���İ��� ä���ִ� ������ ����.\n";
				break;
			case PT_LEVETATION:
				text_ += "���ø� �Ͻ������� ������°� �Ǵ� ����. ������¿����� ������������ �ǳ� �� �ְԵȴ�.\n";
				break;
			case PT_POWER:
				text_ += "���ø� �Ŀ��� ����ϴ� �Ŀ��� ����.\n";
				text_ += "���� ��� P�� 1.00�����ϰ� �ȴ�.\n";
				break;
			case PT_DOWN_STAT:
				text_ += "���ø� �Ͻ������� �ɷ�ġ�� �����ϰ� �Ǵ� ���ܿ� ����.\n";
				text_ += "�� ���� ��ø�� ������ �ɷ�ġ�� �Ͻ������� ���ҵȴ�. �ð��� ������ �ǵ��� �´�.\n";
				break;
			case PT_RECOVER_STAT:
				text_ += "���ø� �Ͻ������� �Ҿ���� �ɷ�ġ�� ������ ȸ�������ִ� ����.\n";
				break;
			case PT_ALCOHOL:
				text_ += "�̰��� ���̴�. ���ø� ���Ѵ�.\n";
				text_ += "���� ���� ���¸� �ȹٷ� �����̱� ����� ����.\n";
				break;

			default:
				text_ += "�̰� ���� �����̴�. �����ϱ�!\n";
				break;
			}
		}
		else
		{
			text_ += "���� �ǽɽ����� ��ü�� ����ִ� ��. ���ź��� �ʰ� �� �� ���� �� ����.\n";
		}
		if (can_use_)
		{
			use_text_ += "(q)���ñ�, ";
			if (key) key->insert('q');
		}
	}
	break;
	case ITM_FOOD:
		text_ += "���� �� �ִ� �����̴�. ������ �̷� ���ĵ��� �������ִ� �͵� ���������� ���� �� �־� ���δ�.\n";
		if (can_use_)
		{
			use_text_ += "(e)�Ա�, ";
			if (key) key->insert('e');
		}
		break;
	case ITM_SCROLL:
	{
		if (iden_list.scroll_list[it->value1].iden == 3)
		{
			switch (it->value1)
			{
			case SCT_TELEPORT:
				text_ += "������ �̻��� �����̵��� ����Ű�� �η縶��. ��, ���ڸ��� �����̵��� ���� �ʴ´�.\n";
				text_ += "������ �غ�Ⱓ�� �ʿ��ϴ�. �����̵��� �ɸ� ���¿��� ������ �� ���� ��ȭ���� ������ �� �� �ִ�.\n";
				break;
			case SCT_IDENTIFY:
				text_ += "�ĺ��� �η縶��. �а��� �տ� �� ������ �ĺ��� �� �ְ� �ȴ�. �ſ� �߿��� �η縶��\n";
				text_ += "�� �ݿ� ���������� �ɷ°� �ſ� ����ϴ�.\n";
				break;
			case SCT_NONE:
				text_ += "�峭�ٷ��� �������� �ǹ̾��� ����� ������!\n";
				break;
			case SCT_CURSE_WEAPON:
				text_ += "����ִ� ���⿡ ���ָ� �Ǵ�. ���ֿ� �ɸ� ���� ���ְ� Ǯ���������� ������ �� ���� �ȴ�.\n";
				break;
			case SCT_CURSE_ARMOUR:
				text_ += "����ִ� ���� ���ָ� �Ǵ�. ���ֿ� �ɸ� ���� ���ְ� Ǯ���������� ������ �� ���� �ȴ�.\n";
				break;
			case SCT_REMOVE_CURSE:
				text_ += "����ִ� ����� ���ָ� �����Ѵ�. ��� ���ݵ� �������.\n";
				break;
			case SCT_BLINK:
				text_ += "�þ߳��� ������ ��ġ�� �����̵��� �ϰ� �����ִ� �η縶��.\n";
				text_ += "����Ż������� �ְ��� �η縶����.\n";
				break;
			case SCT_MAPPING:
				text_ += "���� �ִ� ���� ���� �����ִ� �η縶��.\n";
				break;
			case SCT_ENCHANT_WEAPON_1:
			case SCT_ENCHANT_WEAPON_2:
				text_ += "���� �����Ǿ��ִ� ������ ���ݷ°� ���߷��� ��ȭ��ų �� �ִ�. ���� ���ֵ� �����ش�.\n";
				break;
			case SCT_ENCHANT_ARMOUR:
				text_ += "������ ���� ������ ��ȭ��ų �� �ִ�. ���� ���ֵ� �����ش�.\n";
				break;
			case SCT_FOG:
				text_ += "���⸦ ����� ���� �η縶��.\n";
				text_ += "����� ���� �ڽ��� �þ߸� �����ش�.\n";
				break;
			case SCT_DETECT_CURSE:
				text_ += "����ǰ�߿� ���ְ� �ɸ� �������� Ž���ϴ� �η縶��.\n";
				text_ += "Ž���� �������� ��� �ĺ��� �ȴ�.\n";
				break;
			case SCT_CURSE_JEWELRY:
				text_ += "�����ϰ� �ִ� ��ű��� ���ָ� �Ŵ� �η縶��.\n";
				text_ += "������ ������� ������ �Ѱ��� ��ű��� ���ְ� �ɸ���.\n";
				break;
			case SCT_SILENCE:
				text_ += "�ֺ��� ������ ���̴� �η縶��. �Ͻ������� �������°� �ȴ�.\n";
				text_ += "���������ȿ� �ִ� ���� ������ ����������ϸ� ������ �ð��� ������ ���� �پ���.\n";
				text_ += "��, �ڽŵ� �Ҹ��� �����ϴ� ������ �η縶��, �Ǵ��� ������� ���ϰ� �ȴ�.\n";
				break;
			case SCT_SOUL_SHOT:
				text_ += "������ ����ϴ� �η縶��, �ֺ��� ������ ������ �� ���� ª�� ���� �Ǵ�.\n";
				text_ += "ȿ���� ������������ P�� ��ĭ ������ �Ҹ��ϰԵȴ�.\n";
				break;
			case SCT_CHARGING:
				text_ += "����ī�带 �����ϴ� �η縶��. ������� ����� ����ī���� �������� �����Ѵ�.\n";
				text_ += "����ī���� �ִ�ġ�� �������� �����ϴ� �絵 �þ��.\n";
				break;
			case SCT_AMNESIA:
				text_ += "��� ������ �ش� ������ �η縶��. ���� ���� �ִ� �����߿� �ϳ��� �����Ͽ� �ش´�.\n";
				text_ += "������ ��ﶧ ����� ������ �����޴´�.\n";
				break;
			case SCT_SANTUARY:
				text_ += "���� ���� ���� ������ ��ġ�� �η縶��. ���������� ��� ������ �������� ��ȿ�� �Ѵ�.\n";
				text_ += "�� �ӿ� ��� ��� �߸��ٰ� ������ٰ� �ϴ� ���� �η縶��.\n";
				break;
			case SCT_BRAND_WEAPON:
				text_ += "���� ��� �ִ� ���⿡ �������� ���� �ο��ϴ� �η縶��.\n";
				text_ += "� ������ �ο������� �� �� ������ ������ �ο��� �������� ���� ���������.\n";
				break;
			default:
				text_ += "������ �η縶��. �� �����ڿ��� ���׷� �Ű��ع�����!\n";
				break;
			}
		}
		else
		{
			text_ += "�� �� ���� ���ڵ��� �����Ǿ��ִ� �η縶��.\n";
		}
		text_ += "�Ҹ���� ������ �η縶���� ����� ������ ���� ��� �� �ִ�.\n";
		if (can_use_)
		{
			use_text_ += "(r)�б�, ";
			if (key) key->insert('r');
		}
	}
	break;
	case ITM_SPELL:
	{
		if (iden_list.spellcard_list[it->value2].iden == 2)
		{
			switch (it->value2)
			{
			case SPC_V_FIRE:
				text_ += "ȭ���� ����� ���� ����ī���.\n";
				text_ += "����ϸ� ���ϴ� ������ ���� ������ ȭ�������� �����Ѵ�.\n";
				text_ += "�ߵ���ų�� ������ ������ ���ӽð��� �������.\n";
				break;
			case SPC_V_ICE:
				text_ += "�ñ��� ����� ���� ����ī���.\n";
				text_ += "��뿡�� ������ �ñ������ ���Ѵ�.\n";
				text_ += "�ߵ���ų�� ������ �������� ��������.\n";
				break;
			case SPC_V_EARTH:
				text_ += "������ ����� ���� ����ī���.\n";
				text_ += "��ü ������ ������ ���� �ε����� ���� ���߽��� ���� ���� �������� ������.\n";
				text_ += "�ߵ���ų�� ������ �������� ��������.\n";
				break;
			case SPC_V_AIR:
				text_ += "����� ����� ���� ����ī���.\n";
				text_ += "��ä���� ���� ������ ź���� ���� �������� ������ ����������.\n";
				text_ += "�ߵ���ų�� ������ ������ ������ ������ ��������.\n";
				break;
			case SPC_V_INVISIBLE:
				text_ += "�޺��� ����� ���� ����ī���.\n";
				text_ += "����� ����� �����ð� �����ϰ� �����.\n";
				text_ += "�ߵ���ų�� ������ ������ ���ӽð��� �������.\n";
				break;
			case SPC_V_METAL:
				text_ += "�ݼ��� ����� ���� ����ī���.\n";
				text_ += "����ϸ� �������� ö���ø� 3�������� �߻��Ѵ�.\n";
				text_ += "�ߵ���ų�� ������ �������� ��������.\n";
				break;
			case SPC_V_SUN:
				text_ += "�¾��� ����� ���� ����ī���.\n";
				text_ += "����ϸ� ū ���� �߻��Ͽ� �ֺ��� ���� ������ �ϰ� ȥ���� �Ǵ�.\n";
				text_ += "ȥ���� ���Ҽ��� ������ �� ������ ���������� �ɸ����ʴ´�.\n";
				text_ += "����, �����Ϳ��� �ܼ��� ȥ��ȿ�� �̻��� �������� �� �� �ִٰ� �Ѵ�.\n";
				text_ += "�ߵ���ų�� ������ ���ӽð��� ȥ���� �ɸ� Ȯ���� �þ��.\n";
				break;
			default:
				text_ += "������ ����ī���.\n";
				break;
			}
			text_ += "\n";
		}
		text_ += "����ī��� ������ Ƚ�������� ������� ����� �� ������ �ʰ��ϸ� ���̻� ����� �� ���Եȴ�.\n";
		text_ += "��Ȯ�� ���� ������ �ĺ��� �ؾ� Ȯ���� �� �ִ�. ����ī��� �ߵ����� ����ؼ� ������ �ö󰣴�.\n";
		if (can_use_)
		{
			use_text_ += "(v)�ߵ�, ";
			if (key) key->insert('v');
		}
	}
	break;
	case ITM_AMULET:
	{
		text_ += "������ ���� ����ִ� ����. �⺻������ �ƹ��� ���� ������ �����ʴ� ����� ����������\n";
		text_ += "������ ä�� ����ġ�� ������ ������ �������� ���� �����Ǹ� 100%�� �Ǹ� ���� �����Ѵ�.\n";
		text_ += "���� �����ϰ��ִ� ������ ������ �� ��� �������� 0%�� �������Ƿ� �����ؾ��Ѵ�.\n\n";
		if (iden_list.amulet_list[it->value1].iden == 2)
		{
			switch (it->value1)
			{
			case AMT_PERFECT:
				text_ += "�̷��� ü���Ѵٰ� �ϴ� ���̸��� ���־��� ȿ���� ��Ƶ���ִ� ����.\n";
				text_ += "�ٸ� ������ ���� ���� ���� �ӵ��� ������ ������ ���� ���̸� ������ ȸ���� �� �ִ�.\n";
				text_ += "100%�� �� ������ ������ ä�� �װԵǸ� ü���� ���� ȸ���Ǿ� ��Ȱ�Ѵ�.\n";
				text_ += "��, �� ������� ��Ȱ�ϰԵǸ� ������ ��Ÿ ������Եȴ�.\n";
				break;
			case AMT_BLOSSOM:
				text_ += "�ἳ�̺��� ���� ���� ����� ��Ƽ� Ư���� ��踦 �ߵ���ų �� �ִ� ����.\n";
				text_ += "�����ϰ� ������ �ֺ��� ���� ����� ���̰� ������ �Ǹ� ������ �ߵ��� �� �ְ� �ȴ�.\n";
				text_ += "100%�� �� ������ ������ ä�� v�� ������ ������ �ߵ��Ǿ� �ֺ��� ���� �����ð� �����Ų��.\n";
				text_ += "�ߵ��Ŀ��� ����ġ�� 0%�� �Ǿ� �ٽ� ������ �� �ְ� �ȴ�.\n";
				break;
			case AMT_TIMES:
				text_ += "�����̺��� �ذ��Ҷ� ���� ���� ���ߴ� �ּ��� ���� ��� ����.\n";
				text_ += "�����ϰ� ������ �ֺ��� ���ΰ� ���̰� ������ �Ǹ� �ֺ��� �ð��� �帧���� ������ ������ �� �ִ�.\n";
				text_ += "100%�� �� ������ ������ ä�� v�� ������ ������ �ߵ��Ѵ�.\n";
				text_ += "�ߵ��Ŀ��� ����ġ�� 0%�� �Ǿ� �ٽ� ������ �� �ְ� �ȴ�.\n";
				break;
			case AMT_FAITH:
				text_ += "�ž��� ���� ���� �� �ִ� ����.\n";
				text_ += "�����ϰ� ������ �ֺ��� �ž��� ���̰� ������ �Ǹ� �ŵ���� ���谡 ��������.\n";
				text_ += "100%�� �Ǹ� �ڵ����� ���� �žӽ��� ���� ������ ����ġ�� �ٽ� 0%�� �ȴ�.\n";
				text_ += "��� ���� �ž��� �������ʱ⶧���� �� ������ ȿ���� ���� �� �ִ�.\n";
				break;
			case AMT_WAVE:
				text_ += "���������� ���Ͽ����� �ָ� �ִ� ���� ����� �����ϵ��� ������ ����.\n";
				text_ += "�����ϰ� ������ ���ļ��Ű����� ���� �������� ������ �Ǹ� ���� ���� �� ���� �� �� �ִ�.\n";
				text_ += "100%�� �� ������ ������ ä�� v�� ������ ���� ���� ������ ���߰� �ȴ�.\n";
				break;
			case AMT_SPIRIT:
				text_ += "������繦�� ���ڸ� ��Ȱ��ų���� ���Ǿ��ٴ� �ŷ��� ���� �� �ִ� ����.\n";
				text_ += "�����ϰ� ������ �ֺ��� �ŷ��� ���̰� ������ �Ǹ� ���� ����ī�忡 �ŷ��� �Ҿ���� �� �ִ�.\n";
				text_ += "100%�� �� ������ ������ ä�� v�� ������ ������ �ִ� ����ī�� 1���� ������ �� �ִ�.\n";
				break;
			case AMT_GRAZE:
				text_ += "��� �̺������� �߿��� �׷������� ���� ��� ����.\n";
				text_ += "�����ϰ� ������ ���� ������ �ǰ� ������ ������ ����� ź�������� �ȴ�.\n";
				text_ += "100%�� �� ������ ������ ä�ε� ��� �׷���� �ߵ��Ǿ� ���Ÿ� ź���� ����Ȯ���� ���� �� �ְ�\n";
				text_ += "100%���¿��� v�� ������ �ټ�ȸ�ǰ� �ߵ��Ǿ� ȸ�ǰ����� ������ ������ 100% ȸ���Ѵ�.\n";
				text_ += "�׷������Ҷ� ���� �Ҹ��� ����� ����. �׷���� �ǹ̾��� �ø�� �־��ٰ�...?\n";
				break;
			case AMT_WEATHER:
				text_ += "��� �ҷ� õ���� �ڽ��� ���� ���� �ο��� ����.\n";
				text_ += "�����ϰ� ������ �ֺ��� ���� ������ ����ϰ� ������ ������ ������ �����ִ� ������ �ߵ��ȴ�.\n";
				text_ += "100%�� �� ������ ������ ä�� ������ ü�� ȸ���ӵ��� �ణ �����ϸ�\n";
				text_ += "100%���¿��� v�� ������ ü���� �ణ ȸ���� �� �ִ�.\n";
				break;
			case AMT_OCCULT:
				text_ += "���������� ��üȭ�ϴ� ���� ���� ����Ʈ���� ���� ��� ����.\n";
				text_ += "�����ϰ� ������ ����Ʈ�� ����� ����ϰ� ������ ������ ����Ʈ�� ���� �����Ѵ�.\n";
				text_ += "100%���¿��� v�� ������ �þ߳��� ��� �������� ��ȯ���� �߹��ϸ�\n";
				text_ += "�����ȿ� �����ִ� ����Ʈ�� ���� �䱫�μ� ����ȭ�Ѵ�.\n";
				break;
			default:
				text_ += "�� ���� ������ �ڵ� ���� ȿ���� ����.\n";
				break;
			}
		}
		else
		{
			text_ += "�� ������ ���� ���� ���� ������ �ִ��� ���� �� �� �� ����.\n";
			text_ += "�����ϸ� ���� ���� ����� �ִ��� �� �� ���� �� ����.\n";
		}		

		if (can_use_)
		{
			if (you.equipment[ET_NECK] != it)
			{
				use_text_ += "(w)����, ";
				if (key) key->insert('w');
			}
			else
			{
				use_text_ += "(u)����, ";
				if (key) key->insert('u');
			}
		}
	}
	break;
	case ITM_RING:
	{
		if (iden_list.ring_list[it->value1].iden == 2)
		{
			switch (it->value1)
			{
			case RGT_STR:
				text_ += "�տ� �� �������� �ٷ��� ��ȭ��Ű�ų� ��ȭ��Ű�� ���� ����.\n";
				text_ += "�� �������� ������ ��ġ�� �޷��ִ�.\n";
				break;
			case RGT_DEX:
				text_ += "�տ� �� �������� ��ø���� ��ȭ��Ű�ų� ��ȭ��Ű�� ��ø�� ����.\n";
				text_ += "�� �������� ������ ��ġ�� �޷��ִ�.\n";
				break;
			case RGT_INT:
				text_ += "�տ� �� �������� ������ ��ȭ��Ű�ų� ��ȭ��Ű�� ������ ����.\n";
				text_ += "�� �������� ������ ��ġ�� �޷��ִ�.\n";
				break;
			case RGT_HUNGRY:
				text_ += "������ ���� �ڿ����� P�� �Ҹ� ������ �Ǵ� ������� ����.\n";
				break;
			case RGT_FULL:
				text_ += "�̳븮�ڴ��� �ູ�� ����ִ� ������ ������ �ڰ� �������� ������ �ȴ�.\n";
				text_ += "������簡 �������� �����ڴ� �ڿ����� P�� �Ҹ� �������� �ȴ�.\n";
				text_ += "�����̳� ������¿����� P�Ҹ� ���ӵ� �ٿ��ش�.\n";
				break;
			case RGT_TELEPORT:
				text_ += "�����ڿ��� �����̵��� �ɷ��� �ο��ϴ� ����.\n";
				text_ += "�� ���ۿ����� ���� �ִ� ���� �������� �����̵��� ������ �߻��ϰԵȴ�.\n";
				break;
			case RGT_POISON_RESIS:
				text_ += "���� ���� ������ ��� ����. ���� ��� ���� ������ �����.\n";
				break;
			case RGT_FIRE_RESIS:
				text_ += "ȭ���� ���� ������ ��� ����. �� 3�ܰ���� ��ø������ ���� �� �ִ�.\n";
				break;
			case RGT_ICE_RESIS:
				text_ += "�ñ⿡ ���� ������ ��� ����. �� 3�ܰ���� ��ø������ ���� �� �ִ�.\n";
				break;
			case RGT_SEE_INVISIBLE:
				text_ += "�����ϰ� ������ ������ ���� �� �� �ְ� �ȴ�.\n";
				break;
				/*case RGT_GRAZE:
					text_ += "�׷���� ����� �� �ִ� ����. �����ϸ� �ɷ»�뿡�� �׷�����ߵ��� �����.\n";
					text_ += "�׷�������¿����� ��� ���Ÿ� ������ ����Ȯ���� ���� �� �ְ� �ȴ�.\n";
					text_ += "��뿡�� �ߵ���ų�� �ʿ��ϸ� P�� �ణ �Ҹ�ȴ�.\n";
					break;*/
			case RGT_LEVITATION:
				text_ += "������ ����� �� �ִ� ����. �����ϸ� �ɷ»�뿡�� ����ߵ��� �����.\n";
				text_ += "������¿����� ������������ �ǳ� �� �ְԵȴ�.\n";
				text_ += "��뿡�� �ߵ���ų�� �ʿ��ϸ� P�� �ణ �Ҹ�ȴ�.\n";
				break;
			case RGT_INVISIBLE:
				text_ += "������ ����� �� �ִ� ����. �����ϸ� �ɷ»�뿡�� ����ߵ��� �����.\n";
				text_ += "������¿����� ������ ��ų Ȯ���� �ſ� �������� �ȴ�.\n";
				text_ += "������¿����� P�� �Ҹ��� ���ӵǴ� ������ �ִ�.\n";
				text_ += "��뿡�� �ߵ���ų�� �ʿ��ϸ� P�� �ణ �Ҹ�ȴ�.\n";
				break;
			case RGT_MANA:
				text_ += "����� �ִ븶���� �����ϴ� ����.\n";
				text_ += "���������� ������� ���ƿ´�.\n";
				break;
			case RGT_MAGACIAN:
				text_ += "����� ������������ �����Ŀ��� ��½�Ű�� ����.\n";
				break;
			case RGT_AC:
				text_ += "����� �� �����ϴ� ����.\n";
				text_ += "������ �Ǵ� ��ġ�� ������ ������ ���ڿ� ����.\n";
				break;
			case RGT_EV:
				text_ += "����� ȸ�ǰ� �����ϴ� ����.\n";
				text_ += "���� �Ǵ� ��ġ�� ������ ������ ���ڿ� ����.\n";
				break;
			case RGT_CONFUSE_RESIS:
				text_ += "����� ȥ���� ���⿡ ������ ����� ����.\n";
				break;
			case RGT_ELEC_RESIS:
				text_ += "����� ���������� �ö󰡴� ����.\n";
				text_ += "�Ϻ��ϰ� �������� ������ ����� �������� �ٿ��ش�.\n";
				break;
			case RGT_MAGIC_RESIS:
				text_ += "����� ���������� �ö󰡴� ����.\n";
				text_ += "���������� �������� �ٿ����� �������� ��������� �������κ��� ��ȣ���ش�.\n";
				break;
			default:
				text_ += "������ ���� ��� ������.\n";
				break;
			}
		}
		else
		{
			text_ += "������ ���� ����ִ� ����.\n";
			text_ += "����� �ٷ� �� ���� �� �� �ִ� ������ �ִ� �ݸ�. ��ġä�� ���� ������ �ִ�.\n";
		}
		if (can_use_)
		{
			if (you.equipment[ET_RIGHT] != it && you.equipment[ET_LEFT] != it)
			{
				use_text_ += "(w)����, ";
				if (key) key->insert('w');
			}
			else
			{
				use_text_ += "(u)����, ";
				if (key) key->insert('u');
			}
		}
	}
	break;
	case ITM_BOOK:
	{

		text_ += GetBookInfor((book_list)it->value0);
		text_ += "\n\n";
		if (it->identify)
		{
			char temp[100], sp_char = 'a';
			sprintf_s(temp,100, "%-34s%-30s%s\n", "�����̸�", "����", "����");
			text_ += temp;
			for (int i = 0; i < 8; i++)
			{
				spell_list spell_;
				if ((spell_ = (spell_list)it->GetValue(i + 1)) != SPL_NONE)
				{
					sprintf_s(temp,100, "%c - %-30s%-30s%d\n", sp_char++, SpellString(spell_), GetSpellSchoolString(spell_).c_str(), SpellLevel(spell_));
					text_ += temp;
				}
			}
		}
	}
	break;
	case ITM_MISCELLANEOUS:
	{
		switch (it->value1)
		{
		case EVK_PAGODA:
			text_ += "�������� �Ҿ���� ��ž. ������ ���� ����ִ�.\n";
			text_ += "�ߵ��ϰԵǸ� �ȿ� ���ִ� ���� �������� ���·� �߻�ȴ�.\n";
			text_ += "�ߵ� ��ų�� �������� �������� ��������.\n";
			break;
		case EVK_AIR_SCROLL:
			text_ += "����� �������� ���� �ִ� ����. ������ ���� ��� �ִ�.\n";
			text_ += "�ߵ��ϰԵǸ� �Ŀ��� �밡�� ������� ������ ���İ��� ȸ�������ش�.\n";
			text_ += "�ߵ� ��ų�� �������� ȸ���Ǵ� ������ ��������.\n";
			break;
		case EVK_DREAM_SOUL:
			text_ += "���� ���迡�� �ظް��ִ� ��ȥ�̴�.\n";
			text_ += "����ϸ� ���� ����κ��� ȯ���� ��üȭ�� ��õ��� �����ϴ�.\n";
			text_ += "����� ������ �ִ� ���� �������� �Ʊ��� �Ǿ� ��ȯ�ȴ�.\n";
			text_ += "�ߵ� ��ų�� �������� ���� ���� �Ʊ��� ��ȯ�ȴ�.\n";
			break;
		case EVK_BOMB:
			text_ += "���� �Ŵ��� ��ź. ������ ������ ��ȭ�� �����ϴ�.\n";
			text_ += "�ߵ��ϰԵǸ� ��ź�� ��ȭ�Ǿ� ��ǥ�������� ���� �� �ִ�.\n";
			text_ += "���� ��ź�� �ٷ� ������������ �� ���� ������ ū ������ �Ͼ��.\n";
			text_ += "��ź�� �� ĭ�� �����ϸ� ���� ���� �ı��Ǹ� ���������ʰ� �ı��Ǿ������.\n";
			text_ += "�ߵ����̹Ƿ� ����ص� �Ҹ�����ʴ´�. �ź��� ������ ���� �ۿ��ϴ� �� ����.\n";
			text_ += "�ߵ� ��ų�� �������� �������� ��ź�� ü���� ��������.\n";
			break;
		case EVK_GHOST_BALL:
			text_ += "������� ��Ҹ� ���ٴѴٴ� ������ �ϳ��� ������ ���ٴѴٴ� ����̴�.\n";
			text_ += "�ߵ��Ͽ� �տ� ��� �ƹ����Ե� �������ʰ� ���ݴ������ʴ� ����ȭ���°� �ȴ�.\n";
			text_ += "�ߵ��� �ڽ��� ���� ü���� 30%~70%���� ���ҵǰ� �ߵ��ȴ�.\n";
			text_ += "�ߵ��߿� �������Ե� ������ �޴� ������������ ü���� ȸ�������ʰ� �Ŀ��� ������ ��������.\n";
			text_ += "�ѹ� �� �ߵ��ؼ� �����ϰų� �Ŀ��� 0�̵Ǹ� �ڵ����� ����ȴ�.\n";
			text_ += "����ȭ���¿��� �̵��� �����Ͽ� ������, ����, ���ݵ��� ��� �ൿ�� �Ұ����ϴ�.\n";
			text_ += "���� ����� � ������ �Ŀ��� �������� �ʴ´ٸ� ������ģ�� �ٸ� ���𰡸� ��� ������ ���̴�.\n";
			text_ += "�ߵ� ��ų�� �������� �ߵ��� ���ҵǴ� ü�°� �ߵ��� �������� �Ŀ��Ҹ� ��������.\n";
			break;
		case EVK_SKY_TORPEDO:
			text_ += "ı�İ� ���ۿ����� �� �� �ֵ��� ������ ���.\n";
			text_ += "�� �����غ��� �̻��ϰ� ���� �ٸ��� ����.\n";
			text_ += "�ߵ� ��ų�� �������� �������� ��������.\n";
			break;
		case EVK_MAGIC_HAMMER:
			text_ += "�������� �ٷ�ٰ� �ϴ� �����ġ. ���� ������ ���϶�� �Ѵ�.\n";
			text_ += "����ϸ� �Ƿ� ��û�� ȿ������ ���ϴ´�� �Ŀ� 1ĭ������ ����� �� �ְ� �ȴ�.\n";
			text_ += "��, �����ġ�� ����ϴ°��� ū ����δ��� �����ԵǸ� ����ڸ� �ڸ��Ų�ٰ� �Ѵ�.\n";
			text_ += "�����ġ�� ���� 10%�� Ȯ���� ���ݴ��� ȿ���� ���ֵ� ���ɼ��� �ִ�.\n";
			break;
		default:
			text_ += "���׸� ���� �ߵ����̴�.\n";
			break;
		}
		text_ += "\n\n";
		text_ += "�� ���� Ƚ�����Ѿ��� �ߵ��� ������ ���̴�. ����� �ߵ���ų�� ����ؼ� �������� �����ȴ�.\n";
		text_ += "VŰ�� �Ŀ��� �Ҹ��Ͽ� �ߵ��� �� �ִ�.\n\n";
		char temp[100];
		sprintf_s(temp,100, "�� �ߵ����� ����Ҷ����� �ʿ��� �Ŀ�: %d.%02d\n", Evokeusepower((evoke_kind)it->value1, true) / 100, Evokeusepower((evoke_kind)it->value1, true) % 100);
		text_ += temp;

		if (can_use_)
		{
			use_text_ += "(v)�ߵ�, ";
			if (key) key->insert('v');
		}
	}
	break;

	case ITM_GOAL:
		text_ += "�̰��� ���� ������ ������ ������ ���̴�. \n";
		text_ += "3���� ������ �ֽɺ� ������ �Ż��� ���� �� �� �ִ�.\n";
		break;
	case ITM_ORB:
		text_ += "�̰��� ������ ���� ���� ������̴�. �Ż� ���ο� �����ϰ� ����� �ִ�.\n";
		text_ += "�� ���� ������ Ż���ϸ� �� �̺��� �����ų� ��û�� ���� ���� �� ���� �� ����.\n";
		text_ += "��� ����ϴ����� ����� �����̴�! �׷��� Ż���Ҷ����� ���� �ƴϹǷ� �����ϱ�!\n";
		text_ += "Ư�� �Ż��� ȫ���� ���డ ���� ���� Ű�� ����� �Ѿƿ� ���̴�.\n";
		break;
	case ITM_ETC:
		switch (it->value1)
		{
		case EIT_SATORI:
			if (you.god_value[GT_SATORI][0] == 1)
			{
				text_ += "\"�Ҿ���� �ֿϵ����� ã���ϴ�. - �ڸ����� ���丮\"��� �����ִ� ���̴�.\n";
				text_ += "����� ������ �پ��ִ�...\n";
			}
			else
			{
				text_ += "\"�Ҿ���� ������ ã���ϴ�. - �ڸ����� ���丮\"��� �����ִ� ���̴�.\n";
			}
			break;
		case EIT_CAT_TREE:
			text_ += "���ٷ� ������. �׷��� ���������ʾƺ������� ����̰����� ���� �� �ߴµ��ϴ�.\n";
			break;
		case EIT_BROKEN_CAMERA:
			text_ += "�μ����ִ� �ٱ��� ī�޶��. �ƹ����� ı�ĵ��� ������ ���� �����ϰ� �ִ� �� �ϴ�.\n";
			text_ += "���ϰ� �μ����ֱ⶧���� ���ӻ��� ���� ����δ�.\n";
			break;
		case EIT_KAPPA_TRASH:
			text_ += "ı�ĵ��� ���� ���� ���� �������̴�. ���ӻ��� ���� �� ����.\n";
			break;
		}
		break;
	default:
		text_ += "�������̴�. �����ڿ��� �Ű�����.\n";
		break;
	}

	if (can_use_)
	{
		if (it->type == ITM_BOOK)
		{
			use_text_ += "(D)������";
			if (key) key->insert('D');
		}
		else
		{
			use_text_ += "(d)������";
			if (key) key->insert('d');
		}
	}



	if(it->isArtifact() && it->identify)
	{
		text_ += "\n\n";
		for(auto it2 = it->atifact_vector.begin(); it2 != it->atifact_vector.end(); it2++)
		{
			text_ += GetAtifactInfor((ring_type)it2->kind, it2->value);
			text_ += "\n";
		}
	}


	text_ += "\n\n\n";
	text_ += use_text_;
	//char temp[100];
	//if(!it->is_pile || it->num == 1)
	//	sprintf_s(temp, 100,"\n\n\n���� : %g\n",it->weight);
	//else
	//	sprintf_s(temp, 100,"\n\n\n���� : %g * %d\n",it->weight/it->num,it->num);
	//text_ += temp;
	return text_;

}