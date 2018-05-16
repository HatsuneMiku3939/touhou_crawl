//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: speak.cpp
//
// ����: ������ ���
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "speak.h"
#include "player.h"


char temp_speak[100];

char* Get_Speak(int mon_id, monster* monster_info, monster_speak_type type)
{ //�����϶�?
	if(type == MST_FOUND)
	{
		sprintf_s(temp_speak,100,"%s%s���ƴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
		return temp_speak;
	}
	switch(mon_id)
	{
	case MON_REIMUYUKKURI:
	case MON_MARISAYUKKURI:
		if(type == MST_NORMAL)
		{
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ϰ� ������!!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;	
	case MON_RUMIA:
		if(type == MST_NORMAL)
		{
			switch(randA(9))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷��ǰ�-\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"%s%s �Ծ �Ǵ� %s?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),job_type_string[you.job],job_string_back[you.job]?"��":"��",tribe_type_string[you.tribe]);
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����- �ڲ� ���� �΋H���� ���̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �� ���� ������ Ž���ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ��ҿ��� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֱ� �ΰ��� ���� ��Ƹ��� ���߾�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷��ǰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ϴ� �ϴ��� �ٶ�ô�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s�� ���� �վ����� �Ĵٺô�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ��� %s���� ���ݴ��һ��� ���� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[randA(TRI_MAX-1)]);
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷�����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����־�???\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� ���پ�-\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���� ������ ������ �ڼ��� ���ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_MISTIA:
		if(type == MST_NORMAL)
		{
			switch(randA(15))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�뷡 �Ѱ� ��� ���°� �?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �뷡�� �ʸ� ���� ��ȥ���̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�뷡 ���縦 �ܿ� �ʿ�� ����. ������̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ġ�� �뷡�� ����� �� ���ݾ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, ������ ����ϱ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�η縶���� ���� �������־����� ���� �� ������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ϰ� �θ� ������ ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				string sing, song;
				switch(randA(16))
				{
				case 0:sing = "���� ��Ʈ��";break;
				case 1:sing = "������";break;
				case 2:sing = "���� ������";break;
				case 3:sing = "���ڰ� ���� �ʴ�";break;
				case 4:sing = "���� ������ ����";break;
				case 5:sing = "�龦������ ����";break;
				case 6:sing = "��Ÿī����";break;
				case 7:sing = "��� �þ�����";break;
				case 8:sing = "�����";break;
				case 9:sing = "��ü�� �˼�����";break;
				case 10:sing = "�߶���";break;
				case 11:sing = "��𼱰� ��";break;
				case 12:sing = "������";break;
				case 13:sing = "��������";break;
				case 14:sing = "��ܿ�";break;
				case 15:sing = "����";break;
				case 16:sing = "�Ϳ���";break;
				}
				switch(randA(13))
				{
				case 0:song = "����";break;
				case 1:song = "�߶�带";break;
				case 2:song = "������";break;
				case 3:song = "����";break;
				case 4:song = "���並";break;
				case 5:song = "�˿���";break;
				case 6:song = "���";break;
				case 7:song = "��Ż��";break;
				case 8:song = "��罺��";break;
				case 9:song = "������";break;
				case 10:song = "Ʈ��Ʈ��";break;
				case 11:song = "������";break;
				case 12:song = "���尡��";break;
				case 13:song = "�帣���� ����";break;
				}
				sprintf_s(temp_speak,100,"%s%s%s %s �ҷ���",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true),sing.c_str(),song.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����ǹ��Ⱦ�-\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���� ������ �ϳ��� ���� �ʴ� �뷡�� �ҷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ź��� ������ �뷡�� �ҷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s��Ȥ�ϴµ��� �뷡�� �ҷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ſ� ������ ��ġ�� �뷡�� �ҷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			}

		}
	case MON_WRIGGLE:
		if(type == MST_NORMAL)
		{
			switch(randA(10))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ���������ϴٴ� ���� ��¯�̳�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��Ӱ� ���� ���� �������� õ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �����ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ȥ�ڼ� �ο�ڴٴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ű�! �߹��� ������! ���������ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ�~ �����ϱ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�뱺�� ���� �װ� �̱� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� ���� ������ �ʾ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s�����̸� ��������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���並 �޷�����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s%s������ ���� �������� ���̱� �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �����ΰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �������� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���·Ӱ� ��Ʋ��Ʋ�Ÿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s�� �����̰� ���� ���״�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(3))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���������� �ҷ��´�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�������� ������ ������ �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s������� ��⸦ �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
	case MON_CIRNO:
		if(type == MST_NORMAL)
		{
			switch(randA(9))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׾��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ָ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����̶�� �躸�°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� 9���̶�� �����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���տ� ������ ���ݾ�? �� �����غ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �׸� �����Ͻ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ó�� �������� ����. �ʶ� ����ָ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���������� ���� ũ�� ���ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s�� ������ ���������� ���ܳ���.",monster_info->GetName()->name.c_str());
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s��¯�� ���� �⼼����ϰ� ���ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"3.14159265358979....\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ������ � ���ؼ� �ɰ��ϰ� ���� ���̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ӹ��� ���������Ű���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��, �̷� ������ ��Ծ����־���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(4))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�⼼���� ����� ���ƴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s�� �տ��� �ñⰡ �𿴴�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ñ��� �帧�� �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���� ũ�� ���ȴٰ� ��븦 ���� ���� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s�ñ��� �ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_MEDICINE:
		if(type == MST_NORMAL)
		{
			switch(randA(11))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, ��ġ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				if(you.poison_resist>0)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��°�� ���� �����Ѱž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ʹ� ���ߴ��ɱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 2:
				if(you.s_poison)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ô������. ���� ���� ��Ʋ��Ʋ�Ÿ��� ���ݾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ƚ��ϱ� ���� �Ϸ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ɹ����� ���ư��� �;�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ���� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �Ȱ��� ��~�� �޶�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, %s%s ��Ÿ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[you.tribe],tribe_string_back[you.tribe]?"��":"��");
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����. ��ó�� ���ο� �� ���� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �����ߴ� �༮�� ��� ���� �׾���Ⱦ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���� ������ �ѹ��� ���۵��Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s%s�����鼭 ���� ���հ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 11:
				sprintf_s(temp_speak,100,"%s%s������ ���Ȱ��� ������ �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����! ����־�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, �Ӹ��� ����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �� ������� �������� �ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ķ�~ ���ķ�~ ���� �𿩶�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���� ��½ ���÷ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���� ��Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_DIEFAIRY:
		if(type == MST_NORMAL)
		{
			switch(randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�������� �ڼ��� ���ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�� ���� ���¸� �������ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s������ �Ĵڿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�������ִ� ���� �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s��������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s��Կ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�տ� ź���� ��Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ�������� ���δ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s������ ���� ���ϰ� ��Ʋ�Ÿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�ȹٷ� ���� ���Ѵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_KISUME:
		if(type == MST_NORMAL)
		{	
			switch(randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�� ���� �����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ޱ׶� �Ҹ��� ����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�η��ڿ� ���� �����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���� ���� ���о���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s�η��ڰ� �Բ� ��鸮���ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�ϼ��� ������ ǥ���� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_CHEN:
		if(type == MST_NORMAL)
		{	
			switch(randA(12))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼭ ��Ű� �Ǹ� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �������� �츮���� ���ε� �������� �ʰھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����̸� ������ �����µ� ���ٷ������� �ʹ� ���� �����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �����̰����� �� ��ű� ����Ű���...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����̿��� ��ģ ��ó�� ���������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �Ľ�ȭ�� �ʿ� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ŀ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ĳ�!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�İ�!!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s%s������ ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 11:
				sprintf_s(temp_speak,100,"%s%s����� ���� �ϰ� ���� ũ�� ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 12:
				sprintf_s(temp_speak,100,"%s%s���� ���� �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��..�ĳ�!?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��..���ٷ�����???\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �����̰� �־�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s����� ���� �ֵθ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_KOGASA:
		if(type == MST_NORMAL)
		{	
			switch(randA(12))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �ʾҾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ΰ����� ������� �ʾƼ� ��� ���°�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ���� �η縶����� ������ ���� �ִ�. ����ϳ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ������ �������� ������ �����°� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� �ᱹ �ʿ���� ������ ������ ������ �����ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�꼺�� ��ƹ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ع����ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s%s����� ���ۺ��� ���ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 11:
				sprintf_s(temp_speak,100,"%s%s���� ���� ���� ���� ���о���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 12:
				sprintf_s(temp_speak,100,"%s%s����ִ� ����� ���� ��������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ���پ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s�� ��꿡 �޷��ִ� ���� ���ۺ��� ����.",monster_info->GetName()->name.c_str());
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s����� �̸����� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_SUNNY:
		if(type == MST_NORMAL)
		{	
			switch(randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� �躸����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �ʴ� ���� �ο� �� �ְھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				if(monster_info->GetInvisible() && !you.invisible_view)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ũ, ������ ���ѹ��ȴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� ������ �ϱ����� �� �� ���ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���÷��̶��� �����ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��, ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				if(monster_info->GetInvisible() && !you.invisible_view)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�! ����ִ��� �𸣰���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else if(monster_info->GetInvisible() && you.invisible_view)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��°�� ���� ���̴� �ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼭ �̷��� ���� ���� ��Ű��...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(1))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���? ���� �ﷷ�Ÿ����־�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ��°�� Ŀ���� �۾����� �ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���� ��Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���� ���� �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���� �������״�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_LUNAR:
		if(type == MST_NORMAL)
		{	
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ο� �� �ۿ� ����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼱ ���� ������ �ʾ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ҹ��� �鸮�������ٵ� ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�η縶���� �Ҹ����� �о�� ȿ���� ���ٴ� �� �˰�����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ġ���ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ���� �ƴ϶��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(1))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������! �̷��� �Ҹ��� ���̸�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ò�����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s�� �ֺ��� ��������� �����ߴ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_STAR:
		if(type == MST_NORMAL)
		{	
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹� ĳ���� ����â���� �����ִ°� �˰��־���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� �������� �����ɷ��� �� ����. ġƮ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�츰 �����̼� ���̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				if(you.s_invisible || you.togle_invisible)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���������־ ���δٴϱ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ĵ� ����, ��� ����. �����ϴ°� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 4:
				if(you.s_invisible || you.togle_invisible)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �����ٵ� ����ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ٲ����̶�� �� �ڽ��� ���°�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;

				}
			case 5:
				if(you.s_invisible || you.togle_invisible)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ����°� ���Ѵٰ� �����Ѱž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ο��� �ڽž���������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(1))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�θ�.. �ƴ� ����?!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���������� ����ĥ���� ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;		
	case MON_YAMABIKO:
		if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s��û�� �Ҹ��� �޾Ƹ��� ���Ǹ� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_KYOUKO:
		if(type == MST_NORMAL)
		{	
			switch(randA(11))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"�ȳ��ϼ���-!!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"��~��~ ��~��~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"��~��~ ��~��~��~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"������ %s�� ����� �޾Ƹ�ĥ�ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[you.tribe]);
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"��Ҹ��� �۴�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"�̷��� ���ʿ��� ����� �ϻ�ٴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"���������� �޾Ƹ��� ��� �߸����ڶ�������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ��, û���ϴµ� �ٴڿ� ���̷��� �������� ���ǵ��� ��������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"�޾Ƹ��� �ܼ��� �ڿ������̶��, �̽��̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s�͸� �Ĵڿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s%s�Ұ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 11:
				sprintf_s(temp_speak,100,"%s%s���� ū �Ҹ��� �Ҹ��� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"�����-!!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"��- ��- ��-!!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ſ� ũ�� ���ƴ�. \"���ƾƾ�-!!!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�͸� �����ϰ� �Ĵڿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������ �´�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s��û�� �Ҹ��� �λ縦 �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�Ͱ� �������� �Ҹ��� �Ұ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_FORTUNE_TELLER:
		if(type == MST_NORMAL)
		{	
			switch(randA(9))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ǳ�! �ʵ� �� ��ġ�Ϸ� �°ų�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ΰ����μ��� ��Ȱ�� ����������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� �䱫�� �ٽ� �¾ ���̴�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ȯ���⿡�� �ΰ����� ��ư��°� �󸶳� ����� �ƴ°�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷�! ������ �ش��̴�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �����ϰڴٸ� �ʵ� ������ָ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� �Ӹ��� �븱 ���̳�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ΰ��� �����ϰڴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s��ģ���� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s�̸� ���Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_MOMIZI:
		if(type == MST_NORMAL)
		{	
			switch(randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� ���մ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���¢����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sĮ�� �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���и� �����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s�̻��� �巯�´�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s¢����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�糳�� ����ô�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(1))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ�������� ���δ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s������ û�ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_AYA:
		if(type == MST_NORMAL)
		{	
			switch(you.tribe)
			{
			case TRI_HUMAN:
				switch(randA(8))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ΰ��� �䱫�� �꿡 ���� �̴ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �����״� �������� ����������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���󰡹�������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���Ÿ��� �����ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֽ� ���� ������ �غظ��� �Ź�! �ѹ� �����غ����� �����ðڽ��ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ȥ�� �� ������ ���� �ƽô°��� �����ʴϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ġ�ø� ����մϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ĩ���ڰ� �ΰ��̾����ϱ�? �̵� �����ñ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 8:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�䱫�� �꿣 �Ժη� ������ �����Ǿ��ֽ��ϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case TRI_CROWTENGU:
				switch(randA(9))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ�, �ʴ�... %s�̾�����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),you.user_name.name.c_str());
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ�, �� �Ź��� �о�þ�. ��̷ο�͵� ��������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ϴ°ž�, �� ����ȥ�� �ܿ� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� �غظ��� �Ź��� ������ ���� ��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹� �̺��� ���ȭ�� �纸����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ǵ�δ� �����ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ź���ȸ�� �󸶳��� �ʾҴٰ� �̷� ���� ���� ���� �ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ܿ� ����� ���̾�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 8:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�䱫�� �꿡�� �����θ��ٴ� ����ٱ��� �ҽ��� �����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 9:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٱ������� �ο��ΰ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case TRI_WOLFTENGU:
				switch(randA(5))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���, ���� ��� �Ȱ̴ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ���Ѿ��� �ڰ� �̷� ����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ٱ����� �츮 ����ٱ��� �躸�°ɱ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ĩ���ڰ� �ִٴ� ��⸦ ������� ���� ����ٱ������� �����׿�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �ϴ� ����ٱ����� ��� �Ȱ̴ϱ�? ��, ����̾�����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ܿ� ����� ���Դϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;

			case TRI_ONI:
				switch(randA(7))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̾�, �̰� ū�ϳ����ϴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"���� Ĩ���ڰ� ���������̾�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ߾߾�, �� ����� ���⿡?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �Ժη� �꿡 ���ø� ��ΰ� ����մϴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��, ��¿ �� ���� �������Դϴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼭ ���ֽô°� ���� �䱫 ��ο��� ��ȭ�ӽ��ϴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƴ��ƴ�, ���� ������ ������ �������ϴٸ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ߾߾�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			default://�⺻��ȭ
				switch(randA(6))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ϰ� �ùٸ� �����̸����Դϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���Ÿ��� �����ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"ī�޶� �̻��ѵ�... ı�Ŀ��� �ðܾ��ϳ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ�, ����ϱ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֽ� ���� ������ �غظ��� �Ź�! �ѹ� �����غ����� �����ðڽ��ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ȥ�� �� ������ ���� �ƽô°��� �����ʴϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ġ�ø� ����մϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ���� �ʽ��ϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ߾߾�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���� �ֽ��ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ��ġ ����ȭ��ó�� ���Դϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s��ä�� �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s�� ������ �ٶ��� �䵿ģ��.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}		
		break;
	case MON_WAKASAGI:
		if(type == MST_NORMAL)
		{
			switch(randA(7))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ����������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٸ� ���� ��� �Ǿ��ִ� ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֺ��� �������� ���ٰ� �־�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���̶�� �����ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⿡ ��Ƶ� �����̵��� ��� ������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �ӿ� �����״� ����鵵 �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�����ϰ� ����ƴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���������� ���� Ƣ��� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����! ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ٵհŷȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s������� ���θ�ġ���ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ź��� ������ �뷡�ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�Ƹ��ٿ� ������ �뷡�ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_YAMAME:
		if(type == MST_NORMAL)
		{
			switch(randA(8))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �� ���� ������ ��°�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷��� ������ �䱫�鿡�� ��Ƹ����� �𸥴ٱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				if(you.s_sick)
				{
					sprintf_s(temp_speak,100,"%s%s������. \"������? �Ȼ��� �����ƺ��̴µ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �ʿ��� �´� ������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 3:				
				if(you.s_sick)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷� ���·� �ο� �� �ְھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ȸ�� ������ ����ϰ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 4:
				if(you.s_sick)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ���� ��ŷᰡ �ɲ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �ɷ��� �˰� �־�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 5:
				if(you.tribe == TRI_KAPPA)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ı�ĵ��� �ò�������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ��ɰ��̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 6:
				if(you.s_sick && you.s_poison)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ��... �ְ��� �������ݾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��°ž�? �ƴϸ� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 7:
				if(randA(10))
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ǰ��� �����ϴ°� �.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else //�߸����Դϱ�(����)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ����, �׿�������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s�� �ֺ��� �ҿ��� ���Ⱑ ������ �ִ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̰� ���ο� �����ΰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ۺ��� ���� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�ٴڿ��� ������ �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���� ��� �÷ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_NAZRIN:
		if(type == MST_NORMAL)
		{
			switch(randA(9))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ ã�� �ְ��ִ°���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���? ���� ã�� ������ �����ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				if(you.haveGoal()) //�÷��̾ (��)�� 1���̻� ��� ������
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٿ�¡�� �����ϰ��־�... ���� ������ �ִ°ǰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� ���� ã�� �ִ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� �ֿ����� �̰� �ٸ��ɱ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �����ϸ� ū�� ��ĥ�ٵ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̺�, %s. �̷� ������ �������߾�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[you.tribe]);
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ϱ�. ���� �̷��� �����ؼ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷���, ������鵵 ������ϴϱ� ���⼭ �Ļ縦 �غ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹����� ���ΰ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ճ�. �㸦 �躸�°ɱ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̾���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٽ� �� �׷���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ٿ�¡�� �ֵθ��� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�ڽ��� ������ ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ٿ�¡�� �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s��ⷳ�� ������Ų��.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_YOSIKA:
		if(type == MST_NORMAL)
		{
			switch(randA(7))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��~���� ��~����~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��~��~��?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��~���~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:			
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �ʾ�~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���� �Ҹ��̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �� ���� ��Ű���� ����� �޾Ҿ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ÿ��� �����ִ� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� �츮���� ���ᰡ �Ǵ°ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��~��~��~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��,��... ��,��...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ø� �����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�̸����� �پ�ٴϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}	
		break;
	case MON_SEKIBANKI:
	case MON_SEKIBANKI_HEAD:
		if(type == MST_NORMAL)
		{
			switch(randA(9))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ������ ���ϰ� ���ָ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ������ ���� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷�, �� ���������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				if(mon_id == MON_SEKIBANKI_HEAD)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ϰ� �ֳ�, �����? ��ŭ �ͼ� ���� ���ϰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �Ӹ��� ������� �����ʴ´�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				if(mon_id == MON_SEKIBANKI_HEAD)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, ���� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, �� �ɷ��� ���� ��������� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����ü... ��ü ���ϴ� �������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ %s���� ������ ���ع޾Ҵ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[randA(TRI_MAX-1)]);
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ���� �η�������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s�� �Ӹ��� ��鸮�� �ִ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				if(mon_id == MON_SEKIBANKI_HEAD)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ����, �� ������ �����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ӹ��� ��������! �� �Ӹ��� ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ȵ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���·Ӱ� �����δ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ۺ��� ���ư���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			if(mon_id == MON_SEKIBANKI_HEAD)
				return NULL;
			switch(randA(1))
			{
			case 0: 
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� ������Ų��.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s�� �Ӹ��� ����ٴϱ� �����Ѵ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}		
		break;
	case MON_NITORI:		
		if(type == MST_NORMAL)
		{	
			switch(you.tribe)
			{
			case TRI_HUMAN:
				switch(randA(5))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ԁ�, �ΰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ΰ��� ��°�� ���⿡ ���°���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̺� �ΰ�! �� ������ �ѹ� �纸���ʰھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ø��ڴٸ��� ��ġ�� �°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �ΰ��� ı�Ĵ� �Ϳ쿴���ϱ� �����������ʰھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ο� ������ ������ �غ� �� �ְڱ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case TRI_CROWTENGU:
				switch(randA(6))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ī�޶� �ʿ��Ѱž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ī�޶� �׷��� �Ժη� �ٷ��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٱ��� ����� ����ϰھ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ڱ� �����ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹��� ���� �Ѽ� �����ֵ�������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹��� �߸��� �ٱ��� ���ǵ嵵 �������� ����... ���? �۵������ʾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ƿ��� �ѹ� ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case TRI_KAPPA:
				switch(randA(6))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� ���� �� �����Ű�����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����� ��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ı�İ� �ۿ� ������ �� �Ϸ��°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʱ���! �ֺ��� �������̷� �����Ѵٴ� ı�İ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ϴ� �������� �ý����� ������ �������� �ʰھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ϼ��� �����ϴٰ�! �ʶ� �����׷�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ��ȯ�ΰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case TRI_ONI:
				switch(randA(7))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����!?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"������... ������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"���⼭ ���ϸ� �������̾�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���й�ä��ġ��...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƴ� �̰� ���� �ο�� �; �ο�� �ƴ϶�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ֽø� �ȵɱ��?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���� �긮�� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s�����ڰ� ��鸰��.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			default://�⺻��ȭ
				switch(randA(7))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ı���� ������� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					if(you.invisible_view)
					{
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �� ���й�ä ���峭�ǰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						
					}
					else
					{
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���й�ä�� �����غ����� �Ա�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					}
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"���̰� �԰� �;����µ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ��簡 �ȵǼ� ������, �ʵ� �ϳ� �纸�� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �����Ÿ� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �� �ֹ�����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					if(you.god != GT_NONE)
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� ���������� �ϴ°ž�? �������ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					else
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ʵ� ������ �ʿ���ٰ� �����ϴ°���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹��� ���� ���� ����ǰ�̾�. ������ ���̷� �ص� ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ּ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s����� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s�� ���濡�� ��ü�� �˼����� ������ Ƣ��´�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���濡�� �� ������ ���´�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s����ġ�� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_KEGERO:
		if(type == MST_NORMAL)
		{
			switch(randA(7))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ο�ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �����ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ó���� ��������Ű���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ϰ� �ְ�;���\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ƴϾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���뿡�� �ѱ�� ��Ƴ��� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���¢����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s������ ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʹ� ��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ħ����������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� ����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� ���� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}	
		break;
	case MON_PARSI:
		//�ĸ��ô� ũ���� ������ ������. �پ��� ����, �ſ� ���� ���� ����.
		if(type == MST_NORMAL)
		{	
			switch(randA(2)) //0�� �븻, 1�� ��, 2�� ������ ���� ����
			{
			case 0:
				switch(randA(8))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�η��� �η��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"�ĸ��ĸ��ĸ��ĸ��ĸ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׾ �ٽ� �����ϴ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�÷��̾�� �����޴´ٴ°� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �ູ�غ���! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �׷��� �������� ���� ��� �ִ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ������� �̿��� �� �ִٴ°� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 8:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�װ� ������ ������, ������ ���������� �󸶵��� ���� �� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}				
				break;
			case 1:
				switch(you.god)
				{
				default:
					switch(randA(0))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�װ� ���� �����ݾ�! ���״� �� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_NONE:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ŷ��ھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ��� �� �����ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ȥ�� ���� �ϴ� ����� �𸣴°� �ƴϾ�? p�� ������� p!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ŵ��̶� �䱸�ϴ°� ���� �����ϴ� �͵� ����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��·�� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �ϴ� �����ε鶧���� ������... �ʵ� �׷���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�װ� ������ ������, ���� �ʸ� ������ ���������� �󸶵��� ���� �� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_JOON_AND_SION:
					switch(randA(4))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��°�� �׷� ���� ���� ������ �Ѱž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						if (you.god_value[GT_JOON_AND_SION][0] == 1)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �׷��� ���� ���� ������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else if (you.god_value[GT_JOON_AND_SION][0] == 2)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��°�� ������ �ް� �ο���°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�����־��� �ҹ��� ������ �ִµ�, �ʽ��� �����̶�� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						if (you.god_value[GT_JOON_AND_SION][0] == 1)
							sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ᱹ ���� ���°� �װ� ������ �������ΰ� �ƴϾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else if (you.god_value[GT_JOON_AND_SION][0] == 2)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �ڿ� ������ ���̴µ�... �׷� ���� �̱� �� �ִ°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������� ������ �� �ִٴ� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						if (you.god_value[GT_JOON_AND_SION][0] == 1)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�׷��� �ڸ� �������ϰ� �������ϰ� ������ �� �ִٴ� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else if (you.god_value[GT_JOON_AND_SION][0] == 2)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"����� �״��� �η����ʾ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�׷� �� ���� ���� �ž��ϴ°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						if (you.god_value[GT_JOON_AND_SION][0] == 1)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��� ���� ���㾲�°ž�? �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else if (you.god_value[GT_JOON_AND_SION][0] == 2)
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ���ݾ�! ������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						else
							sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �༮���� ���ǽ�Ų�ٴ� ���� ������ �ƴѰŰ���.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_BYAKUREN:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���̾�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������鼭�� ������ �������ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"å�� �ʹ� ���ƺ��̳�! ���� �ѱ� ��! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ұ��� �ϴµ� ���� ���� �� �ִ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ұ��� �䱫�� �޾��ִ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �� �Ἥ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٸ� ��û�����ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_KANAKO:
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �ܼ� ������ ���� �� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʳ� ���� ������ġ�� �Ӹ���Ÿ��! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �޷����ðž�? �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ȥ�ڼ� �������� ����� �����̾�? �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ���� ���̾�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_SUWAKO:
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ZUN�� �Ϳ��ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ӽ��� �ϴ°ž�? ������? ��·�� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ¡�׷����ʾ�? �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �Ǵ��� ���Ѱž�? �˼���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���ĥ �� �ִ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ �������� �������� �����ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_MINORIKO:
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �������Ű���! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �ϳ� ���� �ʰھ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������Ű��� ������ ��! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ �ִ� ���̶� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���� �� �����̾�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �� ���� �ȵǴ� ȸ������ ����? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_MIMA:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �������ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����̶� �� �μ������ؼ� ���°ž�? �����ؼ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �������� ��� ���� �ñ��ϳ�. �� �ƽ��ƽ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷� ������ ������ ������ �����������! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʳ� ���� �̸��� �� ������ ����. �ŴϾ��ؼ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʳ� ���� �� ���° �Ȱ��� ����� �α��ִ°ž�? �� �������� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ۿ��� ���ۿ� ����;��Ѵٰ�? �� ���ۿ� �����Ѱ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_SHINKI:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���̶�� â���� �ϴ°ǰ�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���۰�谡 ��? �� ������ 2�麸���ε�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ģ���� ���� ���̳�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ǵ���Ͽ��� �ʹ� ���. �������ʾ�? �� �ټ��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ǹ��� �θ� �� �ִٰ� �����ϴ°ž�? �������� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ǹ��� ��ſ� ������ ����Ÿ��� ����ڳ�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����Ե� P���� �������ž�? �������� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_YUUGI:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ģ�Ѱž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���! ��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ������ �Ǵ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �� ���̶�� �����ߴµ�, �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��? �ʰ� �� ������� ���� ���°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����, �ڲ� ���������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ο�鼭 ���� ���ô� �����ο��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_SHIZUHA:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ������. �������� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ϻ��Ϸ����Ѱž�? ��絵 ���һ����ݾ�, �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ڰ��־��µ� ���� �����ɿ� �����Ⱦ�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ǳ�� �̻ڳ�. �ϳ����� �ʰھ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��Ű�� �������ž�? �������� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� Ÿ�� �ִ°ž�? �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���, ��ǳ�ٶ����� ��ó�� �����������ݾ�. û�Ҿ��ص� �Ǵ� �༮�� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_HINA:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ְ� ����? �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ ���ֹ��� �ܰ��� �ֿ����Ⱦ�. �׷��� ������ �� �ִ� �ʰ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������! ���ְ� ���ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʳ� ���� �׷��� ���µ� ��������������? �����̰��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"2�麸�� ����. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ֿ� ��ӹ����� �������ʾ�? �� �밨���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �׶������� �ʰھ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_YUKARI:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� �����̵� �η縶�� �� ���������ʰھ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �����̴°� �������� �����̵� �غ���;�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����ġ�°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ľ����� ��°� �? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �װ� ��Ż�̶� ���ӿ��� �þ�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���� ǥ������ ���ٴϴ� �ָ� �þ�. ǥ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ѹ� �� ƴ���� ������;�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_EIRIN:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �������� ��ó�Ѱž�? �� �밨���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ���־�? ���� ���־� ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⿡�� ���񹰾��� ���� ������ �ϴ� �� �ڽŰ��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ɷ�ġ���Ϲ����� � �ֿ���. ȸ������� �ٲ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�๰ �ߵ��ΰž�? ���� �ҷ��غ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���ƺ��̳�, ���� �� ������. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� ���� �� ���°ž�? �ҷκһ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_YUYUKO:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ᰡ ���ƺ��̳�, �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ������, ������ �ÿ��ҰŰ��Ƽ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׿������� ��ȥ���� �η��԰��ִ°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ��°� ������ ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ɷ����� �ŴϾƾ�? �ູ�غ��̳� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �� ��ȥ���� ���鲨��? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���Ͽ�����. ȣ���� ���Ѱ���? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_SATORI:
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֿϵ��� ��޹ް� �ִ°ž�? �Ϳ���޾Ƽ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ �ƹ������� �ʾ�? �� ������ ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ���������ص� �����ۿ� �����ž�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֿϵ����� �Ǹ� �� �̸��� �޴°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���丮�� ���ο� �ֿϵ����̾�? ģ���� �����Ű��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ֿϵ����̶� ���� ���غ��̳�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				case GT_TENSI:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������? ���°͵� ������ �� �ִ°� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʿ� �ο�� �������� ����������! ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷� ���� �����鼭 �ߵ� ��������Գ�. �� ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �׻� ���� �����鼭 ���� ��ġ�ڳ�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���� �η���! ������ ���� �ϰ���� �ʾ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �Ӹ����� ���� �������°� �Ⱥ���? �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ��鸮�ݾ�. �� �����Ҵ� �ſ��� ���ؼ� ��� �� �غ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
			case GT_SEIJA:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������� �Ƹ������� �ϴ°ž�? ���� �� Ư���ϳ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ǵ��� ���� �ٸ� �ŵ鿡�Լ� ��ģ�ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ڴ� ���� ��ȭ���Ƽ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �Ƹ��������� ���� ���� �� �ִ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� ���������� ����������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �žӽ��� ���������ִ°� ���� ���̴°�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �Ƹ������� �ϴ� ���� ���ϰھ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
			case GT_LILLY:
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �������� ��� �� ���Ƽ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �׾ �ǻ�Ƴ��ݾ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ������ �󸶳� ���ھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ϰ� �ڿ��� �ο��� �����ص� �Ǵ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �������̶� ģ��������� ������ ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ģ���� ���ƺ����� �η���! ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ģ���� ���ؼ� ����� ���� �� �־�? �ƴ� ����� ���� ģ���� ��������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
			case GT_MIKO:
				switch (randA(6))
				{
				case 0:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�α� ���� ���̳�! �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ʿ��� ��� �׾�޶�� ��Ź�� ���ϳ�����?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ҷκһ�� �η����. �����ϴٸ� ������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���� ���� ���䰡 ���ڴ°�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�׷� �� ����� Ÿ�� �������� �Ǵ°ǰ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"Ȥ�� ����� �Ⱦ��ϴ°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ġ�ε��� �������� ���°�. �Ƿ��� �η�����\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case GT_OKINA:
				switch (randA(6))
				{
				case 0:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �ڰ� �����ѵ�...?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���µ� ��������! �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"Ȥ�� ��� ���� ���ִ� ����������̶� �ϴ°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������ ��ġ ���̵�����! �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �ڿ��� �� �׷��� ��ݻ�� �ٴϴ°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �ٴϱ� ������ ���� ���� �ִµ� �� �� �����ٷ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �� �ȴ�� �� �� �ִ°ž�? �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				break;
			case GT_JUNKO:
				switch (randA(7))
				{
				case 0:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"Ȥ�� �Ҹ�ǰ ���� �� �־�? �� �� �����ٷ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ܼ� �����ϰ� �꺸���� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ü �� �׷��� �����ϰ� �ִ°ž�? ������� ��������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�����غ��̴� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���Ǵ� ������ ������ �����ٷ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ʴ� �װ��� ���� �ູ�̶�� �����ϴ°ž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ���̶� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					switch (you.god_value[GT_JUNKO][3])
					{
					default:
					case 0:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ȭ�� �Ѵٴ°� ���� ������ �ƴѰŰ�����...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ų��ȭ? ��������ʾƵ� �������� �ȴٴ� �η���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���׼�ȭ? ������ ���� ���۰�����?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���¼�ȭ? �ڽ��� ������ ������ϰ� ���� ��� �����簡 ������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�Ŀ���ȭ? �׷��� ���� ������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�����ȭ? �׷��� �������� ���������� �и��ѵ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"����ȭ? �� �ѳ� ��� ���ؼ� �ڽ��� ����Ѱž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 7:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ý��ۼ�ȭ���? ���� �̾߱⸦ �ϴ��� �� �𸣰ھ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}
				}
				break;
				}
				break;				
			case 2:
				if(current_level<MAX_DUNGEUN_LEVEL){
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �������� ���� ������ �־ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �ٸ� ���� ������ �;�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���󼼰� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ı�ĳ� �ΰ����� ��ü�� �ٴ��ݾ�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ �ſ� �����ϰ� �����. �ٸ� ������ ����� ���� ���� �˰��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"o�� �����þ�? �ڵ�Ž�� �˰����� ���� ��û�ϴٱ�! �ٸ� ������ ��ã�� �˰��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ȥ�� ������ ����ī�� ������ �־�? ���� �㹰 �� �ִٴ°� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}				
				else if(current_level == TEMPLE_LEVEL){
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� ����. �� �� ��������? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �������� ������ִٴ� �� ģ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �������� �����൵ �� ���� �ȹ����ž�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �ƹ��� ���� �����ϳ�. â��ε� �� �� �ְھ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �� �̰����� ���� �°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �η���� �����̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ŵ��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=MISTY_LAKE_LEVEL && current_level<=MISTY_LAKE_LEVEL+MAX_MISTY_LAKE_LEVEL) {					
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ȱ��� ȣ���� ���� ���غ��̴� �������� ����. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �� �̷��� ����? ���ĥ�� �ִ� �͵��� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ȱ������� �� �������ʾ�. ���� ���� �༮���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ ���� ���Ƽ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �ϴ��� �� �� �ֳ�. �ϴ��� ���� �������ʾƼ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���ġ�� �ξ�鵵 �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=YOUKAI_MOUNTAIN_LEVEL && current_level<=YOUKAI_MOUNTAIN_LEVEL+MAX_YOUKAI_MOUNTAIN_LEVEL) {					
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �ٱ� ı�ĵ� ģ�� �����Ű���. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������Ȱ�� ���ǿ� ����� �ֵ� ���Ƽ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ı�ĵ��� ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٱ����� ���ǵ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ������ ı�ĵ��� ������� �þ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �� ı�� �ٱ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=SCARLET_LEVEL && current_level<=SCARLET_LEVEL+MAX_SCARLET_LEVEL) {					
					switch(randA(6))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ū ������ ������ �� ���ص� �ǰ���? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���̵�� �Ϳ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ȩ������� ����? ���� ��� ���شٴ°� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ����ī��� �þ�. ���� �ű��Ѱ� Ű��ٴ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���̵� ������ �ϵ� ���ϰ� ��� �־���! ��鼭 ���ϴٴ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ������ ���� �䱫�� �־�. ������ �����ϴٴ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���̵� �������� ȫ���� ���ð� �־���. ȫ�� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=SCARLET_LIBRARY_LEVEL && current_level<=SCARLET_LIBRARY_LEVEL+MAX_SCARLET_LIBRARY_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"å�� �ܶ��̳�. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� å�� ���� �𸣴� ������ ���� �־���. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"å �� � �ֿ������ɱ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷��� ���� �������̶��. �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"å ������ �����ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ������ ���ΰ� ������. ���غ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=SCARLET_UNDER_LEVEL && current_level<=SCARLET_UNDER_LEVEL+MAX_SCARLET_UNDER_LEVEL) {					
					switch(randA(3))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �� �����ִ°���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ǹ��� �������� �� ���� �־�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ȥ���� ����. �� ������ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� ������ ������ �ʴµ��� �α⸸�����ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=BAMBOO_LEVEL && current_level<=BAMBOO_LEVEL+MAX_BAMBOO_LEVEL) {					
					switch(randA(7))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �Ҿ���! �� ��������������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�䳢���� ���� �˰��ִ°ɱ�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ��â�� �� ���߾�. �׷� ���� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ����� ���䳢�� ������. �� ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���? ��� ���� ���� �⵹�� �ִ� ������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ���� �䳢���� �䳢�� �θ����־��ŵ�, ģ���� �����ɱ� �η���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 6:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�䳢�� �ʹ� ���Ƽ� ������ �ȵǴµ� ���� ���� ������ �־�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 7:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ū ��ź�� �� �䳢�� ������������. �� �������� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=EIENTEI_LEVEL && current_level<=EIENTEI_LEVEL+MAX_EIENTEI_LEVEL) {					
					switch(randA(3))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̻��� ���� ���͹��Ⱦ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� ���� �ٻ��� ������ ���ݾ�! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼱ ���� ũ�� ���̴� ��! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⿡�� �䳢���� �ܶ����ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=SUBTERRANEAN_LEVEL && current_level<=SUBTERRANEAN_LEVEL+MAX_SUBTERRANEAN_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �Ծ�, ������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �׷��� ���ϰ� ���°ž�? ��ſ����̴� �η���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �̷��� �������ʿ䰡 ������? ���ư��°� �� �Ż� �����ž�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� 666��... �����ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �����ֵ��� ������ ���� ������ ��°�... �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �󸶳� ��ƿ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=YUKKURI_LEVEL && current_level<=YUKKURI_LAST_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �̻��ϰ� ���� ����ü���� ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��׵��� �������� ��� �� ���� �η���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��׵� �ǿܷ� ���ݾ�. �Ӹ��� �ִµ�! �η���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���ִ� ������ ��...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷��� ���������� �� ¡�׷���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� �ϴ°ž�? �ʹ� �ò�����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=DEPTH_LEVEL && current_level<=DEPTH_LAST_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������� �°ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼱ �°� �䱫���� �ܶ� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̻��� ����� ���� ��Ż���� �ܶ� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ ���� ��ε� �־�. �װ� �� �� �ִ� ���� �ƴϰ�����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����������? ���� �̽��׸��ؼ� �η���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����? �� ���ϵ��� ���� �̷��� ���� �ö���ִ°���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=DREAM_LEVEL && current_level<=DREAM_LAST_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���� ������ �ϴ� �� ������, ���� ���� �ٰ� �ִ°ǰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ӱ�ó�� ������ ��û �걸��! �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ����� ���ε� �� �� �ִ°ž�? ���غ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�۽�, �� �յն��ٴϴ� ������ ����? ó�� ���°�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ʊ���� �� ������ �ٴ��̾�! ������ �Ⱦ�����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� �� ���� �����־��µ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=MOON_LEVEL && current_level<=MOON_LAST_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ��û���� ���� ���� ����? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̻��� �䳢�鿡�� �ѱ�� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ������ũ�� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���̶��? ���� �޿� �°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ʊ���� �Ӹ��� �������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷��� �˾����� ������ ����δ°ǵ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=PANDEMONIUM_LEVEL && current_level<=PANDEMONIUM_LAST_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������? ������ �� �����Ǿ��ֳ�! �η���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ȱ��� ���� �ֵ��� �����Ű���. �� �����ΰŰ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ���� ����ôµ� ���̶�� �ϴ����, �̰� ���� ��?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̻��� ���˵��� ���Ʊ� �Ұž��� ���� ������, ���ƴٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���赵 ��� ������ó�� ���̴µ�, �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���� �г�. �� �Ŵ����� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if(current_level>=HAKUREI_LEVEL && current_level<=HAKUREI_LAST_LEVEL) {					
					switch(randA(5))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ż��� ������� �䱫 õ���ݾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 1:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �׸�ŭ �����ž�? �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 2:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̻��� ��ũ�鶧���� �����ĿԾ�. ��ũ �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 3:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������� �������� ����ؾߵ� �������� �� �𸣰ڴµ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 4:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� ��ü ����? ���� ��ü ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					case 5:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� �� �� ����, �����ϰ� �η���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}				
					break;
				}
				else if (current_level == OKINA_LEVEL) {
					switch (randA(0))
					{
					case 0:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������Դ��� �̻��� ���� �Ծ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}
					break;
				}
				else if (current_level == ZIGURRAT_LEVEL) {
					switch (randA(0))
					{
					case 0:
						sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �غ�� �Ǿ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}
					break;
				}
				else {
					switch(randA(0))
					{
					case 0:
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �����̾�. �ƴϸ� �����ڰ� �߰��ϴ°� ��Ծ�����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
						return temp_speak;
					}
					break;
				}				
				break;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�η����ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ູ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ĸ��ĸ� �߾�Ÿ���..",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s�� �ʷϻ� ���� ��¦�̸鼭 �ֹ��� �ܿ��.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}		
		break;
	case MON_BENBEN:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����𰡹̸� �����ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ��ƿ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ְ��� ������ �������� �˷��ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� ������ �����°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ĸ� �����ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ֿ� �����ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����ȭ���̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���͸� ���ָ� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s����ȭ������ ���ָ� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ź��� ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���� ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_YATHASI:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ��븦 ������ ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �ٷ� ����! \"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� �˱⽬�� �������δ� �ȵǴϱ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ���� �ִ°ž�, ���� ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���並 �����ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ֿ� �����ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ȵ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ֿ� ������ �ȵ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s������ ���ָ� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���͸� ���ָ� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ⱳ�ִ� ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�Ƹ��ٿ� ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;		
	case MON_ORIN:
		if(type == MST_NORMAL)
		{
			if(you.god == GT_SATORI)
			{
				switch(randA(7))
				{
				case 0:		
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"¥��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:	
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�װ� ���丮���� ���ο� �ֿϵ����̾�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷���, ���� �� ���丮�Կ� ��︮�� �ֿϵ������� �����غ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� �����þ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷��� �ʴ� ����̾�? ����? �ƴ� ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���ο� ���� �ֿϵ����� �������� ���� ����ǥ�ε� �ϴ� ��ħ����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����̵��� ���� �޶�� �ϰ��־�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s������ ���鼭 �����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			}
			else
			{
				switch(randA(7))
				{
				case 0:		
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"¥��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:	
					if(you.tribe != TRI_WRAITH)
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �󸶳� ����? ������ ��ü �� �޾ư���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					else
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ɵ� ������ �������Ű���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					if(you.tribe != TRI_WRAITH)
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׾����� ���� ����� �ҷ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					else
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹� �׾��ִ°ž�? ���� ��Ȱ�� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������ ��ü�� �ܶ� �־�. �ູ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���, ���� ���غ��̴µ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					if(you.tribe != TRI_WRAITH)
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ��ü�� ����� ������ ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					else
						sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ����� ��ü�� ����־�? ���� ��Ͽ� �Բ� ������ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s�鶰�ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 7:
					sprintf_s(temp_speak,100,"%s%s�Ŀ˳Ŀ� �Ҹ������ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ�������� ���ƴ�. \"�۸�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%sȥ�������� ���ƴ�. \"��Ǳ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�� ���� ���� �����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������ ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���� ���÷ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_ICHIRIN:
		if(type == MST_NORMAL)
		{
			if(you.god == GT_BYAKUREN)
			{
				switch(randA(4))
				{
				case 0:		
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ȥ�� �̹��� ���� �����翡 ���� ������̽Ű���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹� �ºδ� ������ ���� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �ְ��� �ɰ� �����մϴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����ϴ�! ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� �����̱���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			}
			else
			{
				switch(randA(6))
				{
				case 0:		
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���乫��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����ϴ°Ÿ� �ڽ��־�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 2:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �ָ��� �������� �°� ��ƿ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 3:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� Ȱ���� �ϰ��־�. ���� �ϴ��� �ָ��� ��ȭ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 4:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʿ��� �ϴ� �ѹ��� ���̶�� ������ ���ϰ� �־�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ʿ��� ����� �ϰ� �ִ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 6:
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �̻��� ������ �� ��ġ���� �볳�����ʰڴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ڱ� �������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ʹ� ���� ���̳�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� �ο�����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�̻��� ���⿡ �ָ����� �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������ �ҷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_PACHU:
		if(type == MST_NORMAL)
		{
			switch(randA(10))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"%s%s ó���ϴµ� ���� ���� ������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[you.tribe],tribe_string_back[you.tribe]?"��":"��");
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"...���������� ������ ����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��ħ �������� ã���ִ� ������ �־���\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ �����? ��� �Ӽ��� ���� �س���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��ø� ��ٷ� ���� �ʿ��� ������ �����ִ� å�� ã�ƺ���\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�̹��� �� ������ �?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"������ ��û���� %s�ΰ�... �� �����غ� ������ �־���\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),tribe_type_string[you.tribe]);
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���⼱ ������, å�� �ջ�Ǵϱ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"Ȥ�� å�� �������°ž�? �̾������� �����å�� �ѵι� �غ��� �ƴ϶�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��ø� ��ٷ��� ������ ã�������ϱ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s%s������ �����ϴ� ���� å�� �а� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"...����߾�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"õ���� ��������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s��ħ�� ���ϰ� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%så�� �Ųٷ� �����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%så�� �о� �ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�հ����� ǥ���� �����״�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%så�� ���� ��뿡�� ���ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�ϴ��� ���� ���� �����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s�� å���� ���� ���� �����ߴ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s�� �տ��� ���� �Ҳ��� �Ͼ��.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}		
		break;		
	case MON_KOAKUMA:
		if(type == MST_NORMAL)
		{
			switch(randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�������� �ڼ��� ���ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�� ���� ���¸� �������ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s������ �Ĵڿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�������ִ� å�� �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s��������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s����������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�տ� ź���� ��Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ�������� ���δ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���� ���ε����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s������ ���� ���ϰ� ��Ʋ�Ÿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s�ȹٷ� ���� ���Ѵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_MEIRIN:
		if(type == MST_NORMAL)
		{
			switch(randA(6))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ĩ����? ���⼭�� �� ��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ����� �ƴѰ� ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��... ��� �ڰ��־����� ���̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����⸦ �躸����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�¼������� �����ΰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s������ �ְ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s�±ر��� �߰� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ����~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�˼��ؿ� ����߾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���� ���ε��� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s����� �߱����� �ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;	
	case MON_SAKUYA:
		if(type == MST_NORMAL)
		{
			switch(randA(8))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"û���� ����������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� û���� ���ظ� �ϴ°ǰ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̰͵� û���� ��ȯ���� �صѰԿ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ����� �ð��� ����ſ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̰��� ���Ӽ��� ���� �����Դϴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ư������� ���÷��°ǰ���? �ð��� ���缭�� ���ھ��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ð��� ���缭�� �ð��� �� �� �����ϱ��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ŵ� �� ���ÿ� ���� ���ΰ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s�������� �� �ʿ� ���ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ� �ư���...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƾ� ������ �����־�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�������� ����߷ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s��Ʋ�Ÿ��� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s�� ����� ��񵿾� �������.",monster_info->GetName()->name.c_str());
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%sȸ�߽ð踦 �տ� �����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;	
	case MON_REMILIA:
		if(type == MST_NORMAL)
		{
			switch(randA(8))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ſ� ���� �ɰŰ���\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����Ϳ� �̱� �� �����Ŷ� �����ϴ°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�츮 �ֿϵ��� ���ĸ� �������� ���ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �����ִ� ���� �� ���� 1���̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹� �ʿ��� �̱� ����� ���°� ������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̾������� �������̶�� �����ʾ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ÿ� �Ҷ��� �ǿ�� �ִٴ� Ĩ���ڰ� �ʱ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ɽ�Ǯ�̷δ� ����������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s������ ũ�� ��ģ��.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��-\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ޱ׸��� �ɾ� �Ӹ��� ���մ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�տ��� ���� ����� ��Ҵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s������ �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;	
	case MON_KASEN:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �� �װ� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �Ժη� �ٷ�� ������ ū���� ���ϰ� �ɰž�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �̻� ���ϴ´�� ������ �ʰھ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ĭ��! ���༮�� ����ä!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				if(you.tribe != TRI_ONI)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �ʿ��ҰŰ���\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� ������ �� ���Ḧ ������ �����ʾҴµ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				if(you.god != GT_YUUGI)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�? �ʵ� �� �ؿ��� �����غ����ʰھ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ����... ������� ��?!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��, �Ƴ�! �� ���ϰ� �ƴ϶��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׸���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s�� �ȿ� �����ִ� �ش밡 Ǯ�ȴ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_FLAN:
		if(type == MST_NORMAL)
		{
			switch(randA(10)) 
			{
			case 0:		
				if(you.tribe == TRI_HUMAN)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� �ΰ��� ���°� �幮��?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�.  \"���, ���� �����ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׸��� �ƹ��� ���� �ɱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��Ƽ���� ���������ϱ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				if(you.tribe == TRI_HUMAN)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ΰ��� ����ũ�� ���·� �ۿ� ������ ���µ� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷� �� �� ���ߺ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�峭���� ���Գ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ���������ʾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �κ��� ���� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ƹ��� ������ ĪĪ �ѷ��� �����ĵ�... ����ĥ �� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 9:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹��� �ݴ����̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 10:
				sprintf_s(temp_speak,100,"%s�� ������ ��¦�δ�.",monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�����ϰ� �����̸� �ֵθ��� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s�Ҹ���ġ�� ������. \"������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ֺ� �⹰�� ��ġ�´�� �ı��ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������ ���� ���� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s������ �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_RABIT_SUPPORT:
		if(type == MST_MAGIC)
		{
			sprintf_s(temp_speak,100,"%s%s������ ���� �Ҿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}	
		break;
	case MON_TEWI:
		if(type == MST_NORMAL)
		{
			switch(randA(7))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �����ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�䳢��� �𿩶�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �׷��� �����������ϱ� �����ϰ� �������°� ����~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�䳢���� ������ϴ��� �װ� �����̱���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				{
					string way;					
					switch(randA(7))
					{
					case 0:way = "��";break;
					case 1:way = "��";break;
					case 2:way = "��";break;
					case 3:way = "��";break;
					case 4:way = "�ϵ�";break;
					case 5:way = "�ϼ�";break;
					case 6:way = "����";break;
					case 7:way = "����";break;
					}
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���⼭ %s������ ���� ���ϴ� ������ �� �� ��������~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true),way.c_str());
					return temp_speak;
				}
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���! �� ���̸� �׸����� Ż���� �� �������ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�볪���� �ڸ��ٺ��� ���� Ȯ���� ������ ���� �����°� �˰� �־���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �������̾� ���~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(3))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������ؼ� �̾��ؿ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ������������ �����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ϰ� ��Կ� ����ּ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100,"%s%s��԰Ÿ��� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%sū �Ҹ��� ������ ��û�Ѵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_CLOWNPIECE:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"It's Lunatic Time!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������! �� �� �ӵ��� �÷��� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				if(you.s_lunatic)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�װ� ���� ǥ���̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ ���ϸ� �ξ� ��� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				if(you.s_lunatic)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷� �����ִ°� ���� ���ٱ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ȶ���� ���� ��ġ������ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				if(you.s_lunatic)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̹� �� �����ִ°ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ��ġ�Եɰž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ���������ϸ� ���� �������ִ�. \"�Ͼ�, �Ͼ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��°��??\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� �����־�� �Ǵ°� �ƴѵ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%sȶ���� ��ĥ�� �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_DOREMI:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ϴ��� �ڰ�������, ������ ���� ��������״ϱ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ǹ��� �󸶳� ��ƿ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �����ʾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����⿣ ���� �̸� �ð��̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̰� ���ο� �Ǹ��ΰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׸���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_HELL_HOUND:
		if(type == MST_NORMAL)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s¢����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ϴ��� ���� ��� ���¢����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_LETTY:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�渷 ����~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��? �׶��ϴٰ�? ������ �׷� ��⸦!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ϴ� �����ؼ� ���ܸ��̾�. ������ �ʹ� �߰�����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				if(you.god == GT_SHIZUHA || you.god == GT_MINORIKO)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �̹� ������ ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ܿ��� ���� �����ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				if(you.god == GT_SHIZUHA || you.god == GT_MINORIKO)
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� ��������? �����Ҽ��� ���ܸ��̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷��� �躸���ʴ°� �����ٵ� ������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���ΰž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ȵ�! �ܿ��� ���� �������ʾҾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_YORIHIME:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ĩ����? ���䳢���� ���ϰ��ִ�����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� �����߰ھ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �������ΰ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ������ ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�δ�! ��ǥ�� �����ض�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sĮ�� �̸����� �ֵθ����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"ũ��, ��������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��ø� �ð��� ������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ŷ��� �ҷ����� �����Ѵ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_TOYOHIME:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���� ������ �����ΰ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� �״°�, �װ��� ����� ���Դϴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �ֽź��� �տ��� ����� ������ �� �� ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ���� �ڿ�, �� ���⼭ ������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �� �ִ� �͵� ���� ���ϰž�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ���������ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��ü, ���...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�̷� ���� ���渮��...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s��ä�� ��¦ �ֵѷ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_UTSUHO:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ĩ���� �߰�! �����շ��� ������ �����ϰ� Ĩ���ڸ� �����Ѵ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ǻ������������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�����Ѱ� �𸣰����� �ϴ� �ѹ� ��Ʈ���� �Ǵ°� �ƴϾ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ū�� �ѹ� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʸ� ����Ʈ�� ������ ���� �����Ҳ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٿ������� ������ ���� ��ƹ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�촺?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ٹ��� ����Ҵ�! ����Ҵ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�̰������� ź���� ����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������� Ÿ���� ���� �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_SUIKA:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��? ���� �����ҷ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ְ� �ʿ��߰ŵ�, ������ ��̸� �Ƿ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ᱹ�� ���̰� �Ǿ�����, ��ŵ� �׷��� ���ΰž�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				if(you.tribe == TRI_ONI)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �༮�ε�... �� ��� �������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���� �躸�� ���� ������ ��������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 4:						
				if(you.god == GT_YUUGI)
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��! �����ݾ�? ���� ���� ���ž���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				else
				{
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�������� ��ȸ�� �����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				}
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ϴ� ���������Ѵٰ�! ..����������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������, ���Ѵ�~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �׻� �����ִ°�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�����հŸ����ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�Ȱ��� ������ �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_REIMU:
		break;
	case MON_ALICE:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ο� ������ �����غ��� �� ���ھ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ź���� �극������, �翬�� ��⸦ �ϰ� �־�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���ҰŶ�� ������? �ڰ� ���°� �����̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���ʿ��� ������ �����ʴ´�. ��ȯ������ �⺻�̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ������� �������� �� ��ȭ�� �� �������ϴ°Ű���...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �����ľ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ������ �����Ҽ��� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_SEIRAN:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ݺ��� ��ȭȰ���� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ϴ� ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ���̶�, ���� �����ߴ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̱۷����� ô�ĺ� ���̶�, Ÿ�ٰ� ����, ��ȭ�� �ǽ��Ѵ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s�����ŷȴ�. \"���޵� ����, ���� �������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���̵���! ���̵���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���䳢 �δ�� �� ������ �ȿ��°ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_RINGO:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���󿡵� �� ���� �ڰ� �ִٴ� ��⸦ ����µ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ô�ĺ��� ���� �ְ� ���ϱ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ����δ� �̱۷���, Ÿ���� ��ġ���ʾ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�˰��ִ°� ���� �͵� �׸� ������ �ʴ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:	
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� �ٹ������̸� ���󿡼� ��°͵� ��������������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ��Ȱ�� ���Ⱦ�~\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ����! �����Ȳ�� ó�ߴ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s�߾�ŷȴ�. \"����������\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s���� �������ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s����� �����鼭 �ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_UDONGE:
		if(type == MST_NORMAL)
		{
			switch(randA(4))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ���� ��ġ������ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �䳢���� ���� ������ �����ʾ�, ���� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���� ����ĥ �� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�װ� �����ִ� ���� ��¥�� �ƴϾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� 3ü�� �н��ϰų� ȯ���� �ɰų� �ϰ�;���...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��°�� ���� ȥ�����������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷�����... ���� ���⿡ �ɸ��������ٵ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������ ���⸦ �����´�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_KAGUYA:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� ������ ã�ƿ��ٴ� ȯ�� �λ縦 �ؾ߰ڳ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̳��ٵ��� ���ϰ��ִ°ž� ��\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� ���� ��ġ�� �°ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�״��� �����̰� ����������, �ݹ� �������ٰ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:	
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� �󸶳� ���� ������ Ǯ �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�׷�, ������ ����޴°ž�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���̸�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ȵ�! ���ϱ� �Ⱦ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�Ӹ��� ��� ȥ���������ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_MOKOU:
		break;		
	case MON_TOKIKO:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"å�д� �ð��� ������ �˰��� ġ���ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� å�� ���ѱ�����������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ʵ� �� å�� �븮�°���? ����� �����ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������, �� ���ֿ��Ե� å�� �����޾ƾ��ϴµ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:	
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̸�? �׷��� ���� �߿���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ �ְ� �ʹܸ��̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s��Կ���. \"���� �̸��� �־�����...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s��Կ���. \"���� ���� ������ ��ȸ��...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s������ ȥ�������� �Ĵ��̰��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_TOZIKO:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��ġ���ָ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����� ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷� �̷�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �ϳ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:	
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���Ⱑ �󸶳� �� ���Ϸ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ҽ��� ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"�� ���� ����ΰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"�� ���� �׳��� ���ΰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ϴÿ� ���⸦ ���հ� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���⸦ ����� ������ �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_FUTO:
		if(type == MST_NORMAL)
		{
			switch(randA(8))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�״�� �� ��Ȱ�� �ູ���ֱ����� �Դ°�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��, �ڳ��� ��� ������ ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				if(!you.s_unluck) //�� ������ �Ȱɷ�������
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"ǳ���� �д´ٸ� �� ������ ���ٳ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else //�� ������ �ɷ�������
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ڳ��� ��... ��߳��ֱ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:	
				if(!you.s_unluck) //�� ������ �Ȱɷ�������
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�Ӵ� �� ġ�� � �ѹ� ���°� ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else //�� ������ �ɷ�������
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷��̷�... ������ ū ����� ���Ұ��̾�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̺���! �� ���ø� �������� ȭ�� �θ��ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ø� �ƹ��� ������ 1���� ���ڶ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�ڳװ� Ȥ�� �ҿ� ��Ÿ���� �����غ��� �ǳ�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 7:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������ ����� ������ �غ����ǳ�? ���� �ұ��������̶��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 8:	
				if(!you.s_unluck) //�� ������ �Ȱɷ�������
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ��ٸ��Գ�! ���� ���� �θ��� ������ ���������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				else //�� ������ �ɷ�������
					sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������. �Ǽ��� �ڳ��� ���� �ǵ�ȱ���. �� ��������������.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"������! ����ִ°�! �� �� �����ְ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"��ó�� ���տ�... �� ���¿�������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"�̺���! ���� �����̱� ���� �׷��� �����ְڳ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ÿ� ����� ������ �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_MAMIZO: //������ ��� ����
		if(type == MST_NORMAL)
		{
			switch(randA(1))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��~ ������ ������� \"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��, ź����ȭ 10�� �º�! �����غ��ô� �׷�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:	
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(0))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"��ó�� ���տ�... �� ���¿�������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"�̺���! ���� �����̱� ���� �׷��� �����ְڳ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s�����ٿ� ����� �Ҿ�ִ´�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s����븦 ���� ũ�� ���⸦ �������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_SEIGA:
		if(type == MST_NORMAL)
		{
			switch(randA(5))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��մ� ���̳׿�. ��� �Ƿ��� �����غ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ο� ������ ����밡 �ʿ��ߴµ�, �� ������ ���̾��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���ؼ��� ������ ��������? ���� ���͵帮��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:	
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���õ� �� ���� �Ϳ��ٰ��. ���ð� �Ǻ��ô°� �����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�� ���ī�� �� ưư�ϴ�ϴ�. ����̰� ����غ��ŵ� ���ƿ�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:		
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ���� ���� �������̿���. �ѹ� �ܷﺼ���?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_CONFUSE)
		{
			switch(randA(2))
			{
			case 0:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"�����̽ó׿�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:		
				sprintf_s(temp_speak,100,"%s%sȥ���ϰ� �ִ�. \"�������� �ܷ��� ���� �̷��� ���ƺ��̽ôٴ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100,"%s%s�ٴڿ� ������ �������� �õ��ߴ�",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if(type == MST_MAGIC)
		{
			switch(randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s������ �ηȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}		
		break;
	case MON_MURASA:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�¼��� ȯ���մϴ�. �������� ������ �ǰڽ��ϴ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				if (you.s_none_move)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�鿡 �����ִ� ����� ���� ���׿�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else 
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ø� �ű� �����ֽðھ��? �����ϰڽ��ϴ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 2:
				if (you.s_none_move)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �ִ� �� ����ĥ �� �����̴ϴ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �뿡�� ���� ���������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ �� �� �ƽó���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ����... �׸������׿�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���������� ì��̳���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�谡... ��������...!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���� �̷��� �� �ֹ̰�...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ڸ� �̸����� �ֵθ��� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���� ���� �����.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_KEINE:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �˻縦 �ϰھ�. ���������� ��ġ�� �ѹ��̾�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ���� ������ �� ������ �����°� �����ž�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ �л��� ��Ű�� ���ؼ���� ������ �뼭�����ʾ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ����� �޾ư��ھ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				if (you.tribe == TRI_HUMAN)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ΰ��� �ο�°� ������������... ��¿ �� ����.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �ΰ����� �յ� ����� ���ְھ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�װ� �̱�� ����� �����ž�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"Ū, ������ Ǯ������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���� �������϶� ������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s�Ӹ��� ����� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_KEINE2:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ����� ������ ������� �� ������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�Կ� ������ �� �־�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ���� �̱� ���縦 ����� �� ���̾�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�����̸� ���о��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ �ð��̴�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�µ��� ���� �л����� ��ġ�����̴�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�� ���¿��� ������ �ΰ��ؼ�...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�� �������� ������...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s�Ӹ��� ���鼭 ���¢�� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_YOUMU:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�䱫�� ������ �� �������� �� �� ���°�, %s ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true), randA(2)? (randA(1)?"����":"����"):"���� ���ݹۿ�");
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ϴ� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ħ ������ ������ �ʿ��ߴ��ž�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̹��� ������ �˼��� �����غ��߰ھ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ �ٴ´�! �׸��� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̷� �̷� ����ġ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�����ڴ�! ��� �輼��!?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���� �Ѿ�����.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s��濡 ���� �ֵθ��� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���� �������� ��Ҵ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_LYRICA:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �մ��� �ʰ� ������ �� �־�. ������̶�� ���� �̱���\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̹� ������ ������ �� ȥ���ϱ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������� ȥ�ڼ� ���̺굵 �ϰ� �;�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ϵ麸�� ���� �� ������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���� ���������� ��Ƴ�����~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s�� Ű���尡 �ϴÿ� ���ٴϸ鼭 ���� �����ϰ� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���, ���ڸ� ������� ����.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��� ��� �ƴ� �Ǻ��� �����?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s����ȭ������ �����ϰ� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� �ǹ��� ������ ���ֵǰ� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_MERLIN:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���ָ� ��� �����ߴ� �ķ��� ����\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				if (you.s_confuse)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ſ� ���̴µ�~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �� ������ ��� �����Ѱž�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 2:
				if (you.s_confuse)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ ������ �������� �ɸ��ž�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �� �� ��￩�ٷ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �� �ų��� ���� �������״ϱ� ��ٷ�~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̹� ���ִ� �� �����̾�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s�� Ʈ������ ������ �︮�� �Ҹ��� ���� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�ູ��~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�̷� ��� �������̾�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s�� Ʈ������ �ò����� ���ȼҸ��� ������ �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� Ʈ������ ������ ���ֵǰ� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_LUNASA:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ķ� ������ �����߳�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				if (you.s_slow)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�׷�, �״�� ħ���ϰ� �������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �� �����ϰ� �ִ°� �?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 2:
				if (you.s_slow)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ ���� �̻� ����ĥ �� �����ž�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ʹ� �鶰�ִ°� �����ʾ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �׷��� ���Ѱ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̹� ���ִ� ������ �ý��Ѱ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s�� ���̿ø��� �Ҹ���ġ�� �Ҹ��� ����.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��Ϸμ� ħ���ؾ��� ����...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���̿ø��� ���� ���������Ͱ���...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s�� ���̿ø��� ������ �������� ������ ����.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� ���̿ø��� ������ ���ֵǰ� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_KOMACHI:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ð������ ���� ����ΰ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�Ƴ�, ��, ���� ������ġ���ִ��� �ƴ϶��\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��� ��Ŵٿ� �ϵ� �������� �غ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"Ȥ�� ����ĥ ������ �ƴϰ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"Ȥ�� ���ο� �ڻ� ������ϱ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ���� �����ϴܸ�����, �������� ������ �ϵ� �ϰ�;����ٰ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��... ��Ű ��ŰŰ��?! ������ ġ�� �����ʾҾ��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s�ٴڿ� ���� �Ѿ�����.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���� ũ�� �����.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_IKU:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				if (you.god == GT_TENSI)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ū �ƾ��� �̻��� �峭���� �ֿ�����...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ ū ������ �Ͼ�ſ���\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 1:
				if (you.god == GT_TENSI)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"ū �ƾ����� �ֵѸ��°� ��ſ�Ű���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ¥�����ٵ� �����ڳ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 2:
				if (you.god == GT_TENSI)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"ū �ƾ����� ���� ���� �ʿ��� �� ������.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������ ������ õ�� ������ ġ�ڽ��ϴ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ �� ����ϳ׿�. �� �ϴ����� ��������� ������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̷� ������ ������ ���� ��� �ɱ��?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�����ȿ����� ������ ����°� �������� ����� �ʾƿ�.\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"������... �ƴ� ������ �ƴϾ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"������ �帧�� �� Ÿ��������...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s�ϴ��� ���ڿ������� ���� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(1))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� �ֺ��� �����Ⱑ �Ͼ�� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s�ϴ� ���� ���� ������.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_LARVA:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ż����� ���̶� �� �� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���! �ο��̴� �ο�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ѿ������� �����̴�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���õ��� ���� �����귯!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ������ ���ٰھ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������Ե� �� �� ���� �ʾ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��~��?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�׺�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s�� �����̰� ȥ�������� ��鸮�� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_NEMUNO:
		if (type == MST_NORMAL)
		{
			switch (randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"����� �� �����̴�! �� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������ �� �� ������ ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������ʴ´ٸ� �踦 �����ְھ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��� �̷� ������ ���°���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				if (you.tribe == TRI_CROWTENGU || you.tribe == TRI_WOLFTENGU)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ٱ����? �Ұ�ħ ������ �ξ��� ���ε�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�װ� ������ �˹� �ƴϾ�. �� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������ζ� �ѾƳ��ھ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �������� �߸����̶�°���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��... �������̾�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"��������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%sĮ�� ���� �ֵθ��� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_AUNN:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ ���� ��Ű�ھ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��������� ��������ھ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"Ĩ���� �߰�! ������ ��Ű�ھ��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ �̻�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s�������Ÿ��� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s�糳�� ¢�� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�� �̷��� ��������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���� ��ȣ�����μ� ������ ���Ѿ�...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s�ٴڿ� �߱��� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_NARUMI:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ �����غ� ��븦 ã�� �־�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ʴ� �� ������ ��ƿ �� ������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ %s�ڽľ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true), tribe_type_string[you.tribe]);
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ܳ乫��, �� ���� ���ֿ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ �� ȥ�� �־���...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���õ��� ���� �ѹ濡 �������� ������ �� �� ���� �� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���~ ���� ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"����~ �̰�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ۺ��� ���� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_MAI2:
		if (type == MST_NORMAL || type == MST_CONFUSE)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ���� �̰ž�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �ο� �ʿ䵵 ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�׽�Ʈ�� �����غ���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���� ���� �ƴ���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��Ű���Կ��� �ſ��� ���̾�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ʵ� �� ���ᰡ ������ �𸣰ڳ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_SATONO:
		if (type == MST_NORMAL || type == MST_CONFUSE)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���´Կ� ���ۿ� ���� �ʾ�? �ҽ��ϳ�~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ��Ƶ� �ҿ�����ž�~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �㵵 �Ϻ��Ѱ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"����� ���� �ο�������~\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ����� �ʿ䰡 �������̾�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ֹ��� �ܿ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_KOKORO:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"����� ������ �������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ְ��� �ڸ��� �ΰ� ���� �ܷ��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������ ������ ������ �������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ������ ���� �˰� �־�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������̶�� �غ�Ǿ��־�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������ �̰ɷ� �غ���...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�̰� ȥ���Ҷ� ���� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�������ﶩ �� ����... �� �ƴѰ�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s������ �� �� ���� ���Ľ���ȴ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s������ �ִ� ���� �� �ϳ��� ���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_KOKORO1:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�״�� ���峻�ָ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ְ��� �ڸ��� �ΰ� ���� �ܷ��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��Ÿ������! �� �ڽ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �ڽ�! ���㰡�����ֳ�! ������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̰��� �г��Ҷ� ���� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ��������� ������ ��ü�� �� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�̰� ȥ���Ҷ� ���� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�ʹ� �г��ؼ� ���� �Ⱥ���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s������ �Ųٷ� ���� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� ���鿡�� ���� �վ������´�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_KOKORO2:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̷� ����� ����� ���� ��������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������ �̸� ����������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �ӱ��� ���پ��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̰� ���ö� ���� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ǥ���� ��� ���� ����?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�̰� ȥ���Ҷ� ���� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"������ ���� �������ʾ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s������ ��߳� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� ���鿡�� �δ��� �ñⰡ �վ������´�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_KOKORO3:
		if (type == MST_NORMAL)
		{
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������� �¸��� ����� ���ĳ��±���\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������� �ο� ��븦 ã�� ��ڱ���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�̰� �¸��� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�س´�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� �뱸�̰� �Ǿ��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ������� ����������?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�̰� ȥ���Ҷ� ���� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�ʹ� �⻵�� �þ߰� ��鸮���־�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s������ ���� ����߷ȴ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s�� ���鿡�� �����Ⱑ ���ܳ��� �ִ�.", monster_info->GetName()->name.c_str());
				return temp_speak;
			}
		}
		break;
	case MON_SUMIREKO:
		if (type == MST_NORMAL)
		{
			switch (randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�������� ȯ���⿡ �����߾�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				if (you.tribe == TRI_HUMAN)
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���� ȯ���⿡�� �ΰ��� �ִ°ű���\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
				else
				{
					sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��ȣ, %s�� ��̱�����\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true), tribe_type_string[you.tribe]);
					return temp_speak;
				}
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���Ŭ���� �ʴ� ȸ���� ���� �ɰ� �̰��ָ�\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"������̶��� �󸶳� ���� �������� �˰� �־�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"ȯ������ �ֹ��� ���� ȣ�����̱���...\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ʴɷ��� ���� �ΰ��� ���� �־�?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100, "%s%s�⼼ ���� ��� ���ϰ� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���� ���� �;�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�� �����ľ���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"���� �����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�������� ��� ���� �����ߴ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	case MON_HATATE:
		if (type == MST_NORMAL)
		{
			switch (randA(6))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�����Ϸ� ���ƴٴ� �ʿ䰡 ���ٴϱ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"����Ʈ���̶��� ����?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"���! ��� �۾��߿� �Ժη� �����������!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��! ������ ����� ���� �ִ� %s�ε�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true), tribe_type_string[you.tribe]);
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"��� �������� �����ٷ�? ������ ������� ������\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ī�޶�� �������� �پ��־�! �����ĵ� �ҿ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 6:
				sprintf_s(temp_speak,100, "%s%s�� �ڵ����� ������ ������ �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_CONFUSE)
		{
			switch (randA(2))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�ڵ��� �����ϴ°� ��Ծ���!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%sȥ���ϰ� �ִ�. \"�ڵ��� ������ ���� ���� ���ݾ�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%sȥ���Ͽ� �ڱ� �ڽ��� �����Ϸ��� �ִ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		else if (type == MST_MAGIC)
		{
			switch (randA(0))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s�ڵ��� ī�޶� ������ ���ߴ�.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		}
		break;
	default:
		break;
	}
	if(type == MST_MAGIC)
	{
		sprintf_s(temp_speak,100,"%s%s�ֹ��� �ܿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
		return temp_speak;
	}
	else if(type == MST_CONFUSE)
	{
		sprintf_s(temp_speak,100,"%s%sȥ�������� �ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
		return temp_speak;
	}
	sprintf_s(temp_speak,100,"%s%s���ƴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_do(true));
	return temp_speak;
}