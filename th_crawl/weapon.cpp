//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: weapon.h
//
// ����: ���� ���� �Լ���
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "weapon.h"
#include "enum.h"
#include "common.h"
#include "player.h"


int GetNewBrand(int rare_weigth_)
{
	if(randA(99)>=rare_weigth_)
	{
		int arr_[] = {WB_FIRE,WB_COLD,WB_POISON,WB_PROTECT};
		return arr_[randA(3)];
	}
	else
	{
		int arr_[] = {WB_CURSE,WB_AUTUMN,WB_WEATHER,WB_MANA_REGEN,WB_FAST_CAST,WB_PROTECT};
		return arr_[randA(5)];
	}
	return WB_NORMAL;

}

int GetPulsDamage(weapon_brand brand, int damage)
{
	switch(brand)
	{
		case WB_FIRE:
		case WB_COLD:
			damage += damage/3;
			break;
		case WB_WEATHER:
			if (you.s_weather) {
				damage += damage / 2;
			}
			break;
		default:
			break;
	}
	return damage;
}
int GetAttType(weapon_brand brand)
{
	int att_type = ATT_NORMAL;
	switch(brand)
	{
		case WB_FIRE:
			att_type = ATT_FIRE;
			break;
		case WB_COLD:
			att_type = ATT_COLD;
			break;
		case WB_POISON:
			att_type = ATT_S_POISON;
			break;
		case WB_CURSE:	
			att_type = ATT_CURSE;		
			break;
		case WB_WEATHER:
			att_type = ATT_WEATHER;
			break;
		case WB_AUTUMN:
			att_type = ATT_AUTUMN;
			break;
		case WB_MANA_REGEN:
		case WB_FAST_CAST:
		case WB_PROTECT:
		default:
			break;
	}
	return att_type;	
}
const char* GetBrandString(weapon_brand brand, bool artifact_)
{
	switch(brand)
	{
		case WB_FIRE:
			return !artifact_?"ȭ���� ":"ȭ��";	
		case WB_COLD:
			return !artifact_?"�ñ��� ":"�ñ�";
		case WB_POISON:
			return !artifact_?"�͵��� ":"�͵�";	
		case WB_CURSE:		
			return !artifact_?"������ ":"����";	
		case WB_WEATHER	:
			return !artifact_?"����� ":"���";	
		case WB_AUTUMN:
			return !artifact_?"��ǳ�� ":"��ǳ";	
		case WB_MANA_REGEN:
			return !artifact_?"����ȸ���� ":"����ȸ��";	
		case WB_FAST_CAST:
			return !artifact_?"��ӿ�â�� ":"��ӿ�â";	
		case WB_PROTECT:
			return !artifact_?"��ȣ�� ":"��ȣ";	
		default:
			return !artifact_?"�˼����� ":"����";	
	}	

}


const char* GetBrandInfor(weapon_brand brand)
{
	switch(brand)
	{
		case WB_FIRE:
			return "�� ����� ȭ������ �����ִ�. �������� 1/3�� �߰� ȭ�� �������� ���Ѵ�.";
		case WB_COLD:
			return "�� ����� �ñⰡ �ְ����ִ�. �������� 1/3�� �߰� �ñ� �������� ���Ѵ�.";
		case WB_POISON:
			return "�� ����� �͵��� �߶����ִ�. ������ ���� �ߵ���Ų��.";
		case WB_CURSE:		
			return "�� ����� ���ְ� �վ��������� �ִ�. ������ ���� ������ �� ���� ���� ����Ȯ���� ������ �Ǵ�.";
		case WB_WEATHER	:
			return "�� ����� �پ��� �Ӽ��� ������ �������� ����´�. ������ �������̶�� 50%�� �߰� �������� �ش�.";
		case WB_AUTUMN:
			return "�� ����� �ܰ� ������ �Ͻ��� �����ϰ� �ǰ� �̹� �ܰ��� ��쿣 ��� ���� �Ͻ��� �� �ִ�.";
		case WB_MANA_REGEN:
			return "����ִ°͸����� ������ ȸ���ӵ��� �÷��ش�.";
		case WB_FAST_CAST:
			return "�� ����� ����ִ°͸����ε� ����� ��� ���� ��â�ð��� 80%�� �ٿ��ش�.";
		case WB_PROTECT:
			return "�� ����� ����ִ°͸����ε� ����� AC�� 5 ���������ش�.";
		default:
			return "�� ����� ������ �귣�带 �θ��� �ִ�. �Ű��ϼ���!";	
	}	

}