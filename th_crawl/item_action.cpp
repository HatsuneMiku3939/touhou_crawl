//////////////////////////////////////////////////////////////////////////////////////////////////
//
// 파일이름: item_action.cpp
//
// 내용: player의 행동들(아이템 관련 행동들)
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "environment.h"
#include "display.h"
#include "key.h"
#include "player.h"
#include "beam.h"
#include "skill_use.h"
#include "monster_texture.h"
#include "spellcard.h"

extern HANDLE mutx;
string GetItemInfor(item *it);


void PickUp()
{	
	if(you.s_levitation)
	{
		printlog("당신은 땅에 손이 닿지 않는다.",true,false,false,CL_normal);
		return;
	}
	int num=0;
	list<item>::iterator it, first_it;
	for(it = env[current_level].item_list.begin();it != env[current_level].item_list.end();)
	{
		list<item>::iterator temp = it++;
		if((*temp).position.x == you.position.x && (*temp).position.y == you.position.y)
		{
			if(isPick(&(*temp)))
			{
				if(!num++)
					first_it = temp;
			}
		}
		else if(num)
			break;
	}
	if(num)
	{
		if(num==1)
			PickUpNum(first_it,1);
		else
			PickUpSelect(first_it,num);

	}
}



void PickUpAll(list<item>::iterator it)
{	
	for(;it != env[current_level].item_list.end();)
	{
		list<item>::iterator temp = it++;
		if((*temp).position.x == you.position.x && (*temp).position.y == you.position.y)
		{
			if(isPick(&(*temp)))
			{
				if(you.additem(&(*temp)))
				{
					env[current_level].DeleteItem(temp);
					you.time_delay += you.GetNormalDelay();
					you.TurnEnd();
				}
			}
		}
	}
}
void PickUpSelect(list<item>::iterator it, int num)
{	
	for(;it != env[current_level].item_list.end() && num;num--)
	{
		list<item>::iterator temp = it++;
		if((*temp).position.x == you.position.x && (*temp).position.y == you.position.y)
		{
			if(isPick(&(*temp)))
			{
				printlog((*temp).GetName(),false,false,false,(*temp).item_color());
				printlog("을 줍습니까? (예:y 아니오:n 모두:a 선택:*?g,)",true,false,false,CL_help);
				switch(waitkeyinput())
				{
				case 'y':
				case 'Y':
					if(you.additem(&(*temp)))
					{
						env[current_level].DeleteItem(temp);
						you.time_delay+=you.GetNormalDelay();
						you.TurnEnd();
					}
					break;
				case 'a':
					PickUpNum(temp,num);
					return;
				case '*':
				case '?':
				case 'g':
				case ',':
					iteminfor_pick();
					return;
				case 'o':
					//자동탐색을 넣는다.
					break;
				}
			}
		}
	}
}
void PickUpNum(list<item>::iterator it, int num)
{
	while(num>0)
	{
		list<item>::iterator temp = it;
		if(num>1) it++;
		if(isPick(&(*temp)))
		{
			if(you.additem(&(*temp)))
			{
				env[current_level].DeleteItem(temp);
				you.time_delay+=you.GetNormalDelay();
				you.TurnEnd();
			}
			else
				return;
			num--;
		}
	}
}

int isPick(const item* t)
{
	return 1;
}




