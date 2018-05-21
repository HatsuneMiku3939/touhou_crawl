//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: summon.h
//
// ����: ��ȯ�� ����
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __SUMMON_H__
#define  __SUMMON_H__

#include <stdio.h>
#include "common.h"

enum spell_list;
class unit;


enum SUMMON_KIND
{
	SKD_OTHER,
	SKD_SUMMON_BUG,
	SKD_SUMMON_MOOK,
	SKD_SUMMON_BIRD,
	SKD_SUMMON_PENDULUM,
	SKD_SUMMON_ONBASIRA,
	SKD_SUMMON_SEKIBANKI,
	SKD_SUMMON_OPTION,
	SKD_SUMMON_GOLEM,
	SKD_SUMMON_UNZAN,
	SKD_SUMMON_UNZAN_PUNCH,
	SKD_SUMMON_ZOMBIE_FAIRY,
	SKD_SUMMON_UFO,
	SKD_SUMMON_SHINKI,
	SKD_SUMMON_SWAKO_FLOG,
	SKD_SUMMON_SWAKO_MISYAGUZI,
	SKD_SUMMON_FLAN,
	SKD_SUMMON_LESSOR_DEMON,
	SKD_SUMMON_DREAM,
	SKD_SUMMON_DOLLS_WAR,
	SKD_SUMMON_FAKE_DOLLS_WAR,
	SKD_SUMMON_NAMAZ,
	SKD_SUMMON_RACOON,
	SKD_SUMMON_YOUKAI,
	SKD_SUMMON_ANCHOR,
	SKD_SUMMON_TRASH,
	SKD_SUMMON_MASK,
	SKD_SUMMON_MAI,
	SKD_SUMMON_SATONO,
	SKD_SUMMON_OCCULT,
	SKD_SUMMON_KAGUYA_SPELL
};

class summon_info
{
public:
	int parent_map_id; //��ȯ���� �� ���̵�
	SUMMON_KIND summon_id; //���� �����ΰ�
	int max_num; //��ȯ�� �ִ� ����
	summon_info():
	parent_map_id(-1),summon_id(SKD_OTHER),  max_num(-1)
	{}
	summon_info(int parent_map_id_, SUMMON_KIND summon_id_, int max_num_):
	parent_map_id(parent_map_id_),summon_id(summon_id_),  max_num(max_num_)
	{}
	void Setting(int parent_map_id_, SUMMON_KIND summon_id_, int max_num_)
	{
		parent_map_id = parent_map_id_;
		summon_id = summon_id_;
		max_num = max_num_;
	}
	void init();
	
	void SaveDatas(FILE *fp);
	void LoadDatas(FILE *fp);
};
bool summon_check(coord_def c, coord_def order, bool fly_, bool swim_); //�� ��ġ�� ��ȯ�ص� �Ǵ°�?
int GetSummonMaxNumber(spell_list skill);//�ִ��ȯ����
SUMMON_KIND GetSummonKind(spell_list skill);
bool IsIndepend_summoner(SUMMON_KIND skill);//�װ��� ��ȯ���������� ���� ������°�?



#endif // __SUMMON_H__
