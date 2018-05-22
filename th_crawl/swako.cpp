//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: swako.cpp
//
// ����: ������ �Ǵ� ����
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "swako.h"
#include "player.h"
#include "skill_use.h"
#include "god.h"



const char* GetSwakoString1(swako_1_power power, swako_string kind)
{
	switch(power)
	{
	case SWAKO_1_JUMP:		
		switch(kind)
		{
		case SWAKO_NAME: return "������ ����";
		case SWAKO_SIMPLE_INFOR: return "����� ª�� �Ÿ��� ������ �� �ִ�.                             (P, ����)";
		case SWAKO_GET_STRING: return "����� ���� ª�� �Ÿ��� ������ �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ª�� �Ÿ��� ������ �� ����.";
		}
		break;
	case SWAKO_1_TEMPLE:
		switch(kind)
		{
		case SWAKO_NAME: return "���� �����";
		case SWAKO_SIMPLE_INFOR: return "����� ������ ���� �žӽ��� �� �� �ִ�.                              (P)";
		case SWAKO_GET_STRING: return "����� ���� ������ ���� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ������ ���� �� ����.";
		}
		break;
	case SWAKO_1_WATER_GUN:
		switch(kind)
		{
		case SWAKO_NAME: return "����";
		case SWAKO_SIMPLE_INFOR: return "����� �ָ��ִ� ���� ���� ź���� ���� �� �ִ�.                    (����)";
		case SWAKO_GET_STRING: return "����� ���� ������ ���� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ������ ���� �� ����.";
		}
		break;
	case SWAKO_1_TONGUE:
		switch(kind)
		{
		case SWAKO_NAME: return "������ ��";
		case SWAKO_SIMPLE_INFOR: return "����� �ָ��ִ� ���� ���� ��� �� �ִ�.                        (P, ����)";
		case SWAKO_GET_STRING: return "����� ���� �ָ��ִ� ���� ������ �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���� ������ �� ����.";
		}
		break;
	}
	return "����";
}

const char* GetSwakoString2(swako_2_power power, swako_string kind)
{
	switch(power)
	{
	case SWAKO_2_KILL_HP:		
		switch(kind)
		{
		case SWAKO_NAME: return "���϶� ü��ȸ��";
		case SWAKO_SIMPLE_INFOR: return "����� ���� ���϶����� Ȯ�������� ü���� ȸ���Ѵ�.              (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� ���� �������� ü���� ȸ���� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���� �׿��� ü���� ȸ���� �� ����.";
		}
		break;
	case SWAKO_2_KILL_MP:
		switch(kind)
		{
		case SWAKO_NAME: return "���϶� ����ȸ��";
		case SWAKO_SIMPLE_INFOR: return "����� ���� ���϶����� ������ ȸ���Ѵ�.                         (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� ���� �������� ������ ȸ���� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���� �׿��� ������ ȸ���� �� ����.";
		}
		break;
	case SWAKO_2_KILL_POWER:
		switch(kind)
		{
		case SWAKO_NAME: return "���϶� �Ŀ�ȸ��";
		case SWAKO_SIMPLE_INFOR: return "����� ���� ���϶����� Ȯ�������� �Ŀ��� ȸ���Ѵ�.              (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� ���� �������� �Ŀ��� ȸ���� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���� �׿��� �Ŀ��� ȸ���� �� ����.";
		}
		break;
	case SWAKO_2_SWIM:
		switch(kind)
		{
		case SWAKO_NAME: return "����";
		case SWAKO_SIMPLE_INFOR: return "����� ������ �� �ִ�. ������ ȸ�� ���ʽ��� ��´�.             (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� ������ �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� ���� ���ֺ��̴�.";
		}
		break;
	case SWAKO_2_DEAD_PROTECT:
		switch(kind)
		{
		case SWAKO_NAME: return "�������κ����� ��ȣ";
		case SWAKO_SIMPLE_INFOR: return "�����ڰ� ���� ����� �������κ��� ��ȣ�Ѵ�.                     (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� �����ڷκ��� ��ȣ�޴´�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� �����ڷκ��� ��ȣ���� �� ����.";
		}
		break;
	}
	return "����";
}

