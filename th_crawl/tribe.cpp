//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: tribe.h
//
// ����: ���� ����
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "tribe.h"
#include "enum.h"
#include "player.h"
#include "skill.h"
#include "save.h"
#include "skill_use.h"
#include "key.h"
#include "note.h"
#include "environment.h"
extern HANDLE mutx;



void tribe_property::SaveDatas(FILE *fp)
{
	SaveData<tribe_proper_type>(fp, id);
	SaveData<int>(fp, value);

}
void tribe_property::LoadDatas(FILE *fp)
{
	LoadData<tribe_proper_type>(fp, id);
	LoadData<int>(fp, value);
}


string getTribeProperty(tribe_proper_type id, int value) {
	return tribe_property(id, value).GetName();
}

string tribe_property::GetName()
{
	switch(id)
	{
	case TPT_FIRE_RESIST:
		return "ȭ������";
	case TPT_COLD_RESIST:
		return "�ñ�����";
	case TPT_ELEC_RESIST:
		return "��������";
	case TPT_POISON_RESIST:
		return "������";
	case TPT_STEALTH:
		return "������";
	case TPT_FLY:
		return "����";
	case TPT_SWIM:
		return "����";
	case TPT_SIZE:
		{
			switch(value)
			{
			case 1:
				return "�Ŵ������";
			case -1:
				return "�̴ϻ�����";
			default:
				return "���׻�����";
			}
		}
	case TPT_HORN:
		return "��";
	case TPT_GHOST_FOOT:
		return "���ɴٸ�";
	case TPT_CHEUKUMOGAMI:
		return "����𰡹�";
	case TPT_HP:
		{
			switch(value)
			{
			case 3:
				return "ü������(+30%)";
			case 2:
				return "ü������(+20%)";
			case 1:
				return "ü������(+10%)";
			case -1:
				return "ü������(-10%)";
			case -2:
				return "ü������(-20%)";
			case -3:
				return "ü������(-30%)";
			default:
				return "���׻�����";
			}
		}
	case TPT_INVISIBLE:
		return "��������";
	case TPT_POWER_SAVE:
		{
			switch(value)
			{
			case 1:
				return "�Ŀ�����";
			case -1:
				return "�ǿ� ���ָ�";
			default:
				return "�����Ŀ�";
			}
		}
	case TPT_9_LIFE:
		return "��������";
	case TPT_18_LIFE:
		return "��������";
	case TPT_SPEED:
		{
			switch(value)
			{
			case 1:
				return "��ø��";
			case -1:
				return "����";
			default:
				return "�����̼�";
			}
		}
	case TPT_CLAW:
		return "����";		
	case TPT_JAW:
		return "���� ��";	
	case TPT_FOOT:
		return "���� �ٸ�";
	case TPT_EYE:
		return "�پ ��";
	case TPT_FUR:
		return "ǫ���� ��";
	case TPT_REGEN:
		{
			switch(value)
			{
			case 1:
			case 2:
			case 3:
				return "���� �����";	
			case -1:
			case -2:
			case -3:
				return "���� �����";
			default:
				return "�������";
			}
		}
	case TPT_SLAY:
		return "��������";
	case TPT_CONFUSE_ATTACK:
		return "�����";
	case TPT_MAGIC_RESIST:
		return "��������";
	case TPT_SKIN_AC:
		return "���� �Ǻ�";
	case TPT_STR:
		return "������";
	case TPT_EV:
		return "ȸ������";
	case TPT_CLOUD:
		return "���� ��Ʈ��";
	case TPT_BREATH:
		return "�극��";
	case TPT_SCALE:
		return "���";
	case TPT_GRAZE_CONTROL:
		return "������ �帧";
	case TPT_FORCE_OF_NATURE:
		return "�ڿ��� ��";
	case TPT_MP_REGEN:
		{
			switch(value)
			{
			case 1:
				return "���� ȸ�� ����";
			case -1:
				return "���� ȸ�� ����";
			default:
				return "���׿���ȸ��";
			}
		}
	case TPT_CONFUSE_RESIST:
		return "ȥ�� ����";
	case TPT_SPELL_POWER:
		return "��ȭ ����";
	case TPT_FINGER_MAGIC:
		return "���� ����";
	case TPT_BLOOD_MAGIC:
		return "���� ����";
	case TPT_TORMENT:
		return "������ ����";
	case TPT_CLOUD_RESIST:
		return "���� ����";
	case TPT_SEE_INVI:
		return "���� ����";
	case TPT_FIRE_IMUNE:
		return "ȭ�� �鿪";
	case TPT_COLD_IMUNE:
		return "�ñ� �鿪";
	case TPT_ELEC_IMUNE:
		return "���� �鿪";
	case TPT_PURE_MP:
		return "������ ����";
	case TPT_PURE_POWER:
		return "������ �Ŀ�";
	case TPT_PURE_LIFE:
		return "������ ����";
	case TPT_PURE_SYSTEM:
		return "������ �ý���";
	}
	return "����Ư��";
}
string tribe_property::GetInfor()
{
	switch(id)
	{
	case TPT_FIRE_RESIST:
		{
			switch(value)
			{
			case 3:
			case 2:
				return "����� ȭ���� ���� ���ϴ�.";
			case 1:
				return "����� ȭ���� ���ϴ�.";
			case -1:
				return "����� ȭ���� ���ϴ�";
			case -2:
			case -3:
				return "����� ȭ���� ���� ���ϴ�";
			default:
				return "����ȭ������";
			}
		}
	case TPT_COLD_RESIST:
		{
			switch(value)
			{
			case 3:
			case 2:
				return "����� �ñ⿡ ���� ���ϴ�.";
			case 1:
				return "����� �ñ⿡ ���ϴ�.";
			case -1:
				return "����� �ñ⿡ ���ϴ�";
			case -2:
			case -3:
				return "����� �ñ⿡ ���� ���ϴ�";
			default:
				return "���׳ñ�����";
			}
		}
	case TPT_ELEC_RESIST:
		{
			switch(value)
			{
			case 3:
			case 2:
				return "����� ���⿡ ���� ���ϴ�.";
			case 1:
				return "����� ���⿡ ���ϴ�.";
			case -1:
				return "����� ���⿡ ���ϴ�";
			case -2:
			case -3:
				return "����� ���⿡ ���� ���ϴ�";
			default:
				return "������������";
			}
		}
	case TPT_POISON_RESIST:
		return "����� ���� ���ϴ�.";
	case TPT_STEALTH:
		{
			switch(value)
			{
			case 3:
				return "����� �����ϰ� �����δ�.(+3)";
			case 2:
				return "����� �����ϰ� �����δ�.(+2)";
			case 1:
				return "����� �����ϰ� �����δ�.(+1)";
			case -1:
			default:
				return "��������";
			}
		}	
	case TPT_FLY:
		return "����� ū ������ ������.";
	case TPT_SWIM:
		return "����� ������ �� �ִ�.";
	case TPT_SIZE:
		{
			switch(value)
			{
			case 1:
				return "����� ������ Ŀ�� ū ������ ���� �� �´´�.";
			case -1:
				return "����� ������ �۾Ƽ� ū ������ ���� �� �´´�.";
			default:
				return "����� ������ ���״�.";
			}
		}
	case TPT_HORN:
		return "����� �Ӹ��� ���� �޷��ִ�.";
	case TPT_GHOST_FOOT:
		return "����� �����̱⿡ �ٸ��� ����.";
	case TPT_CHEUKUMOGAMI:
		return "����� ��ü�� �����̴�.";
	case TPT_HP:
		{
			switch(value)
			{
			case 3:
				return "����� �ſ� ưư�ϴ�.(ü�� +30%)";
			case 2:
				return "����� �� ưư�ϴ�.(ü�� +20%)";
			case 1:
				return "����� ưư�ϴ�.(ü�� +10%)";
			case -1:
				return "����� �����ϴ�.(ü�� -10%)";
			case -2:
				return "����� �� �����ϴ�.(ü�� -20%)";
			case -3:
				return "����� �ſ� �����ϴ�.(ü�� -30%)";
			default:
				return "���׻�����";
			}
		}
	case TPT_INVISIBLE:
		return "���ǽ��� ����� �׻� ���������ִ�.";
	case TPT_POWER_SAVE:
		{
			switch(value)
			{
			case 1:
				return "����� P�� �ڿ��Ҹ� ������.";
			case -1:
				return "����� P�� ���ַ� �ִ�.";
			default:
				return "�����Ŀ�";
			}
		}
	case TPT_9_LIFE:
		return "����� 9���������� �ѹ� ��Ȱ�� �� �ִ�.";
	case TPT_18_LIFE:
		return "����� 18���������� �ѹ� ��Ȱ�� �� �ִ�.";
	case TPT_SPEED:
		{
			switch(value)
			{
			case 1:
				return "����� �̵��ӵ��� ������.";
			case -1:
				return "����� �̵��ӵ��� ������.";
			default:
				return "�����̼�";
			}
		}
	case TPT_CLAW:
		{
			switch(value)
			{
			case 3:
				return "����� ������ ���� ���.";
			case 2:
				return "����� ������ ����� ���.";
			case 1:
				return "����� ������ ���.";
			default:
				return "���׼���";
			}
		}	
	case TPT_JAW:
		return "����� ���� ���� �����.";	
	case TPT_FOOT:
		return "����� �����ϱ� ����� ���� �ٸ��� �����.";
	case TPT_EYE:
		return "����� �پ ���� ������.";
	case TPT_FUR:
		return "����� ǫ���� �з� �����ִ�. (AC+3, �ñ����� 1�ܰ�)";
	case TPT_REGEN:
		{
			switch(value)
			{
			case 3:
				return "����� ü�� ������� ����.(+3)";
			case 2:
				return "����� ü�� ������� ����.(+2)";
			case 1:
				return "����� ü�� ������� ����.(+1)";
			case -1:
				return "����� ü�� ������� ����.(-1)";
			default:
				return "���������";
			}
		}	
	case TPT_SLAY:
		return "����� ���ݰ� ���и� �ٷ�� ���������� �پ��.";
	case TPT_CONFUSE_ATTACK:
		return "����� ������ ���� ����� �㸦 ���.";
	case TPT_MAGIC_RESIST:
		return "����� �������׷��� ����.";
	case TPT_SKIN_AC:
		return "����� ���� �Ǻθ� �����. (AC+5)";
	case TPT_STR:
		return "����� ���� ���� �����.(��+5)";
	case TPT_EV:
		return "����� �ʿ����� ȸ������� �ִ�. (EV+10)";
	case TPT_CLOUD:
		return "����� ������ ���� �ٴѴ�.";
	case TPT_BREATH:
		return "����� �극���� �� �� �ִ�.";
	case TPT_SCALE:
		{
			switch(value)
			{
			case 3:
				return "����� ���� �ܴ��� ��÷� �����ִ�. (AC+9)";
			case 2:
				return "����� �β��� ��÷� �����ִ�. (AC+6)";
			case 1:
				return "����� ��÷� �����ִ�. (AC+3)";
			default:
				return "���׺��";
			}
		}	
	case TPT_GRAZE_CONTROL:
		return "����� ������ �帧�� �ٷ�� �Ϳ� ���ϴ�. (�׷����ȭ)";
	case TPT_FORCE_OF_NATURE:
		return "����� ���� �ڿ��� ���� �θ��� �ִ�.";
	case TPT_MP_REGEN:
		{
			switch(value)
			{
			case 3:
				return "����� ���� ������� ����.(+3)";
			case 2:
				return "����� ���� ������� ����.(+2)";
			case 1:
				return "����� ���� ������� ����.(+1)";
			case -1:
				return "����� ���� ������� ����.(-1)";
			default:
				return "���������";
			}
		}	
	case TPT_CONFUSE_RESIST:
		return "����� ȥ���� ������ �ִ�.";
	case TPT_SPELL_POWER:
		return "����� ���� ������ ���� ����������.";
	case TPT_FINGER_MAGIC:
		return "����� �������� ������ �� �� �ִ�.";
	case TPT_BLOOD_MAGIC:
		return "����� ������ ��� �Ǹ� �̿��Ͽ� ������ �� �� �ִ�.";
	case TPT_TORMENT:
		return "����� ������ ������ �ҷ��� �� �ִ�.";
	case TPT_CLOUD_RESIST:
		return "����� ������ ������ ���� �޴´�.";
	case TPT_SEE_INVI:
		return "����� ������ �� �� �ִ�.";
	case TPT_FIRE_IMUNE:
		return "����� ȭ���� �鿪�̴�.";
	case TPT_COLD_IMUNE:
		return "����� �ñ⿡ �鿪�̴�.";
	case TPT_ELEC_IMUNE:
		return "����� ���⿡ �鿪�̴�.";
	case TPT_PURE_MP:
		return "����� ü�°� ������ ���Ͻ� �ȴ�.";
	case TPT_PURE_POWER:
		return "����� �׻� Ǯ�Ŀ���.";
	case TPT_PURE_LIFE:
		return value>1?"����� 2���� �߰� ������ �����ִ�.":"����� 1���� �߰� ������ �����ִ�."; 
	case TPT_PURE_SYSTEM:
		return "����� ��ȭ ���¿����� ����ī�带 ����� �� ������ ������ �����ӵ��� 3�谡 �ȴ�.";
	}
	return "�� Ư���� ���״�.";
}
string tribe_property::GetDetail()
{
	switch(id)
	{
	case TPT_FIRE_RESIST:
		{
			switch(value)
			{
			case 3:
				return "ȭ�� ������ 3�ܰ� �����Ѵ�.";
			case 2:
				return "ȭ�� ������ 2�ܰ� �����Ѵ�.";
			case 1:
				return "ȭ�� ������ 1�ܰ� �����Ѵ�.";
			case -1:
				return "ȭ�� ������ 1�ܰ� �����Ѵ�.";
			case -2:
				return "ȭ�� ������ 2�ܰ� �����Ѵ�.";
			case -3:
				return "ȭ�� ������ 3�ܰ� �����Ѵ�.";
			default:
				return "����ȭ������";
			}
		}
	case TPT_COLD_RESIST:
		{
			switch(value)
			{
			case 3:
				return "�ñ� ������ 3�ܰ� �����Ѵ�.";
			case 2:
				return "�ñ� ������ 2�ܰ� �����Ѵ�.";
			case 1:
				return "�ñ� ������ 1�ܰ� �����Ѵ�.";
			case -1:
				return "�ñ� ������ 1�ܰ� �����Ѵ�.";
			case -2:
				return "�ñ� ������ 2�ܰ� �����Ѵ�.";
			case -3:
				return "�ñ� ������ 3�ܰ� �����Ѵ�.";
			default:
				return "���׳ñ�����";
			}
		}
	case TPT_ELEC_RESIST:
		{
			switch(value)
			{
			case 3:
				return "���� ������ 3�ܰ� �����Ѵ�.";
			case 2:
				return "���� ������ 2�ܰ� �����Ѵ�.";
			case 1:
				return "���� ������ 1�ܰ� �����Ѵ�.";
			case -1:
				return "���� ������ 1�ܰ� �����Ѵ�.";
			case -2:
				return "���� ������ 2�ܰ� �����Ѵ�.";
			case -3:
				return "���� ������ 3�ܰ� �����Ѵ�.";
			default:
				return "������������";
			}
		}
	case TPT_POISON_RESIST:
		return "�� ������ �����Ѵ�.";
	case TPT_STEALTH:
		return "���е��� ������. ������ ������ ��ġ��ŭ ��������.";
	case TPT_FLY:
		return "������ �ɷ��� ���� Ű�� �� �� �ִ�.";
	case TPT_SWIM:
		return "���� �������� ����ó�� �̵��� �ٴ� �� �ִ�.";
	case TPT_SIZE:
		{
			switch(value)
			{
			case 1:
				return "õ�� ���� �̿��� ���� ���� ���� �� ����.\n���� ����� ū ������� ���� ȸ�ǿ� �г�Ƽ�� �ش�.";
			case -1:
				return "õ�� ���� �̿��� ���� ���� ���� �� ����.\n�׷��� ����� ���� ������� ȸ�ǿ� ���ʽ��� �ش�.";
			default:
				return "õ�� ���� �̿��� ���� ���� ���Ա� ���� ���״�.\n�����ڿ��� �Ű�����.";
			}
		}
	case TPT_HORN:
		return "�Կ� ���� ��ġ�� ������ �߰��ȴ�.\n�� ���ݸ��� ����Ȯ���� ��ġ�Ⱑ ������ �Ǽ����� �οﶧ �� ���� Ȯ���� ������.\n�Ӹ����� ������ �� ����.";
	case TPT_GHOST_FOOT:
		return "����� �ٸ��� ����ó�� ���������ʴ´�.\n�ٸ����� ������ �� ����.";
	case TPT_CHEUKUMOGAMI:
		return "����� ��ü�� ������ ���� �� ����.\n����� ��ü�� �տ� ��� ������ �� ���� ������ ��ų�� 5�����ϴ� ���ʽ��� �޴´�.";
	case TPT_HP:
		return "����� ���������� ü���� �����Ǿ��ִ�.\n���� ü��ġ�� ��ġ��ŭ ��������.";
	case TPT_INVISIBLE:
		return "���������϶��� ����� ��� ������ �����Ѵ�.\n���� ����� ������ �õ��ϸ� ������ Ǯ����.";
	case TPT_POWER_SAVE:		
		{
			switch(value)
			{
			case 1:
				return "���� ������ ���� �Ҹ�Ǵ� P�� �ڿ� �������� �پ���.\n���� ���Ӱ� ���� ���� P �Ҹ����� �����Ѵ�.";
			case -1:
				return "���� ������ ���� �Ҹ�Ǵ� P�� �ڿ� �������� �����Ѵ�.\n���� ���Ӱ� ���� ���� P �Ҹ����� �����Ѵ�.";
			default:
				return "�����Ŀ�";
			}
		}
	case TPT_9_LIFE:
		return "�׾����� ��� ü�°� ������ ȸ���ϰ� ū ���߰� �Բ� ��Ȱ�Ѵ�.\n�� �ɷ��� ���� 9�� �Ǹ� �������.";
	case TPT_18_LIFE:
		return "�׾����� ��� ü�°� ������ ȸ���ϰ� ū ���߰� �Բ� ��Ȱ�Ѵ�.\n�� �ɷ��� ���� 18�� �Ǹ� �������.";
	case TPT_SPEED:
		{
			switch(value)
			{
			case 1:
				return "�̵��� �ٸ� �������� 80%�� �����̸��� ������.";
			case -1:
				return "�̵��� �ٸ� �������� 120%�� �����̸� ������.";
			default:
				return "�̵��ӵ��� ����� ���� ���״�.\n�����ڿ��� �Ű�����.";
			}
		}
	case TPT_CLAW:
		return "�Ǽհ����� �߰� �������� �ش�.\n�尩�� �� �� ���� �ȴ�.";
	case TPT_JAW:
		return "�� ���ݸ��� ����Ȯ���� ������ ������ ����.";	
	case TPT_FOOT:
		return "�Ŀ��� ����Ͽ� ������ ���İ��� �����ؼ� ������ �� �ִ�.\n���� ����� �Ұ����ϴ�.";
	case TPT_EYE:
		return "������ ���� �� �� �ִ�.";
	case TPT_FUR:
		return "������ 3�����ϰ� �ñ⿡ ���� ������ 1�ܰ� ��´�.";
	case TPT_REGEN:
		{
			switch(value)
			{
			case 3:
			case 2:
			case 1:
				return "ü�� ������� ����.\n�÷��� ��ġ�� �������� ȸ������ ��������.";
			case -1:
				return "ü�� ������� ����.\n���̳ʽ� ��ġ�� �������� ȸ������ ��������.";
			default:
				return "ü�� ������� ����� ���� ���״�.\n�����ڿ��� �Ű�����.";
			}
		}
	case TPT_SLAY:
		return "+6�� ������ ���ʽ��� ���� ��ġ�� ���ʽ��� �޴´�.";
	case TPT_CONFUSE_ATTACK:
		return "�������ݽ� ���� ����� �㸦 �񷯼� ȥ���� ���߸���.\n";
	case TPT_MAGIC_RESIST:
		return "�������׷��� �����Ѵ�.";
	case TPT_SKIN_AC:
		return "������ 5 �����Ѵ�.";
	case TPT_STR:
		return "���� 5 �����Ѵ�.";
	case TPT_EV:
		return "ȸ�ǰ� 10 �����Ѵ�.";
	case TPT_CLOUD:
		return "���� Ư������ �����Ǿ��ִ� �Ӽ� ������ �鿪�̴�.\n���� ���ݴ��Ҷ� �ش� �Ӽ��� ������ ��Ѹ���.\n";
	case TPT_BREATH:
		return "����� ���� Ư������ �����Ǿ��ִ� �Ӽ� �극���� �� �� �ִ�.";
	case TPT_SCALE:
		{
			switch(value)
			{
			case 3:
				return "���� �ܴ��� ��ÿ� ���� ������ 9 �����Ѵ�.";
			case 2:
				return "�β��� ��ÿ� ���� ������ 6 �����Ѵ�.";
			case 1:
				return "��ÿ� ���� ������ 3 �����Ѵ�.";
			default:
				return "���׺��";
			}
		}	
	case TPT_GRAZE_CONTROL:
		return "�׷���� �ߵ��� �� �ְ�\n �׷������� ȿ���� 2��� �����Ѵ�.";
	case TPT_FORCE_OF_NATURE:
		return "�������ݿ� ���� ���� Ư������ �����Ǿ��ִ� �Ӽ����� �ݰ��� �Ѵ�.\n���� �ش� �Ӽ��� �鿪�� ���� ���̸� ������ �� ���� ������ �Ǵ�.";
	case TPT_MP_REGEN:
		{
			switch(value)
			{
			case 3:
			case 2:
			case 1:
				return "���� ������� ����.\n�÷��� ��ġ�� �������� ȸ������ ��������.";
			case -1:
				return "���� ������� ����.\n���̳ʽ� ��ġ�� �������� ȸ������ ��������.";
			default:
				return "���� ������� ����� ���� ���״�.\n�����ڿ��� �Ű�����.";
			}
		}
	case TPT_CONFUSE_RESIST:
		return "ȥ���� ���� ���׷��� �����.\n���� ���⿡�� �鿪�� �ȴ�.";
	case TPT_SPELL_POWER:
		return "��� ������ �Ŀ��� 1.3�谡 �ȴ�.";
	case TPT_FINGER_MAGIC:
		return "���� ��뿡 ���� ������ 70%�� �پ���.\nħ�������� ������ ����� �� �ִ�.";
	case TPT_BLOOD_MAGIC:
		return "������ �����Ҷ� ������ ����ϸ� ������ 2�踸ŭ ü���� �Ҹ��Ͽ� ������ �� �� �ִ�.";
	case TPT_TORMENT:
		return "�Ŀ��� 1ĭ �Ҹ��Ͽ� �þ߳��� �ִ� ��� ���� ������ ü���� �������� �Ѵ�.";
	case TPT_CLOUD_RESIST:
		return "�ڿ����� �� ��ü�� ����� ���� ������ ������ ���� �޴´�.\n�������� ���� �޴� �������� ������ �ȴ�.";
	case TPT_SEE_INVI:
		return "������ ���� �� �� �ְ� �ȴ�.";
	case TPT_FIRE_IMUNE:
		return "����� ��ȣ�� �ູ���� ȭ���� �鿪�̱⿡ ȭ�� �Ӽ��� �������� ���� �ʴ´�.";
	case TPT_COLD_IMUNE:
		return "����� ��ȣ�� �ູ���� �ñ⿡ �鿪�̱⿡ �ñ� �Ӽ��� �������� ���� �ʴ´�.";
	case TPT_ELEC_IMUNE:
		return "����� ��ȣ�� �ູ���� ���⿡ �鿪�̱⿡ ���� �Ӽ��� �������� ���� �ʴ´�.";
	case TPT_PURE_MP:
		return "����� ��ȣ�� �ູ���� ���°� ü���� ���Ͻ� �Ǿ���.\nü�°� ������ ������ ��ġ�� �����Ǿ� �������� ������, ������ ����Ҷ� ����� �� �ִ�.\n���� ������ ü��ȸ���°� ����ȸ������ �ջ�Ǿ� �� ���� ȸ���� �ϰԵȴ�.";
	case TPT_PURE_POWER:
		return "����� ��ȣ�� �ູ���� �׻� Ǯ�Ŀ�����̸� ���������ʴ´�.";
	case TPT_PURE_LIFE:
		return value>1 ? "����� ��ȣ�� �ູ���� �׾ �ٽ� ��Ȱ�� �� �ִ�.\n��, ��ȣ�� ����Ͽ� ���� ������ �� �ູ���� ��Ⱑ �Ұ����ϴ�.\n����� �߰� ������ 2�� ���Ҵ�." : 
			"����� ��ȣ�� �ູ���� �׾ �ٽ� ��Ȱ�� �� �ִ�.\n��, ��ȣ�� ����Ͽ� ���� ������ �� �ູ���� ��Ⱑ �Ұ����ϴ�.\n����� �߰� ������ 1�� ���Ҵ�.";
	case TPT_PURE_SYSTEM:
		return "����� ��ȣ�� �ູ���� ���� �ý��ۿ��� ������ ������ ȿ���� ��ȭ�Ǿ���.\n������ ��ȭ���¿����� ����ī�尡 ����� �����ϰ� �Ǿ���.\n����, ���ú��� ������ �����ӵ��� 3��� �������Եȴ�.";
	}
	return "�� Ư���� �����̹Ƿ� ������ü�� �ؾ��̴�.\n�����ڿ��� �Ű�����.";
}