void iteminfor_pick()
{
	view_item(IVT_PICK,"무슨 아이템을 줍겠습니까?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			CheckKey(key_);
		}
		else if(key_ == VK_DOWN)//-----이동키-------
		{
			changemove(32);  //위
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //아래
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-WindowHeight);
		}
		else if(key_ == VK_NEXT)
		{
			changemove(WindowHeight);
		}						//-----이동키끝-------
		else if( key_ == ',' )
		{
			AllCheckKey();
		}
		else if(key_ == VK_RETURN)
		{
			changedisplay(DT_GAME);
			list<item>::iterator it = env[current_level].GetPositiontoitem(you.position);
			list<item>::iterator end = env[current_level].GetPositiontoitemend(you.position);
			for(;it != end;)
			{
				list<item>::iterator temp = it++;
				if(GetItemofKey(temp,end))
				{	
					if(you.additem(&(*temp)))
					{
						env[current_level].DeleteItem(temp);
						you.time_delay+=you.GetNormalDelay();
						you.TurnEnd();
					}
					else
						break;
				}
			}
			break;
		}
		else if(key_ == VK_ESCAPE)
			break;

	}
	changedisplay(DT_GAME);
}



void iteminfor_discard()
{
	int i=0;
	view_item(IVT_DISCARD,"무슨 아이템을 버리겠습니까?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			CheckKey(key_,i);
		}
		else if(key_ == VK_DOWN)//-----이동키-------
		{
			changemove(32);  //위
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //아래
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-WindowHeight);
		}
		else if(key_ == VK_NEXT)
		{
			changemove(WindowHeight);
		}						//-----이동키끝-------
		else if((key_ >= '0' && key_ <= '9'))
		{
			i= i*10+key_-'0';
		}
		else if(key_ == VK_RETURN)
		{
			list<item>::iterator it = you.item_list.begin();
			list<item>::iterator end = you.item_list.end();
			for(;it != end;)
			{
				list<item>::iterator temp = it++;
				if(GetItemofKey(temp,end))
				{	
					if(you.possibleunequip(temp))
					{
						int number = GetItemofNum(temp,end);
						item *temp2 = env[current_level].AddItem(you.position,&(*temp),number);	
						temp2->drop = true;
						printlog("당신은 ",false,false,false,CL_normal);					
						printlog(temp2->GetName(number),false,false,false,temp2->item_color());				
						printlog(temp2->GetNameInfor().name_to(true),false,false,false,CL_normal);					
						printlog("내려놓았다.",true,false,false,CL_normal);	
						you.DeleteItem(temp,number);
						changedisplay(DT_GAME);
						you.time_delay+=you.GetNormalDelay();
						you.TurnEnd();
					}
					else
						break;
				}
			}
			break;
		}
		else if(key_ == VK_ESCAPE)
			break;

	}
	changedisplay(DT_GAME);
}


void Eatting()
{
	if(you.power >= 500 && !(you.god == GT_MINORIKO))
	{
		printlog("당신은 이미 풀파워다!",true,false,false,CL_normal);
		return;
	}
	view_item(IVT_FOOD,"무엇을 먹겠습니까?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			changedisplay(DT_GAME);
			you.Eat(key_);
			break;
		}
		else if(key_ == VK_DOWN)//-----이동키-------
		{
			changemove(32);  //위
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //아래
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-WindowHeight);
		}
		else if(key_ == VK_NEXT)
		{
			changemove(WindowHeight);
		}						//-----이동키끝-------
		else if(key_ == '*')
			view_item(IVT_SELECT,"무엇을 먹겠습니까?");
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}


void Drinking()
{
	view_item(IVT_POTION,"무엇을 마시겠습니까?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			if(you.Drink(key_))
			{			
				you.time_delay += you.GetNormalDelay();
				changedisplay(DT_GAME);
				if(you.god == GT_EIRIN)
				{
					if(randA(1))
					{
						you.PietyUpDown(1);
						you.GiftCount(1);
					}
				}
				you.TurnEnd();
			}
			break;
		}
		else if(key_ == VK_DOWN)//-----이동키-------
		{
			changemove(32);  //위
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //아래
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-WindowHeight);
		}
		else if(key_ == VK_NEXT)
		{
			changemove(WindowHeight);
		}						//-----이동키끝-------
		else if(key_ == '*')
			view_item(IVT_SELECT,"무엇을 마시겠습니까?");
		else if(key_ == VK_ESCAPE)
		{
			break;
		}
	}
	changedisplay(DT_GAME);
}