const char* GetSwakoString3(swako_3_power power, swako_string kind)
{
	switch(power)
	{
	case SWAKO_3_CURSE:		
		switch(kind)
		{
		case SWAKO_NAME: return "�������� ���";
		case SWAKO_SIMPLE_INFOR: return "����� ��뿡 ����� �� �� �ִ�.                               (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� ��븦 ������ �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���ָ� �� �� ����.";
		}
		break;
	case SWAKO_3_DIGGING:
		switch(kind)
		{
		case SWAKO_NAME: return "����";
		case SWAKO_SIMPLE_INFOR: return "����� ���� ���ʶ߸� �� �ִ�.                                  (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� ���� ���ʶ߸� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���� ���ʶ߸� �� ����.";
		}
		break;
	case SWAKO_3_SUMMON_FLOG:
		switch(kind)
		{
		case SWAKO_NAME: return "������ ��ȯ";
		case SWAKO_SIMPLE_INFOR: return "����� ������ ���Ḧ ��ȯ�� �� �ִ�.                           (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� �������� ��ȯ�� �� �ִ�";
		case SWAKO_UNGET_STRING: return "����� �� �̻� �������� ��ȯ�� �� ����.";
		}
		break;
	case SWAKO_3_STATUE:
		switch(kind)
		{
		case SWAKO_NAME: return "���� �����";
		case SWAKO_SIMPLE_INFOR: return "����� �����ð����� ������ ���� �� �ִ�.                       (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� �Ϳ��� ������ ������ ���� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ������ ������ ���� �� ����.";
		}
		break;
	}
	return "����";
}

const char* GetSwakoString4(swako_4_power power, swako_string kind)
{
	switch(power)
	{
	case SWAKO_4_COLD_RESIST:		
		switch(kind)
		{
		case SWAKO_NAME: return "�ñ� ����";
		case SWAKO_SIMPLE_INFOR: return "����� �ñ⿡ ������ �ִ�.                                      (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� �ñ⿡ ���ϴ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� �ñ⿡ ������ �ʴ�.";
		}
		break;
	case SWAKO_4_FIRE_RESIST:
		switch(kind)
		{
		case SWAKO_NAME: return "ȭ�� ����";
		case SWAKO_SIMPLE_INFOR: return "����� ȭ���� ������ �ִ�.                                      (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� ȭ���� ���ϴ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ȭ���� ������ �ʴ�.";
		}
		break;
	case SWAKO_4_AC:
		switch(kind)
		{
		case SWAKO_NAME: return "�Ǻ� ��ȭ";
		case SWAKO_SIMPLE_INFOR: return "����� AC�� �����Ѵ�.                                           (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� �Ǻΰ� �ܴ�������.";
		case SWAKO_UNGET_STRING: return "����� �Ǻδ� ����������.";
		}
		break;
	case SWAKO_4_CONFUSE_RESIST:
		switch(kind)
		{
		case SWAKO_NAME: return "ȥ�� ����";
		case SWAKO_SIMPLE_INFOR: return "����� ȥ���� ������ �ִ�.                                      (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� �̸ֹ� ���� �ʴ´�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� �ֹ̿� ������ �ʴ�.";
		}
		break;
	case SWAKO_4_POISON_RESIST:
		switch(kind)
		{
		case SWAKO_NAME: return "�� ����";
		case SWAKO_SIMPLE_INFOR: return "����� ���� ������ �ִ�.                                        (�нú�)";
		case SWAKO_GET_STRING: return "����� ���� ���� ���ϴ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ���� ������ �ʴ�.";
		}
		break;
	}
	return "����";
}

const char* GetSwakoString5(swako_5_power power, swako_string kind)
{
	switch(power)
	{
	case SWAKO_5_RAIN:		
		switch(kind)
		{
		case SWAKO_NAME: return "�� ������";
		case SWAKO_SIMPLE_INFOR: return "����� �ֺ��� ���ٴٷ� ���� �� �ִ�.                           (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� �Ŵ��� �� ������ �� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� �� ���� �� ����.";
		}
		break;
	case SWAKO_5_SLEEP:
		switch(kind)
		{
		case SWAKO_NAME: return "����";
		case SWAKO_SIMPLE_INFOR: return "����� ���ӿ� ��� ������ ���� �� �ִ�.                      (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� ������ �Ѵ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� ������ ���� �ʴ´�.";
		}
		break;
	case SWAKO_5_MISYAGUZI:
		switch(kind)
		{
		case SWAKO_NAME: return "�̻������� ��ȯ";
		case SWAKO_SIMPLE_INFOR: return "����� �̻��������� ��ȯ�� �� �ִ�.                            (P, �ž�)";
		case SWAKO_GET_STRING: return "����� ���� ���ù����� �̻��������� ��ȯ�� �� �ִ�.";
		case SWAKO_UNGET_STRING: return "����� �� �̻� �̻��������� ��ȯ�� �� ����.";
		}
		break;
	case SWAKO_5_SWAKO_HAT:
		switch(kind)
		{
		case SWAKO_NAME: return "�����ڴ��� ����";
		case SWAKO_SIMPLE_INFOR: return "����� �����ڴ��� �Ϳ��� ���ڸ� �޾Ҵ�.";
		case SWAKO_GET_STRING: return "";
		case SWAKO_UNGET_STRING: return "";
		}
		break;
	}
	return "����";
}