D3DCOLOR tribe_property::getColor()
{

	switch (id)
	{
	case TPT_FIRE_IMUNE:
	case TPT_COLD_IMUNE:
	case TPT_ELEC_IMUNE:
	case TPT_PURE_MP:
	case TPT_PURE_POWER:
	case TPT_PURE_LIFE:	
	case TPT_PURE_SYSTEM:
		return CL_junko;
	}
	return CL_STAT;
}
void tribe_property::gain(bool gain_)
{
	int value_ = gain_?value:-value;
	switch(id)
	{
	case TPT_FIRE_RESIST:
		you.ResistUpDown(value_,RST_FIRE);
		return;
	case TPT_COLD_RESIST:
		you.ResistUpDown(value_,RST_ICE);
		return;
	case TPT_ELEC_RESIST:
		you.ResistUpDown(value_,RST_ELEC);
		return;
	case TPT_POISON_RESIST:
		you.ResistUpDown(value_,RST_POISON);
		return;
	case TPT_STEALTH:
		return;
	case TPT_FLY:
		{
			int temp = you.Ability(SKL_LEVITATION_OFF,false,true);
			you.Ability(SKL_LEVITATION,false,value<=0,value>0?(temp>0?temp+1:0):0);
			if(value<=0 && temp == 1 && you.s_levitation)
			{
				you.s_levitation=0;
			}
			return;
		}
	case TPT_SWIM:
		return;
	case TPT_SIZE:
		return;
	case TPT_HORN:
		if(you.equipment[ET_HELMET])
		{
			if(you.unequip(ET_HELMET, true))
			{
				printlog("����� �����ִ� �Ӹ����� ��������!",true,false,false,CL_danger);
			}
		}
		return;
	case TPT_GHOST_FOOT:
		if(you.equipment[ET_BOOTS])
		{
			if(you.unequip(ET_BOOTS,true))
			{
				printlog("����� �����ִ� �ٸ����� ��������!",true,false,false,CL_danger);
			}
		}
		return;
	case TPT_CHEUKUMOGAMI:
		return;
	case TPT_INVISIBLE:
		you.SetTogleInvisible(false);
		return;
	case TPT_POWER_SAVE:
		you.ResistUpDown(value_,RST_POWER);
		return;	
	case TPT_9_LIFE:
		return;
	case TPT_18_LIFE:
		return;
	case TPT_SPEED:
		return;
	case TPT_CLAW:
		if(you.equipment[ET_GLOVE])
		{
			if(you.unequip(ET_GLOVE,true))
			{
				printlog("����� �����ִ� �չ��� ��������!",true,false,false,CL_danger);
			}
		}
		return;
	case TPT_JAW:
		return;
	case TPT_FOOT:
		you.Ability(SKL_JUMPING_ATTACK,true,!gain_);
		return;
	case TPT_EYE:
		you.ResistUpDown(value_,RST_INVISIBLE);
		return;
	case TPT_FUR:
		you.AcUpDown(0,value_>0?3:-3);		
		you.ResistUpDown(value_,RST_ICE);
		return;
	case TPT_REGEN:
		return;
	case TPT_SLAY:
		you.ShUpDown(0, 0);
		return;
	case TPT_CONFUSE_ATTACK:
		return;
	case TPT_MAGIC_RESIST:
		you.MRUpDown((value_>0?40:-40));
		return;
	case TPT_SKIN_AC:
		you.AcUpDown(0,value_>0?5:-5);	
		return;
	case TPT_STR:
		you.StatUpDown(value_>0?6:-6, STAT_STR);
		return;
	case TPT_EV:
		you.EvUpDown(0,value_>0?10:-10);
		return;
	case TPT_CLOUD:
		return;
	case TPT_BREATH:
		you.Ability(SKL_BREATH,true,!gain_);
		return;
	case TPT_SCALE:
		you.AcUpDown(0,value_*3);	
		return;
	case TPT_GRAZE_CONTROL:
		{	
			int temp = you.Ability(SKL_GRAZE_OFF,false,true); //�׷����� ������ �����ϰ� ���� ����
			temp += you.Ability(SKL_GRAZE,false,true); //�׷����� �ߵ��� �����ϰ� ���� ����

			temp+=value;

			if(!you.s_graze)
				you.SetGraze(-1);
			//int temp = you.Ability(SKL_GRAZE,false,true,1);
			//you.Ability(SKL_GRAZE_OFF,false,false,temp);
			you.Ability((you.s_graze || you.isGrazeAmulet())?SKL_GRAZE_OFF:SKL_GRAZE,false,temp<=0?true:false,temp);
			if(temp <= 0 && you.s_graze && !you.isGrazeAmulet())
			{
				you.s_graze=0; 
			}
		}
		return;
	case TPT_FORCE_OF_NATURE:
		return;
	case TPT_MP_REGEN:
		return;
	case TPT_CONFUSE_RESIST:
		you.ResistUpDown(value_,RST_CONFUSE);
		return;
	case TPT_SPELL_POWER:
		return;
	case TPT_FINGER_MAGIC:
		return;
	case TPT_BLOOD_MAGIC:
		return;
	case TPT_TORMENT:
		you.Ability(SKL_TORMENT,true,!gain_);
		return;
	case TPT_CLOUD_RESIST:
		return;
	case TPT_SEE_INVI:
		you.ResistUpDown(value_, RST_INVISIBLE);
		return;
	case TPT_FIRE_IMUNE:
		you.ResistUpDown(value_, RST_FIRE);
		return;
	case TPT_COLD_IMUNE:
		you.ResistUpDown(value_, RST_ICE);
		return;
	case TPT_ELEC_IMUNE:
		you.ResistUpDown(value_, RST_ELEC);
		return;
	case TPT_PURE_MP:
		if (value_)
			you.pure_mp = true;
		else
			you.pure_mp = false;
		return;
	case TPT_PURE_POWER:
		you.power = 1000;
		return;
	case TPT_PURE_LIFE:
		return;
	case TPT_PURE_SYSTEM:
		return;
	}
}


