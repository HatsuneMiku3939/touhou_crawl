//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: bamboo.cpp
//
// ����: �̱��� �׸��� ( ��� )
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "map.h"
#include "throw.h"
#include "enum.h"
#include "event.h"
#include "smoke.h"
#include "floor.h"
#include "rect.h"
#include "mon_infor.h"

extern HANDLE mutx;

void map_algorithms_bamboo(int num);
void bamboo_count(int num);




void map_algorithms_bamboo(int num, dungeon_tile_type floor_tex, dungeon_tile_type wall_tex)
{
	int d_x = 10, d_y = 10;
	for(int x = 0; x<DG_MAX_X; x++)
	{	
		for(int y=0; y<DG_MAX_Y; y++)
		{
			if(randA(10)>1)
			{
				env[num].dgtile[x][y].tile = floor_tex;
			}
			else 
				env[num].dgtile[x][y].tile = wall_tex;
		}
	}
	int x_ = DG_MAX_X/2;
	int y_ = DG_MAX_Y/2;

	env[num].stair_up[0].x = x_;
	env[num].stair_up[0].y = y_;
	env[num].dgtile[x_][y_].tile = floor_tex;


	env[num].ClearEvent();
	env[num].MakeEvent(EVL_BAMBOO,coord_def(x_,y_),EVT_ALWAYS);
	env[num].MakeEvent(23,coord_def(x_,y_),EVT_SIGHT);

	map_list.bamboo_count=0;
	map_list.bamboo_rate = 0;
}