//void Spelllcard_Declare()
//{
//	if(!you.equipment[ET_NECK])
//	{
//		printlog("스펠카드를 장착하고 있지 않다.",true,false,false,CL_normal);
//		return;
//	}
//	if(you.GetSpellcard())
//	{
//		printlog("이미 선언 중이다.",true,false,false,CL_normal);
//		return;
//	}
//	if(declare_spellcard((spellcard_declare_type)you.equipment[ET_NECK]->value1, 20+you.level*5)){
//		int turn_ = spellcard_turn((spellcard_declare_type)you.equipment[ET_NECK]->value1, (spellcard_evoke_type)you.equipment[ET_NECK]->value2, (spellcard_passive_type)you.equipment[ET_NECK]->value3);
//		you.SetSpellcard(turn_);
//		passive_spellcard((spellcard_passive_type)you.equipment[ET_NECK]->value3, you.equipment[ET_NECK]->value4, 1, turn_-1);
//	}
//}

void Spelllcard_Evoke()
{
	int i=0;
	view_item(IVT_SPELLCARD,"무슨 아이템을 발동하시겠습니까?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			changedisplay(DT_GAME);
			if(you.Evoke(key_))
			{
				you.time_delay += you.GetNormalDelay();
				you.TurnEnd();
			}
			break;
		//	CheckKey(key_,i);
		}
		else if(key_ == VK_DOWN)//-----이동키-------
		{
			changemove(32);  //위
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //아래
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-WindowHeight);
		}
		else if(key_ == VK_NEXT)
		{
			changemove(WindowHeight);
		}						//-----이동키끝-------
		else if(key_ == '*')
			view_item(IVT_SELECT,"무엇을 발동하시겠습니까?");
		else if(key_ == VK_ESCAPE)
		{
			break;
		}
	}
	changedisplay(DT_GAME);
}
void Reading()
{
	if(env[current_level].isSilence(you.position))
	{
		printlog("당신은 소리를 낼 수 없다.",true,false,false,CL_normal);
		return;
	}
	view_item(IVT_SCROLL,"무엇을 읽겠습니까?");
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			item* item_ = you.GetItem(key_);
			if(!item_)
				continue;
			if(item_->type == ITM_BOOK)
			{
				if(item_->value0>=0)	
				{
					iden_list.books_list[item_->value0] = true;
					item_->identify = true;
				}
				while(1)
				{
					WaitForSingleObject(mutx, INFINITE);
					SetText() = GetItemInfor(item_);
					ReleaseMutex(mutx);
					changedisplay(DT_TEXT);
					int key_ = waitkeyinput(true);
					if( (key_ >= 'a' && key_ <= 'f'))
					{
						if(int spell_ = item_->GetValue(key_ - 'a'+1))
						{	
							WaitForSingleObject(mutx, INFINITE);
							SetText() = GetSpellInfor((spell_list)spell_);
							ReleaseMutex(mutx);
							waitkeyinput();
							continue;
						}	
					}
					view_item(IVT_SCROLL,"무엇을 읽겠습니까?");
					break;
				}
			}
			else if(item_->type == ITM_SCROLL && you.Read(key_))
			{
				you.time_delay += you.GetNormalDelay();
				changedisplay(DT_GAME);
				you.TurnEnd();
			}
			break;
		}
		else if(key_ == VK_DOWN)//-----이동키-------
		{
			changemove(32);  //위
		}
		else if(key_ == VK_UP)
		{
			changemove(-32); //아래
		}
		else if(key_ == VK_PRIOR)
		{
			changemove(-WindowHeight);
		}
		else if(key_ == VK_NEXT)
		{
			changemove(WindowHeight);
		}						//-----이동키끝-------
		else if(key_ == '*')
			view_item(IVT_SELECT,"무엇을 읽겠습니까?");
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}