void PropertyView()
{
	int i=0;
	changedisplay(DT_PROPERTY);
	while(1)
	{
		int key_ = waitkeyinput(true);
		if( (key_ >= 'a' && key_ <= 'z') || (key_ >= 'A' && key_ <= 'Z') )
		{
			int num = (key_ >= 'a' && key_ <= 'z')?(key_-'a'):(key_-'A'+26);
			if(num < you.property_vector.size())
			{
				WaitForSingleObject(mutx, INFINITE);
				SetText() = "Ư�� : " + you.property_vector[num].GetName();
				SetText() += "\n\nȿ�� : " + you.property_vector[num].GetDetail();
				changedisplay(DT_TEXT);
				ReleaseMutex(mutx);
				waitkeyinput();
				changedisplay(DT_PROPERTY);
				changemove(0);
			}
			else
				break;
		}
		else if(key_ == VK_ESCAPE)
			break;
	}
	changedisplay(DT_GAME);
}




void SetTribe(tribe_type select_)
{
	switch(select_)
	{
	case TRI_HUMAN:
		break;
	case TRI_WIZARD:
		you.SetProperty(TPT_HP,-2);
		you.max_mp+=1;
		you.StatUpDown(-2,STAT_STR);
		you.StatUpDown(2,STAT_INT);
		break;
	case TRI_FAIRY:
		you.SetProperty(TPT_HP,-3);
		you.StatUpDown(-2,STAT_STR);
		you.StatUpDown(1,STAT_INT);
		you.StatUpDown(1,STAT_DEX);
		you.SetProperty(TPT_SIZE,-1);
		you.SetProperty(TPT_REGEN,1);
		you.SetProperty(TPT_MP_REGEN,1);
		you.SetProperty(TPT_STEALTH,1);	
		you.SetProperty(TPT_CLOUD_RESIST,1);		
		break;
	case TRI_CROWTENGU:
		you.StatUpDown(-1,STAT_INT);
		you.StatUpDown(1,STAT_DEX);
		you.SetProperty(TPT_FLY,1);
		break;
	case TRI_WOLFTENGU:
		you.SetProperty(TPT_HP,1);
		you.StatUpDown(2,STAT_STR);
		you.StatUpDown(-1,STAT_INT);
		you.StatUpDown(-1,STAT_DEX);
		you.SetProperty(TPT_JAW,1);
		break;
	case TRI_KAPPA:
		you.SetProperty(TPT_HP,-1);
		you.SetProperty(TPT_SWIM,1);
		break;
	case TRI_NECOMATA:
		you.StatUpDown(-2,STAT_STR);
		you.StatUpDown(2,STAT_DEX);
		you.SetProperty(TPT_HP,-2);
		you.SetProperty(TPT_SPEED,1);
		you.SetProperty(TPT_CLAW,1);
		break;
	case TRI_OARFISH:
		you.SetProperty(TPT_HP,2);
		you.SetProperty(TPT_SPEED,-1);
		you.SetProperty(TPT_SWIM,1);
		you.SetProperty(TPT_ELEC_RESIST,1);
		you.SetProperty(TPT_SCALE,1);
		break;
	case TRI_CHEUKUMOGAMI:
		you.SetProperty(TPT_HP,-1);
		you.StatUpDown(1,STAT_STR);
		you.StatUpDown(-2,STAT_INT);
		you.StatUpDown(1,STAT_DEX);
		you.SetProperty(TPT_SIZE,-1);
		you.SetProperty(TPT_POISON_RESIST,1);
		//you.SetProperty(TPT_CHEUKUMOGAMI,1);
		break;
	case TRI_ONI:
		you.SetProperty(TPT_HP,3);
		you.StatUpDown(3,STAT_STR);
		you.StatUpDown(-2,STAT_INT);
		you.StatUpDown(-1,STAT_DEX);
		you.SetProperty(TPT_SIZE,1);
		you.SetProperty(TPT_HORN,1);
		break;
	case TRI_HALFYOKAI:
		you.half_youkai[0]=randA(3);
		you.half_youkai[1]=randA(2);
		you.half_youkai[2]=randA(2);
		you.half_youkai[3]=randA(1);
		//you.half_youkai[0]=2;
		//you.half_youkai[1]=2;
		//you.half_youkai[2]=0;
		//you.half_youkai[3]=1;
		break;
	case TRI_WRAITH:
		you.SetProperty(TPT_HP,1);
		you.SetProperty(TPT_COLD_RESIST,1);
		you.SetProperty(TPT_STEALTH,2);
		you.SetProperty(TPT_POISON_RESIST,1);
		you.SetProperty(TPT_GHOST_FOOT,1);
		break;
	case TRI_VAMPIRE:
		you.SetProperty(TPT_HP,1);
		you.SetProperty(TPT_REGEN,2);
		you.SetProperty(TPT_MP_REGEN,-1);
		you.SetProperty(TPT_POWER_SAVE,-1);
		you.SetProperty(TPT_EYE,1);
		you.SetProperty(TPT_BLOOD_MAGIC,1);
		break;
	}
	for(int i=0;i<SKT_MAX;i++)
		you.skill[i].aptit = aptitude[select_][i];
	you.exper_aptit = exp_aptitude[select_];
}