bool GetSwakoAbility(int level, bool plus)
{
	switch(level)
	{
	case 1:
		switch(you.god_value[GT_SUWAKO][0])
		{
		case SWAKO_1_JUMP:	
			you.Ability(SKL_SWAKO_JUMP,true,!plus);
			break;
		case SWAKO_1_TEMPLE:
			you.Ability(SKL_SWAKO_TEMPLE,true,!plus);
			break;
		case SWAKO_1_WATER_GUN:
			you.Ability(SKL_SWAKO_WATER_GUN,true,!plus);
			break;
		case SWAKO_1_TONGUE:
			you.Ability(SKL_SWAKO_TOUGUE,true,!plus);
			break;
		}
		if(plus)
			printlog(GetSwakoString1((swako_1_power)you.god_value[GT_SUWAKO][0],SWAKO_GET_STRING),true,false,false,CL_swako);	
		else
			printlog(GetSwakoString1((swako_1_power)you.god_value[GT_SUWAKO][0],SWAKO_UNGET_STRING),true,false,false,CL_swako);
		break;
	case 2:
		switch(you.god_value[GT_SUWAKO][1])
		{
		case SWAKO_2_KILL_HP:	
			break;
		case SWAKO_2_KILL_MP:
			break;
		case SWAKO_2_KILL_POWER:
			break;
		case SWAKO_2_SWIM:
			break;
		case SWAKO_2_DEAD_PROTECT:
			break;
		}
		if(plus)
			printlog(GetSwakoString2((swako_2_power)you.god_value[GT_SUWAKO][1],SWAKO_GET_STRING),true,false,false,CL_swako);	
		else
			printlog(GetSwakoString2((swako_2_power)you.god_value[GT_SUWAKO][1],SWAKO_UNGET_STRING),true,false,false,CL_swako);
		break;
	case 3:
		switch(you.god_value[GT_SUWAKO][2])
		{
		case SWAKO_3_CURSE:	
			you.Ability(SKL_SWAKO_CURSE,true,!plus);
			break;
		case SWAKO_3_DIGGING:
			you.Ability(SKL_SWAKO_DIGGING,true,!plus);
			break;
		case SWAKO_3_SUMMON_FLOG:
			you.Ability(SKL_SWAKO_SUMMON_FLOG,true,!plus);
			break;
		case SWAKO_3_STATUE:
			you.Ability(SKL_SWAKO_STATUE,true,!plus);
			break;
		}
		if(plus)
			printlog(GetSwakoString3((swako_3_power)you.god_value[GT_SUWAKO][2],SWAKO_GET_STRING),true,false,false,CL_swako);	
		else
			printlog(GetSwakoString3((swako_3_power)you.god_value[GT_SUWAKO][2],SWAKO_UNGET_STRING),true,false,false,CL_swako);
		break;
	case 4:
		switch(you.god_value[GT_SUWAKO][3])
		{
		case SWAKO_4_COLD_RESIST:	
			you.ResistUpDown(plus?1:-1,RST_ICE);
			break;
		case SWAKO_4_FIRE_RESIST:
			you.ResistUpDown(plus?1:-1,RST_FIRE);
			break;
		case SWAKO_4_AC:
			you.AcUpDown(0,plus?5:-5);
			break;
		case SWAKO_4_CONFUSE_RESIST:
			you.ResistUpDown(plus?1:-1,RST_CONFUSE);
			break;
		case SWAKO_4_POISON_RESIST:
			you.ResistUpDown(plus?1:-1,RST_POISON);
			break;
		}
		if(plus)
			printlog(GetSwakoString4((swako_4_power)you.god_value[GT_SUWAKO][3],SWAKO_GET_STRING),true,false,false,CL_swako);	
		else
			printlog(GetSwakoString4((swako_4_power)you.god_value[GT_SUWAKO][3],SWAKO_UNGET_STRING),true,false,false,CL_swako);
		break;
	case 5:
		switch(you.god_value[GT_SUWAKO][4])
		{
		case SWAKO_5_RAIN:	
			you.Ability(SKL_SWAKO_RAIN,true,!plus);
			break;
		case SWAKO_5_SLEEP:
			you.Ability(SKL_SWAKO_SLEEP,true,!plus);
			break;
		case SWAKO_5_MISYAGUZI:
			you.Ability(SKL_SWAKO_MISYAGUZI,true,!plus);
			break;
		case SWAKO_5_SWAKO_HAT:
			if (you.suwako_meet == 1 && plus) {
				GodGift(GT_SUWAKO, you.piety);
				you.suwako_meet = 2;
			}
			return true;
		}
		if((swako_5_power)you.god_value[GT_SUWAKO][4] != SWAKO_5_SWAKO_HAT)
		{
			if(plus)
				printlog(GetSwakoString5((swako_5_power)you.god_value[GT_SUWAKO][4],SWAKO_GET_STRING),true,false,false,CL_swako);	
			else
				printlog(GetSwakoString5((swako_5_power)you.god_value[GT_SUWAKO][4],SWAKO_UNGET_STRING),true,false,false,CL_swako);
		}
		break;
	}
	return true;
}