//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: lilly.cpp
//
// ����: ����
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "lilly.h"
#include "unit.h"
#include "monster.h"
#include "environment.h"
#include "mon_infor.h"
#include "skill_use.h"


int getMaxFairyName(){return 20;};

name_infor fairy_name[] =
{
	name_infor("����",false),
	name_infor("���丮",false),
	name_infor("����",false),
	name_infor("����",false),
	name_infor("����Ű",false),
	name_infor("��ī",false),
	name_infor("�ƿ�",false),
	name_infor("����",false),
	name_infor("���",false),
	name_infor("��ī",false),

	name_infor("������",false),
	name_infor("�ҳ�",false),
	name_infor("�̾�",false),
	name_infor("����",true),
	name_infor("����",false),
	name_infor("���",false),
	name_infor("����",false),
	name_infor("�̺�",false),
	name_infor("����ī",false),
	name_infor("������",false)
};






extern char temp_speak[100];
const char* fairy_speak(monster* monster_info, int personal, FAIRY_SPEAK type)
{
	
	switch(monster_info->id)
	{
	case MON_DIEFAIRY:
		switch(type)
		{
		case FS_NORMAL:
				switch(randA(5))
				{
				case 0:
					sprintf_s(temp_speak,100,"%s%s���� ��ſ��� �����ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 1:
					sprintf_s(temp_speak,100,"%s%s��ſ��� �������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;					
				case 2:
					sprintf_s(temp_speak,100,"%s%s�������� ���� ���ȴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;				
				case 3:
					sprintf_s(temp_speak,100,"%s%s������ �Ĵڿ���.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;	
				case 4:
					sprintf_s(temp_speak,100,"%s%s��ſ��� ���� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				case 5:
					sprintf_s(temp_speak,100,"%s%s���� �ݰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
					return temp_speak;
				}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���� ��������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s������ ���� �������ϴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s�ݰ��� �λ縦 �ߴ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
	case MON_SUNNY:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������������ ���� �ٰ��� �� �־�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ������ �ô밡 �°ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ ���� �ѵ� �������� �Ծ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� ������ �����ʴ°�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� ������ ���� ����ִ� �� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� �������� ����� ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
			break;
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ ���� ���� �� �ִٸ� �����ϰھ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��¥ ����ũ�� �����ְھ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case MON_LUNAR:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�������� ������ Ŀ�Ǹ� ���ð� �;�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� �����ϸ� �����̶� �� ���Ѱų�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�̷��� ��� �������� ó���ε�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�Ҹ��� ���̸� ������ ������ ���� �� �־�.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��� �ɾƼ� å�̶� ���� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ������ ������ �ְ���.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
			break;
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���ᰡ �Ǹ� �����������ž�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� �Ҷ� �Ѵٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���°� �Ⱦ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case MON_STAR:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ ���̸� �̷��� ���Ѱ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� ���, �̰��� ���� ����ᰡ\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�ֺ��� ���� ������ �־�, �� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ����ã�� ���Ƽ� ��ſ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� Ž�� �ɷ����� ��Ȯ�� ���� �� �� ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �԰� ���� �� ����? �������� �丮�� �ұ� �ϴµ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
			break;
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��� �� �ٴ°� �� �̵��ϰ� ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�������� ������ ������ �����ִ°ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�ܿ� ���ƿԾ�. ������ ��������������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case MON_CIRNO:		
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� ���� ���� �ʿ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� ��¥ ���� �����ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s��ſ��� �õ��������� �ڶ������� �ǳ����.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� �� �����ٰ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� ���� �ڿ� ������ �����ҰŶ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"Ư���� �� ���� ���Ϸ� �������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�̷��� �� ȥ�ڼ��� �����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������� �Ǽ�����! ��� �� �༮�� ����??\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case MON_CLOWNPIECE:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �Ҳ��� ���� �����ߴ� ����� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �� ���⸦!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ��վ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%sȶ���� �̸����� ���� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �� �ӵ��� �÷��� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�������� �����̴�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"�˰ھ�! �� ���� �� ��ſ�Ű���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"����! �糪ƽ Ÿ��!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case MON_LARVA:
		switch (type)
		{
		case FS_NORMAL:
			switch (randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100, "%s%s���ߴ�. \"�;�! ��� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100, "%s%s���ߴ�. \"���õ��� ���� �����귯!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 2:
				sprintf_s(temp_speak,100, "%s%s���ߴ�. \"�����δ� ����̴�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 3:
				sprintf_s(temp_speak,100, "%s%s����� �տ��� ���� ���� �߾���.", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 4:
				sprintf_s(temp_speak,100, "%s%s���ߴ�. \"���� �������� �� ����!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 5:
				sprintf_s(temp_speak,100, "%s%s���ߴ�. \"������ ��� ���?\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� ���� ���ϱ���! �� ��Ź��!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�� �������� �����̴�!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100, "%s%s���ƴ�. \"�ο�Ȱ!\"", monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	default:
		break;
	}





	switch(personal)
	{
	default:		
	case FP_NORMAL:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�峭�� �Ⱦ��ϴ� ������ ����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�������� ���� ���̵带 �غ��� ������ �����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"� �峭�� ĥ������ ������ ���� ��վ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�츰 �ְ��� ���̾�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���ο� ģ����� �����°� �׻� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ �̹ڹ��� ���� �ô븦 ���Ͽ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ������ �� �� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"������ ���Ͽ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ �����ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case FP_SHY:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"����... ����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���� ������ �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ɽ����� ���ߴ�. \"���� ���� �ǰ� ����?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s��ſ��� ������ �ü��� ������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"����������...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s������ ",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ݰ� ���� ��������.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"...������ �غ���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��Ȱ�� �� �־ �״°� �Ⱦ�...\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case FP_BRAVE:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ �츱 ���� �� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� �� �� ���� ������ ���� �ʾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �ο�°� ���� ��վ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��, ���� ���� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �ְ��� �ɰž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ ������ �����ϴ°ž�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s�ڽ��ְ� ���ƴ�. \"�������� ������ �ð�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"���� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ������! ���� ���ƿԾ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case FP_COLD:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ������ �Ӹ��� ���� �ô��.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s������ �ִ� å�� �а� �ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� ������ �˸� ��뵵 ����ž�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"������ �ִ� ������ �׻� üũ�ϰ��־�?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�� �� �ϰ��־�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"����� ���� ���� ����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"����. ���� �����ٰ�\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"�˰ھ� �� ������� ����\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��� ���� �Ǽ�����.\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	case FP_ANNOY:
		switch(type)
		{
		case FS_NORMAL:
			switch(randA(5))
			{
			case 0:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"����! ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			case 1:
				sprintf_s(temp_speak,100,"%s%s���ž��� �����ϰ��ִ�.",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;		
			case 2:
				sprintf_s(temp_speak,100,"%s%s��ſ��� �����̸� ���о���. \"���� �ֿ� ������!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 3:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��մ� �峭�� ���ö���!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 4:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��������, ���ڲ������� ������?\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;			
			case 5:
				sprintf_s(temp_speak,100,"%s%s���ߴ�. \"��վ�! ��վ�!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
				return temp_speak;
			}
		case FS_ENTER:
			sprintf_s(temp_speak,100,"%s%s���ƴ�. \"��������, ���ϰ� ���??\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_FAIRY_WAR:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���ο� ���̾�? ���� ���� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		case FS_REVIVE:
			sprintf_s(temp_speak,100,"%s%s���ߴ�. \"���� �� ������? ��� ����!\"",monster_info->GetName()->name.c_str(), monster_info->GetName()->name_is(true));
			return temp_speak;
		}
		break;
	}
	
	return "<���� ���� �����޼���>";

}



void GetFairyExp(int exp)
{
	int enter_ = 0;
	for(auto it = env[current_level].mon_vector.begin(); it != env[current_level].mon_vector.end();it++)
	{
		for(int i = 0; i<5;i++)
		{
			if(you.god_value[GT_LILLY][i] == 1)
			{
				if(it->isLive() && (*it).isUserAlly() && it->map_id == you.lilly_allys[i].map_id && current_level == you.lilly_allys[i].floor)
				{				
					you.lilly_allys[i].exp += exp;

					while(level_up_value[you.lilly_allys[i].level-1] <= you.lilly_allys[i].exp)
					{
						you.lilly_allys[i].level++;

						while(you.lilly_allys[i].level> it->level)
						{
							it->LevelUpdown(1,6.0f,1.0f);
							if(it->isYourShight())
							{
								printarray(false,false,false,CL_normal,3,it->name.name.c_str(),it->name.name_is(true),"��������. ");
								enter_++;
								if(enter_>=4)
									enterlog();
							}
						}

						int prev_id = it->id;
						switch(it->id)
						{
						case MON_FAIRY_GREEN:
							if(it->level >= 5)
							{
								it->ChangeMonster(MON_FAIRY_GREEN_WARRIOR,M_FLAG_ALLY);
							}
							break;
						case MON_FAIRY_BLUE:
							if(it->level >= 7)
							{
								it->ChangeMonster(MON_FAIRY_BLUE_MAGICIAN,M_FLAG_ALLY);
							}
							break;
						case MON_FAIRY_RED:
							if(it->level >= 8)
							{
								it->ChangeMonster(MON_FAIRY_RED_COMMANDER,M_FLAG_ALLY);
							}
							break;
						case MON_FAIRY_GREEN_WARRIOR:
							if(it->level >= 12)
							{
								it->ChangeMonster(MON_FAIRY_HERO,M_FLAG_ALLY);
							}
							break;
						case MON_FAIRY_BLUE_MAGICIAN:
							if(it->level >= 10)
							{
								it->ChangeMonster(MON_FAIRY_SOCERER,M_FLAG_ALLY);
							}
							break;
						case MON_FAIRY_RED_COMMANDER:
							if(it->level >= 13)
							{
								it->ChangeMonster(MON_FAIRY_SUN_FLOWER,M_FLAG_ALLY);
							}
							break;
						case MON_SUNNY:
							if(it->level == 13)
							{
								it->spell_lists.push_back(spell(SPL_LASER,20));
							}
							break;
						case MON_LUNAR:
							if(it->level == 13)
							{
								it->spell_lists.push_back(spell(SPL_SMITE,20));
							}
							break;
						case MON_STAR:
							if(it->level == 13)
							{
								it->spell_lists.push_back(spell(SPL_HASTE_OTHER,20));
							}
							break;
						case MON_DIEFAIRY:
							if(it->level == 13)
							{
								it->spell_lists.push_back(spell(SPL_HEAL_OTHER,20));
							}
							break;
						case MON_LARVA:
							if (it->level == 13)
							{
								it->spell_lists.push_back(spell(SPL_VENOM_BOLT, 20));
							}
							break;
						}
						if(prev_id != it->id)
						{						
							you.lilly_allys[i].id = it->id;
							if(!(it->flag & M_FLAG_UNIQUE))
							{
								it->name.name = fairy_name[you.lilly_allys[i].name].name;
								it->name.name_type = fairy_name[you.lilly_allys[i].name].name_type;
							}
							if(it->isYourShight())
							{
								if(enter_>0)
								{
									enterlog();
									enter_ = 0;
								}
								printarray(true,false,false,CL_normal,6,"�׵��� ���� �������� ",mondata[prev_id].name.name.c_str(),"���� ",mondata[it->id].name.name.c_str(),mondata[it->id].name.name_do(true),"�Ǿ���.");
								
							}
						}					
					}
				}
			}
		}
	}
	enterlog();
}






