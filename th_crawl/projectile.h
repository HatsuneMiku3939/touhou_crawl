//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: projectile.h
//
// ����: �߻�ó��(�߻繰 ��� ���ð���)
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __PROJECTILE_H__
#define  __PROJECTILE_H__

#include "item.h"
#include "monster.h"
#include "beam.h"


struct projectile_infor
{
	int length;
	bool isitem;
	bool smite;
	int spell;
	bool skill; //��ų�϶�(true�� ��ų, false�� ����)
	projectile_infor(int length_,bool isitem_,bool smite_, int spell_ = -1, bool skill_=false):length(length_),isitem(isitem_),smite(smite_),spell(spell_),skill(skill_){};
};


int Common_Throw(list<item>::iterator& it, vector<monster>::iterator it2, beam_iterator& beam, projectile_infor* infor_, int m_len_= -1, float sector_ = 0, bool auto_ = false);
int Direc_Throw(int auto_direc_, coord_def* c);

#endif // __PROJECTILE_H__