void LevelUpTribe(int level_)
{
	char temp[100];
	switch(you.tribe)
	{
	case TRI_HUMAN:
		if(level_%5 == 0)
		{
			randA(2)?(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX)):you.StatUpDown(1,STAT_INT);
		}
		break;
	case TRI_WIZARD:
		if(level_%4 == 0)
		{
			you.StatUpDown(1,STAT_INT);
		}
		you.max_mp++;
		you.mp++;
		break;
	case TRI_FAIRY:
		if(level_%5 == 0)
		{
			(randA(1)?you.StatUpDown(1,STAT_DEX):you.StatUpDown(1,STAT_INT));
		}
		if(level_%2 == 0)
		{
			you.max_mp++;
			you.mp++;
		}
		break;
	case TRI_CROWTENGU:
		if(level_%5 == 0)
		{
			(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX));
		}
		break;
	case TRI_WOLFTENGU:
		if(level_%4 == 0)
		{
			you.StatUpDown(1,STAT_STR);
		}
		if(level_%3 == 0)
		{
			you.max_mp--;
			you.mp--;
		}
		break;
	case TRI_KAPPA:
		if(level_%5 == 0)
		{
			randA(2)?(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX)):you.StatUpDown(1,STAT_INT);
		}
		break;
	case TRI_NECOMATA:
		if(level_%5 == 0)
		{
			you.StatUpDown(1,STAT_DEX);
		}
		if(level_%5 == 0)
		{
			you.max_mp--;
			you.mp--;
		}
		if(level_ == 15)
		{
			printlog("��ſ��� ǫ��ǫ���� ���� �ڶ󳵴�.",true,false,false,CL_small_danger);
			you.SetProperty(TPT_FUR,1);
		}
		break;
	case TRI_OARFISH:
		if(level_%5 == 0)
		{
			randA(2)?(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX)):you.StatUpDown(1,STAT_INT);
		}
		if(level_ == 9)
		{
			printlog("����� ����� �ܴ�������.",true,false,false,CL_small_danger);
			you.DeleteProperty(TPT_SCALE);
			you.SetProperty(TPT_SCALE,2);
		}
		if(level_ == 18)
		{
			printlog("����� ����� ���� �ܴ�������.",true,false,false,CL_small_danger);
			you.DeleteProperty(TPT_SCALE);
			you.SetProperty(TPT_SCALE,3);
		}
		break;
	case TRI_CHEUKUMOGAMI:
		if(level_%5 == 0)
		{
			(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX));
		}
		if(level_%5 == 0)
		{
			you.max_mp--;
			you.mp--;
		}
		break;
	case TRI_ONI:
		if(level_%3 == 0)
		{
			you.StatUpDown(1,STAT_STR);
		}
		if(level_%2 == 0)
		{
			you.max_mp--;
			you.mp--;
		}
		break;
	case TRI_HALFYOKAI:
		if(level_%5 == 0)
		{
			randA(2)?(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX)):you.StatUpDown(1,STAT_INT);
		}
		if(level_ == 4)
		{
			switch(you.half_youkai[0])
			{
			case 0:
				printlog("��ſ��� ������ �ǰ� �帣�� �ִ�! ����� Ư���� ���翡 �����ϴ�.",true,false,false,CL_small_danger);
				printlog("��ſ��� ������ �ڶ󳵴�.",true,false,false,CL_small_danger);
				you.SetProperty(TPT_CLAW,1);
				sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_CLAW, 1).c_str());
				AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
				break;
			case 1:
				printlog("��ſ��� ������ �ǰ� �帣�� �ִ�! ����� Ư���� ���� �������� �̾�����.",true,false,false,CL_small_danger);
				printlog("��ſ��� ���� �ڶ󳵴�.",true,false,false,CL_small_danger);
				you.SetProperty(TPT_HORN,1);
				sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_HORN, 1).c_str());
				AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
				break;
			case 2:
				printlog("��ſ��� ���� �ǰ� �帣�� �ִ�! ����� Ư���� �Ӽ��� �ٷ�µ� �ɼ��ϴ�.",true,false,false,CL_small_danger);
				printlog("��ſ��� ����� �ڶ󳵴�.",true,false,false,CL_small_danger);
				you.SetProperty(TPT_SCALE,1);
				sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_SCALE, 1).c_str());
				AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
				break;
			case 3:
				printlog("��ſ��� �Ǹ��� �ǰ� �帣�� �ִ�! ����� Ư���� ������뿡 ���ߵȴ�.",true,false,false,CL_small_danger);
				printlog("����� ����������� ��������.",true,false,false,CL_small_danger);
				you.SetProperty(TPT_MP_REGEN,1);
				sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_MP_REGEN, 1).c_str());
				AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
				break;
			}
		}
		if(level_ == 9)
		{
			switch(you.half_youkai[0])
			{
			case 0:
				switch(you.half_youkai[1])
				{
				case 0:	
					printlog("������ ������ ���� ��������. ��ſ��� ���� ���� �ڶ󳵴�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_JAW,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_JAW, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("������ ������ ���� ��������. ����� �ٸ��� �����Ҽ�������ŭ ��������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_FOOT,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_FOOT, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("������ ������ ���� ��������. ����� �÷��� ��������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_EYE,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_EYE, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 1:
				switch(you.half_youkai[1])
				{
				case 0:	
					printlog("������ ������ ���� ��������. ����� ưư������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_HP,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_HP, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("������ ������ ���� ��������. ����� ���� ������ �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_POISON_RESIST,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_POISON_RESIST, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("������ ������ ���� ��������. ����� ���������� ��������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_MAGIC_RESIST,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_MAGIC_RESIST, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 2:
				switch(you.half_youkai[1])
				{
				case 0:	
					printlog("���� ������ ���� ��������. ����� ȭ���� ������ �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_FIRE_RESIST,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_FIRE_RESIST, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("���� ������ ���� ��������. ����� �ñ⿡ ������ �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_COLD_RESIST,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_COLD_RESIST, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("���� ������ ���� ��������. ����� ���⿡ ������ �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_ELEC_RESIST,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_ELEC_RESIST, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 3:
				switch(you.half_youkai[1])
				{
				case 0:	
					printlog("�Ǹ��� ������ ���� ��������. ��ſ� ū ������ �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_FLY,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_FLY, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("�Ǹ��� ������ ���� ��������. ����� ��������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_CONFUSE_RESIST,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_CONFUSE_RESIST, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("�Ǹ��� ������ ���� ��������. ����� ����������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_STEALTH,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_STEALTH, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			}
		}
		
		if(level_ == 13)
		{
			switch(you.half_youkai[0])
			{
			case 0:
				switch(you.half_youkai[2])
				{
				case 0:	
					printlog("������ ������ ���� ��������. ��ſ��� ǫ��ǫ���� ���� �ڶ󳵴�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_FUR,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_FUR, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("������ ������ ���� ��������. ����� ���� ��������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_SPEED,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_SPEED, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("������ ������ ���� ��������. ����� ���� ������� �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_REGEN,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_REGEN, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 1:
				switch(you.half_youkai[2])
				{
				case 0:	
					printlog("������ ������ ���� ��������. ����� �Ǻδ� �ܴ�������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_SKIN_AC,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_SKIN_AC, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("������ ������ ���� ��������. ����� ���� ������� �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_REGEN,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_REGEN, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("������ ������ ���� ��������. ����� ��û�� ���� �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_STR,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_STR, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 2:
				switch(you.half_youkai[2])
				{
				case 0:	
					printlog("���� ������ ���� ��������. ����� ������ ���� �ٴѴ�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_CLOUD,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_CLOUD, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("���� ������ ���� ��������. ����� �Կ��� �극���� �� �� �ִ�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_BREATH,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_BREATH, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("���� ������ ���� ��������. ����� ����� ���� �β�������.",true,false,false,CL_small_danger);
					you.DeleteProperty(TPT_SCALE);
					you.SetProperty(TPT_SCALE,2);
					sprintf_s(temp, 100, "�ݿ� ���̰�ȭ: %s", getTribeProperty(TPT_SCALE, 2).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					switch(you.half_youkai[1])
					{
					case 0:
						you.DeleteProperty(TPT_FIRE_RESIST);
						you.SetProperty(TPT_FIRE_RESIST,2);
						sprintf_s(temp, 100, "�ݿ� ���̰�ȭ: %s", getTribeProperty(TPT_FIRE_RESIST, 2).c_str());
						AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
						break;
					case 1:
						you.DeleteProperty(TPT_COLD_RESIST);
						you.SetProperty(TPT_COLD_RESIST,2);
						sprintf_s(temp, 100, "�ݿ� ���̰�ȭ: %s", getTribeProperty(TPT_COLD_RESIST, 2).c_str());
						AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
						break;
					case 2:		
						you.DeleteProperty(TPT_ELEC_RESIST);		
						you.SetProperty(TPT_ELEC_RESIST,2);
						sprintf_s(temp, 100, "�ݿ� ���̰�ȭ: %s", getTribeProperty(TPT_ELEC_RESIST, 2).c_str());
						AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
						break;
					}
					break;
				}	
				break;
			case 3:
				switch(you.half_youkai[2])
				{
				case 0:	
					printlog("�Ǹ��� ������ ���� ��������. ����� ������ ���� ����������.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_SPELL_POWER,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_SPELL_POWER, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("�Ǹ��� ������ ���� ��������. ����� ���������� ������ ��â�� �� �ִ�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_FINGER_MAGIC,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_FINGER_MAGIC, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 2:
					printlog("�Ǹ��� ������ ���� ��������. ����� �ڽ��� �Ƿ� ������ ��â�� �� �ִ�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_BLOOD_MAGIC,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_BLOOD_MAGIC, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			}
		}
		
		if(level_ == 18)
		{
			switch(you.half_youkai[0])
			{
			case 0:
				switch(you.half_youkai[3])
				{
				case 0:	
					printlog("������ ������ Ư���� �����Ǿ���. ����� �������� ���������� �����ƴ�.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_SLAY,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_SLAY, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("������ ������ Ư���� �����Ǿ���. ����� �پ ������ ��븦 ȥ���ϰ� �����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_CONFUSE_ATTACK,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_CONFUSE_ATTACK, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 1:
				switch(you.half_youkai[3])
				{
				case 0:	
					printlog("������ ������ Ư���� �����Ǿ���. ����� �����ŭ ưư������.",true,false,false,CL_small_danger);
					if(you.half_youkai[1]==0)
					{
						you.DeleteProperty(TPT_HP);
						you.SetProperty(TPT_HP,3);
						sprintf_s(temp, 100, "�ݿ� ���̰�ȭ: %s", getTribeProperty(TPT_HP, 3).c_str());
						AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					}
					else {
						you.SetProperty(TPT_HP, 2);
						sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_HP, 2).c_str());
						AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					}
					break;
				case 1:
					printlog("������ ������ Ư���� �����Ǿ���. ����� �ʿ����� ȸ����ɿ� ���� ����.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_EV,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_EV, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 2:
				switch(you.half_youkai[3])
				{
				case 0:	
					printlog("���� ������ Ư���� �����Ǿ���. ����� ������ �帧�� �ٷ� �� �ְ� �Ǿ���.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_GRAZE_CONTROL,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_GRAZE_CONTROL, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("���� ������ Ư���� �����Ǿ���. ����� �ڿ��� ���� ���� �θ��� �Ǿ���.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_FORCE_OF_NATURE,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_FORCE_OF_NATURE, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			case 3:
				switch(you.half_youkai[3])
				{
				case 0:	
					printlog("�Ǹ��� ������ Ư���� �����Ǿ���. ����� �ʿ����� ����ȸ���ӵ��� �����.",true,false,false,CL_small_danger);
					you.DeleteProperty(TPT_MP_REGEN);
					you.SetProperty(TPT_MP_REGEN,3);
					sprintf_s(temp, 100, "�ݿ� ���̰�ȭ: %s", getTribeProperty(TPT_MP_REGEN, 3).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				case 1:
					printlog("�Ǹ��� ������ Ư���� �����Ǿ���. ����� ������ ������ �ҷ��� �� �ְ� �Ǿ���.",true,false,false,CL_small_danger);
					you.SetProperty(TPT_TORMENT,1);
					sprintf_s(temp, 100, "�ݿ� ���̹���: %s", getTribeProperty(TPT_TORMENT, 1).c_str());
					AddNote(you.turn, CurrentLevelString(), temp, CL_normal);
					break;
				}	
				break;
			}
		}
		break;
	case TRI_WRAITH:
		if(level_%5 == 0)
		{
			randA(2)?(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX)):you.StatUpDown(1,STAT_INT);
		}
		break;
	case TRI_VAMPIRE:
		if(level_%5 == 0)
		{
			you.max_mp--;
			you.mp--;
		}
		break;
	case TRI_YOKAI:
		if(level_%5 == 0)
		{
			randA(2)?(randA(1)?you.StatUpDown(1,STAT_STR):you.StatUpDown(1,STAT_DEX)):you.StatUpDown(1,STAT_INT);
		}
		if(level_ == 15 && you.char_name.name.compare("���̽�")==0)
		{
			printlog("����� �پ ������ ��븦 ȥ���ϰ� �����.",true,false,false,CL_small_danger);
			you.SetProperty(TPT_CONFUSE_ATTACK,1);
		}
		break;
	}
}