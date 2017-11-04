//////////////////////////////////////////////////////////////////////////////////////////////////
//
// 파일이름: amulet.cpp
//
// 내용: 부적
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "amulet.h"
#include "common.h"
#include "const.h"
#include "display.h"
#include "player.h"
#include "skill_use.h"
#include "environment.h"


char *amulet_uniden_string[AMT_MAX+2] =
{
	"쥐가 그려진 ",
	"소가 그려진 ",
	"호랑이가 그려진 ",
	"돼지가 그려진 ",
	"토끼가 그려진 ",
	"뱀이 그려진 ",
	"말이 그려진 ",
	"양이 그려진 ",
	"원숭이가 그려진 ",
	"닭이 그려진 "
};

const char *amulet_iden_string[AMT_MAX+2] =
{
	"완전무결의 ",
	"삼라결계의 ",
	"각부의 ",
	"신앙의 ",
	"전파의 ",
	"신령의 ",
	"그레이즈의 ",
	"날씨의 ",
	"인기도의 ",
	"오컬트의 "
};



int isAmuletGotValue(amulet_type amulet_)
{
	return 0;
	/*return ( amulet_ == AMT_AC || amulet_ == AMT_EV);*/
}

amulet_type goodbadamulet(int good_bad)
{
	return (amulet_type) randA(AMT_MAX - 1);
}

int isGoodAmulet(amulet_type kind, int value)
{
	return 1;
}

bool equipamulet(amulet_type kind, int value)
{
	return false;
}
bool unidenequipamulet(amulet_type kind, int value)
{
	return false;
}
float getAmuletCharge(amulet_type kind)
{
	return 1.0f;
}
bool isCanCharge(amulet_type kind)
{
	switch (kind) {
	case AMT_FAITH:
	case AMT_PERFECT:
		return false;
	}
	return true;
}
bool isCanEvoke(amulet_type kind)
{
	return true;
}
bool chargingFinish(amulet_type kind, int value)
{
	switch (kind)
	{
	case AMT_GRAZE:
		if (value > 0) {
			you.SetGraze(-1);
			int temp = you.Ability(SKL_GRAZE, false, true, 1);
			if (temp) {
				you.Ability(SKL_GRAZE_OFF, false, false, temp);
			}
			enterlog();
		}
		else {
			int temp = you.Ability(SKL_GRAZE_OFF, false, true, 1);
			if (temp) {
				you.Ability(SKL_GRAZE_OFF, false, false, temp);
				//그레이즈를 조종중이면 그레이즈를 끄지않음
			} else 
			{
				you.s_graze = 0;
				printlog("더 이상 탄막을 그레이즈 하지 않는다.", true, false, false, CL_blue);
			}
		}
		break;
	case AMT_WEATHER:
		if (value > 0) {
			printlog("부적에 의해 체력 재생력이 올라갔다!", true, false, false, CL_blue);
		}
		else {
			printlog("더 이상 부적으로부터 재생력을 받지 못한다.", true, false, false, CL_blue);
		}
		break;
	case AMT_FAITH:
		if (value > 0) {
			if (you.god == GT_NONE) {
				printlog("당신은 신앙이 없기때문에 모은 신앙심이 하늘로 날라갔다.", true, false, false, CL_blue);
				you.resetAmuletPercent(kind);
			}
			else {
				printlog("부적에 의해 신과 교감하였다!", true, false, false, CL_blue);
				if (you.god != GT_SEIJA)
					you.PietyUpDown(10);
				you.GiftCount(10);
				you.resetAmuletPercent(kind);
			}
		}
		break;
	}
	return true;
}

bool skill_soul_shot(int power, unit* order, coord_def target);
bool recharging_scroll(bool pre_iden_, bool ablity_);

bool evokeAmulet(amulet_type kind) 
{

	switch (kind)
	{
	case AMT_PERFECT:
	case AMT_FAITH:
		//발동하지않음
		break;
	case AMT_BLOSSOM:
		printlog("팡! ", false, false, false, CL_white_blue);
		skill_soul_shot(0, &you, you.position);
		break;
	case AMT_TIMES:
		you.SetHaste(rand_int(50, 80));
		break;
	case AMT_WAVE:
		if (env[current_level].isBamboo())
		{
			printlog("지형 탐지는 미궁의 죽림에선 효과를 보지 못한다.", true, false, false, CL_normal);
			return false;
		}
		else
		{
			env[current_level].MakeMapping(100);
			printlog("당신은 현재 층을 감지해냈다.", true, false, false, CL_normal);
		}
		break;
	case AMT_SPIRIT:
		return recharging_scroll(true, true);
		break;
	case AMT_GRAZE:
		you.SetSuperGraze(rand_int(10, 15));
		printlog("당신은 순간적으로 회피에 모든 신경을 쏟는다!", false, false, false, CL_white_blue);
		break;
	case AMT_WEATHER:
		printlog("당신은 체력을 회복했다. ", false, false, false, CL_normal);
		you.HpUpDown(rand_int(10, 15) + you.GetMaxHp()*rand_float(0.15f, 0.25f), DR_NONE);
		break;
	case AMT_POPULAR:
		//???

		//미구현
		break;
	case AMT_OCCULT:
		//오컬트 종류

		//네시
		//팔척귀신
		//리틀 그린맨
		//반쵸사라야시키
		//쿠네쿠네
		//.....
		//차후 구현하기
		break;
	}
	return true;
}