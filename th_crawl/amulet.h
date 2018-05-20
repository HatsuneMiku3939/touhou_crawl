//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: amulet.h
//
// ����: �ƹķ�
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __AMULET_H__
#define  __AMULET_H__


enum amulet_type
{
	AMT_PERFECT = 0, //��������, 100%�� �Ǹ� ��Ȱ
	AMT_BLOSSOM, //�����, 100%�� �Ǹ� ���ݹߵ�
	AMT_TIMES, //����, 100%�� �Ǹ� �Ŀ�����
	AMT_FAITH, //�ž�, 100%�� �Ǹ� �ڵ����� �ž� ����
	AMT_WAVE, //����, 100%�� �Ǹ� ����������� 100%�� �Ǹ� ����ȸ��
	AMT_SPIRIT, //�ŷ�, 100%�� �Ǹ� ����ī�� ����
	AMT_GRAZE, //�׷�����, 100%�� �Ǹ� �׷��������, �ߵ��� �ټ�ȸ��
	AMT_WEATHER, //����, ���� ������ ���� �ߵ� + ü������
	AMT_OCCULT, //����Ʈ, 100%�� �Ǹ� ��ȯ�� �߹氡�� + ��ȯ�ϱ�
	AMT_MAX,
};
//������ �����÷��̿� �°� �ٲٴ°� ���� �� ����
//�����(�ʹ� ���뼺�ִ� ���)
//���� (ü��) -> ������ ���� �ߵ� + ü������
//���� (����) -> �Ŀ�
//���� (����) -> ���� ����


enum occult_type
{
	OCT_NESI = 0,
	OCT_LONG,
	OCT_SHORT,
	OCT_DISH,
	OCT_KUNEKUNE,
	OCT_MAX
};


extern char *amulet_uniden_string[AMT_MAX];
extern const char *amulet_iden_string[AMT_MAX];


int isAmuletGotValue(amulet_type amulet_);
amulet_type goodbadamulet(int good_bad);
int isGoodAmulet(amulet_type kind, int value);
bool equipamulet(amulet_type kind, int value); //���ϰ�: �ĺ��� true �̽ĺ��� false
bool unidenequipamulet(amulet_type kind, int value); //���ϰ�: �ĺ��� true �̽ĺ��� false
float getAmuletCharge(amulet_type kind);
bool isCanCharge(amulet_type kind);
bool isCanEvoke(amulet_type kind);
bool chargingFinish(amulet_type kind, int value);
bool evokeAmulet(amulet_type kind, int value_);
const char* getOccultName(occult_type kind);

#endif // __AMULET_H__
