//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: mon_infor.h
//
// ����: ������ ������
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __MON_INFOR_H__
#define  __MON_INFOR_H__

#include "texture.h"
#include "monster_texture.h"
#include "unit.h"

struct mon_infor
{
	int id;
	int level;
	int exper;
	name_infor name;
	textures *image;
	int max_hp;
	int ac;
	int ev;
	int atk[3];
	attack_type atk_type[3];
	name_infor atk_name[3];
	int flag;
	int resist;
	int sense;
	int speed;
	char dot;
};


enum monster_flag
{
	M_FLAG_OPEN_DOOR = 1<<0, //���� �� �� �ִ°�?
	M_FLAG_FAIRY = 1<<1, //�����ΰ�?
	M_FLAG_UNIQUE  = 1<<2, //���ӵ��ΰ�?
	M_FLAG_FLY = 1<<3, //���°�?
	M_FLAG_NO_ATK = 1<<4, //������ ���� �ʴ°�?
	M_FLAG_CONFUSE = 1<<5, //�׻� ȥ�������ΰ�?
	M_FLAG_SUMMON = 1<<6, //��ȯ�Ǿ���?
	M_FLAG_SPEAK = 1<<7, //���ϴ°�?
	M_FLAG_ALLY = 1<<8, //�����ΰ�?
	M_FLAG_SWIM = 1<<9, //������ �����Ѱ�?
	M_FLAG_CAN_SEE_INVI = 1<<10, //������ �� �� �ִ°�?
	M_FLAG_CANT_GROUND = 1<<11, //���� ���ö���°�?
	M_FLAG_EVENT = 1<<12, //�̺�Ʈ�� ����.(�����ڸ��� ���ΰ��� Ÿ��)
	M_FLAG_LEADER_SUMMON = 1<<13, //������ ��ȯ�� �ֺ��� �⵷��
	M_FLAG_PASSED_ALLY = 1<<14, //�Ʊ��� ���Ÿ� ������ �기��.
	M_FLAG_PASSED_ENEMY = 1<<15, //������ ���Ÿ� ������ �기��.
	M_FLAG_NONE_MOVE = 1<<16, //�������� �ʴ´�.
	M_FLAG_UNHARM = 1<<17, //�����Ѱ�?
	M_FLAG_INVISIBLE = 1<<18, //���� ����
	M_FLAG_ANIMAL = 1<<19, //����
	M_FLAG_NETURALY = 1<<20,  //�߸�. �׷��� ����ũ�Ѱ��� �ణ �ٸ���. �÷��̾�� �������̳� ������ �ο�
	M_FLAG_NONE_STAIR = 1<<21,
	M_FLAG_CANT_NETURAL = 1<<22, //�ڿ������� �����ɼ� ����. �Ʒ������� ���� �� ���� ��
	M_FLAG_INANIMATE = 1<<23, //������
	M_FLAG_NO_STATE = 1<<24, //���� ǥ�� �ȵ�
	M_FLAG_SILENCE = 1 << 25, //ħ���� �鿪�̴�.
	M_FLAG_SHIELD = 1 << 26, //������ ��Ų��.
	M_FLAG_RESIST_BLIZARD = 1 << 27
};


enum getMonsterFromFloor_flag
{
	GMFF_FLAG_ALL = 0,
	GMFF_FLAG_ONLY_WEAK,
	GMFF_FLAG_ONLY_STRONG,
	GMFF_FLAG_ONLY_MIDDLE
};

extern const mon_infor mondata[];


bool is_exist_named(monster_index id); //�ش� ���ӵ尡 ����Ȯ���Ǿ��ִ���
void set_exist_named(monster_index id); //���ӵ带 ����Ȯ��(��Ʈ������)
void unset_exist_named(monster_index id);

void create_mon(int floor, int num_);
void init_monster(); 
int getMonsterFromSpecial(int type_, getMonsterFromFloor_flag power_);
int getMonsterFromFloor(int level_, getMonsterFromFloor_flag power_);

struct unique_infor
{
	int id;
	int level;
	unique_infor(int id_=0,int level_=0):id(id_),level(level_){};
};

extern vector<unique_infor> unique_list;
void SetResistMonster(monster* mon);

string GetMonsterInfor(monster *it);

#endif // __MON_INFOR_H__