void bamboo_count(int num)
{ //�÷��̾ ���� ����Ű����� �ٷ� �߾����� ����´�.
	int offset_x=0, offset_y=0;
	if(you.position.x<8 || you.position.x>DG_MAX_X-9)
		offset_x = DG_MAX_X/2-you.position.x;
	if(you.position.y<8 || you.position.y>DG_MAX_Y-9)
		offset_y = DG_MAX_Y/2-you.position.y;

	if(offset_x || offset_y) //���� ���
	{
		WaitForSingleObject(mutx, INFINITE);
		//���������Ұ�. ��Ÿ��, ������ġ, ������Ʈ��ġ, ���� Ÿ����?
		dungeon_tile tempdgtile[DG_MAX_X][DG_MAX_Y];
		for(int i = 0; i < DG_MAX_X; i++)
		{
			for(int j = 0; j < DG_MAX_Y; j++)
			{
				tempdgtile[i][j] = env[num].dgtile[i][j];
			}
		}


		
		for(int i = 0; i < DG_MAX_X; i++)
		{
			for(int j = 0; j < DG_MAX_Y; j++)
			{
				if(offset_x  > i || offset_x  <= i - DG_MAX_X  || offset_y  > j || offset_y  <= j - DG_MAX_Y )
				{  //���� �������ϴ� ��	
					if(randA(18000 - 15*min(map_list.bamboo_count,1100))<(map_list.bamboo_tewi?2:1))
					{
						env[num].dgtile[i][j].init();
						env[num].dgtile[i][j].tile = DG_EIENTEI_STAIR;

					}
					else if(randA(map_list.bamboo_tewi?2000:4000)<1)
					{
						env[num].dgtile[i][j].init();
						env[num].dgtile[i][j].tile = DG_RETURN_STAIR;
						//map_list.bamboo_count;
					}
					else if(randA(10)>1)
					{
						env[num].dgtile[i][j].init();
						env[num].dgtile[i][j].tile = DG_GRASS;
					}
					else 
					{
						env[num].dgtile[i][j].init();
						env[num].dgtile[i][j].tile = DG_BAMBOO_WALL;
					}
				}
				else
				{ //���� ���� �����δ�.
					int x_ = i - offset_x, y_ = j - offset_y;

					if(x_ >= 0 && x_ < DG_MAX_X && y_ >= 0 && y_ < DG_MAX_Y )
						env[num].dgtile[i][j] = tempdgtile[x_][y_];
					else
					{						
						env[num].dgtile[i][j].init();
						env[num].dgtile[i][j].tile = DG_SEA; //�����ؼ��ȵ�(�����)
					}
				}
			}
		}

		//�������� �Ű��� ������ �°� ������Ʈ���� ���� �̵���Ų��.

		//�÷��̾�
		you.offsetmove(coord_def(offset_x,offset_y));
		//����
		for(vector<monster>::iterator it = env[num].mon_vector.begin() ; it != env[num].mon_vector.end() ; it++)
		{
			if((*it).isLive())
			{
				if((*it).offsetmove(coord_def(offset_x,offset_y)) == false)
				{
					if(it->id == MON_TEWI)
					{
						unset_exist_named(MON_TEWI);
					}
				}
			}
		}
		//�Ȱ�
		for(list<smoke>::iterator it = env[num].smoke_list.begin();it != env[num].smoke_list.end() ;it++)
		{
			(*it).offsetmove(coord_def(offset_x,offset_y));
		}
		//������� �����ʴ´�.
		env[num].ClearAllShadow();
		//������		(������ ����� ������ �ȴ�.)
		for(list<item>::iterator it =  env[num].item_list.begin();it !=  env[num].item_list.end() ;)
		{
			item *temp = &(*it);
			it++;
			temp->offsetmove(coord_def(offset_x,offset_y));
		}
		//����Ʈ		�ʿ����
		env[num].ClearEffect();
		//��ȿ��		
		for(list<floor_effect>::iterator it = env[num].floor_list.begin() ; it != env[num].floor_list.end() ; it++)
		{
			(*it).offsetmove(coord_def(offset_x,offset_y));
		}
		//�̺�Ʈ��... �ʿ����?
		//list<events> event_list;

		env[num].allCalculateAutoTile();
		ReleaseMutex(mutx);

	}

	if(randA(500)<1)
	{
		
		if(!is_exist_named(MON_TEWI)){
			dif_rect_iterator rit(you.position,12,true);
			while(!rit.end())
			{
				coord_def check_pos_ = (*rit);

				if(env[num].isMove(check_pos_.x, check_pos_.y, false) && !env[num].isInSight(check_pos_))
				{
					monster *temp = env[num].AddMonster(MON_TEWI,0,coord_def(DG_MAX_X/2,DG_MAX_Y/2));
					temp->state.SetState(MS_NORMAL);
					set_exist_named(MON_TEWI);
					break;
				}
				rit++;
			}
		}
	}

	if(randA(1000)<map_list.bamboo_rate)
	{ //���͸� �����ϱ�����Ѵ�.
		
		random_extraction<int> percent_;
		percent_.push(MON_RABIT_BOMB,5+max(map_list.bamboo_count/50-10,0));//�Ĺֹ��� ��ź���� ���� ���� ��������

		if(map_list.bamboo_rate<=200)
		{
			percent_.push(MON_RABIT_SPEAR,60);//â��
			percent_.push(MON_RABIT_SUPPORT,15);//������
			percent_.push(MON_RABIT_MAGIC,20);//������
		}
		else
		{ //�䳢���� �������� �������� ������
			percent_.push(MON_RABIT_SPEAR,65);//â��
			percent_.push(MON_RABIT_SUPPORT,5);//������
			percent_.push(MON_RABIT_MAGIC,25);//������

		}
		int id_ = percent_.pop();


		dif_rect_iterator rit(you.position,12,true);
		while(!rit.end())
		{
			coord_def check_pos_ = (*rit);

			if(env[num].isMove(check_pos_.x, check_pos_.y, false) && !env[num].isInSight(check_pos_))
			{
				monster *temp = env[num].AddMonster(id_,0,*rit);
				if(id_ == MON_RABIT_BOMB)
				{
					int level_up_ = min(max(map_list.bamboo_count/300-2,0),10);
					temp->LevelUpdown(level_up_);
				}
				temp->state.SetState(MS_NORMAL);
				break;
			}
			rit++;
		}


	}



	map_list.bamboo_count++;
	if(map_list.bamboo_count % 120 == 20)
	{
		int grade_ = min(map_list.bamboo_count/20,200); //�ð��� �带���� ���� �׸��� �ż�����
		map_list.bamboo_rate = rand_int(60,120)+grade_;

	}
	

}