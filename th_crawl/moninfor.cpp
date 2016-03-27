//////////////////////////////////////////////////////////////////////////////////////////////////
//
// 파일이름: moninfor.cpp
//
// 내용: 몬스터의 정보띄우기
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "monster.h"
#include "mon_infor.h"

extern HANDLE mutx;


string GetMonsterInfor(monster *it)
{
	string text_ = it->GetName()->name;
	text_ += "\n\n";
	switch(it->id)
	{
	case MON_REIMUYUKKURI:
		text_ += "머리밖에 없는 기분 나쁜 생명체. 언제부턴가 그 개체수가 엄청난 속도로 늘어나기 시작했다.\n";
		text_ += "\"느긋하게 있으라구!\"라는 말밖에 하지 못하는 것 같다.\n";
		break;
	case MON_RAT:
		text_ += "어디서나 볼 수 있는 쥐. 약하다.\n";
		break;
	case MON_FAIRY_GREEN:
	case MON_FAIRY_BLUE:
	case MON_FAIRY_RED:
		text_ += "장난치기를 좋아하는 요정. 자주 몰려다니는 것 같다.\n";
		text_ += "색깔에 따라 강한 정도가 다르다는 것 같다.\n";
		break;
	case MON_MOOK:
		text_ += "털구슬처럼 생긴 자코몹.\n";
		break;
	case MON_CROW:
		text_ += "썩은 고기를 좋아하고 무리지어다니는 까마귀다.\n";
		break;
	case MON_CRANE:
		text_ += "망함.\n";
		break;
	case MON_SPIDER:
		text_ += "다리가 8개 달린 징그러운 거미다.\n";
		break;
	case MON_SNAKE:
		text_ += "던전을 기어다니는 독을 지닌 뱀.\n";
		break;
	case MON_KATPA:
		text_ += "현무의 늪에 사는 요괴. 손기술이 좋고 물을 다루는 능력을 가지고 있다.\n";
		text_ += "강의 사는 요괴지만 환상향이 던전화되고 강을 잃어버리자 난폭해졌다.\n";
		break;
	case MON_KATPA_GUN:
		text_ += "현무의 늪에 사는 요괴. 손기술이 좋고 물을 다루는 능력을 가지고 있다.\n";
		text_ += "강의 사는 요괴지만 환상향이 던전화되고 강을 잃어버리자 난폭해졌다.\n";
		break;
	case MON_FAIRY_GREEN_WARRIOR:
		text_ += "장난치기를 좋아하는 요정. 자주 몰려다니는 것 같다.\n";
		text_ += "길에서 투구와 단검을 주워서 다닌다. 보잘 것 없지만 없는 것 보단 나은 것 같다.\n";
		break;
	case MON_FAIRY_BLUE_MAGICIAN:
		text_ += "장난치기를 좋아하는 요정. 자주 몰려다니는 것 같다.\n";
		text_ += "작은 지팡이를 주워서 마법을 증폭시키고 있다.\n";
		text_ += "작은 요정의 마법이라고 얕보다간 큰일 날 것 같다.\n";
		break;
	case MON_FAIRY_RED_COMMANDER:
		text_ += "장난치기를 좋아하는 요정. 자주 몰려다니는 것 같다.\n";
		text_ += "근처의 꽃밭에서 해바라기를 꺽어서 들고 다니고 있다.\n";
		text_ += "해바라기의 향기로 근처 요정들을 끌어모으고 있다.\n";
		break;
	case MON_RUMIA:
		text_ += "어둠을 다루는 요괴. 언제나 자신의 주위에 어둠을 감싸고 다닌다.\n";
		text_ += "그 때문에 자신도 앞을 보지 못한다.\n";
		break;
	case MON_MISTIA:
		text_ += "미스티아는 노래로 사람을 야맹증으로 만드는 능력을 지닌 밤참새 요괴이다.\n";
		text_ += "빠른 움직임과 긴 손톱으로 공격해온다.\n";
		break;
	case MON_WRIGGLE:
		text_ += "벌레들을 통솔하는 벌레요괴. 벌레를 소환해낸다.\n";
		break;
	case MON_CIRNO:
		text_ += "자칭 최강 얼음요괴 치르노. 냉기를 다루는 정도의 능력을 지녔다.\n";
		text_ += "요정치고 강한편이고 멀리선 강력한 냉기를 발사한다. 하지만 바보다.\n";
		break;
	case MON_MEDICINE:
		text_ += "버려진 인형이 요괴가 된 일종의 츠구모가미. 강력한 독을 사용한다.\n";
		text_ += "요괴가 된지 얼마 안됬지만 치명적인 독을 사용하므로 매우 위험하다.\n";
		text_ += "자주 사용하는 독은 은방울꽃의 독으로 중독된 상대는 느려지기까지한다.\n";
		break;
	case MON_DIEFAIRY:
		text_ += "요정중에서도 특히 힘이 강하기때문에 대요정. 진짜 이름은 알려지지 않았다.\n";
		break;
	case MON_HUMAM_WOMAN:
		text_ += "힘이 없는 여자 인간이다.\n";
		break;
	case MON_HUMAM_MAN:
		text_ += "남자 인간이다.\n";
		text_ += "환상향이 던전화된후에는 자신들을 지키기 위해 무리지어 다니면서 방어하고 있다.\n";
		break;
	case MON_HUMAM_YINYANG:
		text_ += "인간마을에서 요괴 퇴치를 업으로 삼던 음양사.\n";
		text_ += "환상향이 던전화된후에는 자신들을 지키기 위해 무리지어 다니면서 방어하고 있다.\n";
		break;
	case MON_HUMAM_PRIEST:
		text_ += "불교의 가르침에 따라 수행한 법사. 불경의 힘으로 요괴를 퇴치하는 것 같다.\n";
		text_ += "환상향이 던전화된후에는 자신들을 지키기 위해 무리지어 다니면서 방어하고 있다.\n";
		break;
	case MON_HUMAM_SAMURI:
		text_ += "갑옷과 검을 착용하고 싸우는 사무라이.\n";
		text_ += "환상향이 던전화된후에는 자신들을 지키기 위해 무리지어 다니면서 방어하고 있다.\n";
		break;
	case MON_FIREFLY:
		text_ += "반딧불이다. 불빛을 내는 신기한 곤충\n";
		break;
	case MON_BUTTERFLY:
		text_ += "전투능력은 없는 나비\n";
		break;
	case MON_GHOST:
		text_ += "흔히 볼 수 있는 환상향의 유령. 본체보단 약해졌다.\n";
		break;
	case MON_BAKEKASA:
		text_ += "버려진 우산에 요괴가 깃든 츠쿠모가미.\n";
		break;
	case MON_GREEN_MOOK:
		text_ += "털구슬처럼 생긴 자코몹. 초록색이라서 독이 있다.\n";
		break;
	case MON_ORANGE_MOOK:
		text_ += "털구슬처럼 생긴 자코몹. 이쁜 주황색이다.\n";
		break;
	case MON_GRAY_MOOK:
		text_ += "털구슬처럼 생긴 자코몹. 시크한 회색이다.\n";
		break;
	case MON_FROG:
		text_ += "일반 개구리보다 큰 거대한 개구리. 생각보다 위협적이다.\n";
		break;
	case MON_BLACK_CAT:
		text_ += "검은색 고양이. 불운을 상징하는가?\n";
		break;
	case MON_ORANGE_CAT:
		text_ += "주황색 고양이. 털이 이쁘다.\n";
		break;
	case MON_WHITE_CAT:
		text_ += "하얀색 고양이. 도도하다.\n";
		break;
	case MON_CROW_TENGU:
		text_ += "요괴의 산에 사는 까마귀텐구. 보도직을 맡고 있으며 바람을 다룬다.\n";
		text_ += "텐구들은 자신의 산에 사는 요괴들끼리 뭉쳐 다른 세력을 배척한다.\n";
		break;
	case MON_ONI:
		text_ += "거짓말을 싫어하고 술을 좋아하는 호탕한 오니.\n";
		text_ += "매우 힘이 강하고 호전적이다.\n";
		break;
	case MON_KISUME:
		text_ += "두레박 안에서 몸을 숨기고 있는 두레박요괴. 머리위에 떨어져서 기절을 시킨다\n";
		text_ += "소심해보이는 겉모습과 다르게 식인요괴.\n";
		break;
	case MON_CHEN:
		text_ += "고양이가 오랜세월을 지나 요괴가 된 요괴 고양이 첸. \n";
		text_ += "짐승길이나 요괴의산에 출몰된다고 하며 주변의 고양이들을 개다래나무로 길들이는 것 같다.\n";
		text_ += "종종 길들인 고양이들에게 긁혀서 상처가 나는 듯.\n";
		break;
	case MON_KOGASA:
		text_ += "요괴 우산이 버려져서 요괴가 된 케이스인 우산요괴 코가사\n";
		text_ += "인간을 놀래키는 것을 낙으로 삼고 있다. 하지만 최근들어 놀라지 않는 인간들이 많아 고생.\n";
		text_ += "던전에서도 놀래킬 인간들을 찾으며 떠돌아 다니고 있다.\n";
		break;
	case MON_SUNNY:
		text_ += "햇빛을 다루는는 능력을 지닌 쾌활한 요정. 삼월정의 리더\n";
		text_ += "특히 빛을 굴절시켜 빛을 반사시키거나 투명하게 하는게 가능하다.\n";
		text_ += "세 요정중에선 가장 강하지만 역시 요정이라 머리가 나쁘고 약하다.\n";
		break;
	case MON_LUNAR:
		text_ += "달빛을 다루는 능력을 지닌 요정. 삼월정의 일원\n";
		text_ += "소리를 지우는게 가능해서 기척을 없앤다. 하지만 오히려 소리가 없는게 부자연.\n";
		text_ += "밤같은 입을 가지고 있다.\n";
		break;
	case MON_STAR:
		text_ += "별빛을 다루는 능력을 지닌 요정. 삼월정의 일원\n";
		text_ += "기척을 감지하는 능력을 지녔다. 가까이다가가도 금방 눈치챈다.\n";
		text_ += "생각보다 속이 검다. 도망칠때 가장 먼저 도망친다.\n";
		break;
	case MON_MARISAYUKKURI:
		text_ += "머리밖에 없는 기분 나쁜 생명체. 언제부턴가 그 개체수가 엄청난 속도로 늘어나기 시작했다.\n";
		text_ += "\"느긋하게 있으라구!\"라는 말밖에 하지 못하는 것 같다.\n";
		break;
	case MON_AYAYUKKURI:
		text_ += "머리밖에 없는 기분 나쁜 생명체. 언제부턴가 그 개체수가 엄청난 속도로 늘어나기 시작했다.\n";
		text_ += "느긋한 다른 윳쿠리들과 달리 매우 빠르다! 머리를 좌우로 흔들면서 말을 두번 반복하는게 특징.\n";
		break;
	case MON_REMILIAYUKKURI:
		text_ += "머리밖에 없는 기분 나쁜 생명체. 언제부턴가 그 개체수가 엄청난 속도로 늘어나기 시작했다.\n";
		text_ += "육식하는 육식성윳쿠리. 날라다니면서 사냥감을 노린다. 속에 고기가 차있다는 얘기가 있다.\n";
		break;
	case MON_ALICEYUKKURI:
		text_ += "머리밖에 없는 기분 나쁜 생명체. 언제부턴가 그 개체수가 엄청난 속도로 늘어나기 시작했다.\n";
		text_ += "시크한 도시파 윳쿠리.\n";
		break;
	case MON_YOUMUYUKKURI:
		text_ += "머리밖에 없는 기분 나쁜 생명체. 언제부턴가 그 개체수가 엄청난 속도로 늘어나기 시작했다.\n";
		text_ += "묭!\n";
		break;
	case MON_YAMABIKO:
		text_ += "산속에서 목소리가 들려오면 메아리를 치는 메아리의 요괴.\n";
		text_ += "개와 원숭이를 닮았다.\n";
		break;
	case MON_KATPA_SPEAR:
		text_ += "현무의 늪에 사는 요괴. 손기술이 좋고 물을 다루는 능력을 가지고 있다.\n";
		text_ += "강의 사는 요괴지만 환상향이 던전화되고 강을 잃어버리자 난폭해졌다.\n";
		text_ += "이 캇파는 창을 자유자재로 다룰 수 있어 보인다.\n";
		break;
	case MON_KATPA_WATER_WIZARD:
		text_ += "현무의 늪에 사는 요괴. 손기술이 좋고 물을 다루는 능력을 가지고 있다.\n";
		text_ += "강의 사는 요괴지만 환상향이 던전화되고 강을 잃어버리자 난폭해졌다.\n";
		text_ += "물을 다루는 능력이 특히 높아 보인다.\n";
		break;
	case MON_YAMABUSH_TENGU:
		text_ += "요괴의 산에 사는 까마귀텐구. 인쇄업 맡고 있다.\n";
		break;
	case MON_HANATACA_TENGU:
		text_ += "요괴의 산에 사는 까마귀텐구. 사무직 맡고 있다.\n";
		text_ += "빨간얼굴에 긴 코가 특징.\n";
		break;
	case MON_BLUE_ONI:
		text_ += "거짓말을 싫어하고 술을 좋아하는 호탕한 오니.\n";
		text_ += "매우 힘이 강하고 호전적이다.\n";
		break;
	case MON_MUSHROOM:
		text_ += "걸어다니는 요괴 물약.\n";
		text_ += "포자 공격을 통해 독이나 혼란을 건다.\n";
		break;
	case MON_KYOUKO:
		text_ += "메아리를 울리는 야마비코 요괴 카소다니 쿄코.\n";
		text_ += "최근들어 메아리가 단순히 소리가 반사되는 물리현상이라는 미신이 유행해 허무함을 느껴 불문에 귀의했다.\n";
		text_ += "소리를 반사시키는 정도의 능력을 가지고 있다.\n";
		break;
	case MON_SIGMUND:
		text_ += "SIGMUND WILL KILL YOU!\n";
		break;
	case MON_WOLF_TENGU:
		text_ += "요괴의 산에 사는 백랑텐구. 경비를 맡고 있는 텐구다.\n";
		break;
	case MON_MOMIZI:
		text_ += "경비를 맡고 있는 백랑텐구다.\n";
		text_ += "평소에는 한가하기때문에 대장기를 하면서 쉬고있다.\n";
		break;
	case MON_AYA:
		text_ += "요괴의 산의 까마귀 텐구 샤메이마루 아야.\n";
		text_ += "붕붕마루신문의 기자이기도 해서 취재거리를 삼아 이리저리 돌아다니기도한다.\n";
		break;
	case MON_TEST_KATPA:
		text_ += "현무의 늪에 사는 요괴. 손기술이 좋고 물을 다루는 능력을 가지고 있다.\n";
		text_ += "강의 사는 요괴지만 환상향이 던전화되고 강을 잃어버리자 난폭해졌다.\n";
		break;
	case MON_WAKASAGI:
		text_ += "안개호수에 살고있는 인어. 물 밖에 나오면 힘을 못 쓴다.\n";
		break;
	case MON_YAMAME:
		text_ += "전염병을 다루는 츠치구모. 질병과 독으로 공격을 해온다.\n";
		text_ += "그녀를 만나는 것만으로도 질병에 걸릴 수 있다!\n";
		break;
	case MON_NAZRIN:
		text_ += "비사문천의 직속 부하인 요괴 쥐.\n";
		text_ += "물건을 찾는데 능통하며 펜듈럼을 소환하여 자신의 방어를 굳힌다.\n";
		break;
	case MON_DAUZING:
		text_ += "날아다니는 펜듈럼. 공격능력은 없지만 소환수를 보호한다.\n";
		break;
	case MON_YOSIKA:
		text_ += "걸어다니는 시체다. 누군가에 의해서 움직이고 있는 듯하다.\n";
		text_ += "기본적으로 단단하면서 체력을 회복해서 잡기가 어려워보인다.\n";
		break;
	case MON_SEKIBANKI:
		text_ += "로쿠로쿠비의 요괴. 목을 떨어뜨려서 공중에 날릴 수 있다.\n";
		text_ += "거만하고 자존심이 강한 성격이라고 한다.\n";
		break;
	case MON_SEKIBANKI_BODY:
		text_ += "로쿠로쿠비의 요괴. 목을 떨어져서 몸통만 남아있다.\n";
		text_ += "목이 떨어진 상태에선 움직이지 못하는 것 같다.\n";
		break;
	case MON_SEKIBANKI_HEAD:
		text_ += "로쿠로쿠비의 요괴. 몸통으로부터 떨어져서 하늘을 날고 있다.\n";
		text_ += "머리로부터 강력한 공격을 해오므로 본체부터 노리는게 좋을 것 같다.\n";
		break;
	case MON_NITORI:
		text_ += "현무의 계곡에 살고있는 캇파. 무리생활을 하고 있다.\n";
		text_ += "기계를 다루는데 능숙하고 물을 다룰 수 있다.\n";
		text_ += "광학미채를 발명하여 불완전하지만 투명해질 수 있고 다양한 도구로 공격해온다.\n";
		break;
	case MON_KEGERO:
		text_ += "환상향의 늑대인간. 보름달이 되면 변신한다.\n";
		text_ += "미혹의 죽림에 살고있으며 변신하여도 냉정을 잃지않는다.\n";
		break;
	case MON_PARSI:
		text_ += "질투심의 요괴. 그 누구를 보더라도 질투한다.\n";
		text_ += "지하세계의 통로를 지키는 문지기 역할을 하고있다.\n";
		break;
	case MON_BENBEN:
		text_ += "비파가 요괴화한 츠쿠모가미.\n";
		text_ += "동생인 벤벤과 함께 다닌다.\n";
		break;
	case MON_YATHASI:
		text_ += "고토가 요괴화한 츠쿠모가미.\n";
		text_ += "언니인 야츠하시와 함께 다닌다.\n";
		break;
	case MON_ORIN:
		text_ += "작열지옥터에서 원령을 관리하고 있다.\n";
		text_ += "수레를 이용하여 시체를 수거해가는 고양이 화차요괴다.\n";
		text_ += "고양이로 변신해서 다니기도 하며 그녀의 주변엔 많은 원령들이 떠다닌다.\n";
		break;
	case MON_ORIN_CAT:
		text_ += "작열지옥터에서 원령을 관리하고 있다.\n";
		text_ += "고양이로 변신한 상태로 재빠른 움직임은 짜증과 피탄을 불러온다.\n";
		break;
	case MON_ZOMBIE_FAIRY:
		text_ += "좀비의 모습을 하고있는 요정.\n";
		text_ += "사실 단순히 좀비의 흉내를 내고있다고 한다.\n";
		break;
	case MON_ICHIRIN:
		text_ += "원래는 인간이었던 요괴. 뉴도를 퇴치한후 요괴가 되어 뉴도를 다룬다.\n";
		text_ += "항상 뉴도의 같이다니면서 뉴도의 힘을 이용한다.\n";
		break;
	case MON_UNZAN:
		text_ += "이치린과 함께 다니는 뉴도.\n";
		text_ += "거대한 주먹은 그의 트레이드 마크이다.\n";
		break;
	case MON_UNZAN_PUNCH:
		text_ += "운잔의 거대한 주먹.\n";
		text_ += "맞으면 아플 것 같다.\n";
		break;
	case MON_PACHU:
		text_ += "홍마관의 도서관에 있는 마법사.\n";
		text_ += "도서관을 어지럽히는걸 싫어하여 도서관에 칩입한 칩입자를 공격한다.\n";
		break;
	case MON_MAGIC_BOOK:
		text_ += "날라다니는 마법서. 마법에 의해 움직이면서 적을 공격하고 있다.\n";
		text_ += "마법서가 사용하고 있는 마법은 자신에게 쓰여진 마법이다.\n";
		text_ += "쓰러트려 떨어뜨리면 사용하고있던 마법을 배울 수 도 있을 것 같다.\n";
		break;
	case MON_HOBGOBRIN:
		text_ += "홍마관에 새롭게 고용되었다. 가사를 돕는 요정으로 생김새는 무섭게 생겼다.\n";
		text_ += "약해보이지만 그는 사실 한때 최강의 몬스터로 몽둥이와 함께 흉폭한 데미지와\n";
		text_ += "던전을 탐험하는 초보자를 학살하는 최고의 플레이어 살인율을 자랑했다고 한다.\n";
		text_ += "환상향에 온걸 환영하네!\n";
		break;
	case MON_HOBGOBRIN_MAID:
		text_ += "홍마관에 새롭게 고용되었다. 가사를 돕는 요정으로 생김새는 무섭게 생겼다.\n";
		text_ += "홍마관의 직책에 맞게 메이드 옷을 입어 청소를 돕고 있다.\n";
		text_ += "그가 지닌 길다란 걸레자루는 플레이어의 목숨을 위협하고 있다.\n";
		break;
	case MON_HOBGOBRIN_LIBRARIAN:
		text_ += "홍마관에 새롭게 고용되었다. 가사를 돕는 요정으로 생김새는 무섭게 생겼다.\n";
		text_ += "도서관의 수많은 책을 관리하기 위해 사서로 고용된 홉고블린이다.\n";
		text_ += "그에게 마법은 전문분야까지는 아니지만 던전에 오는 무식한 플레이어들을 학살하기에는 충분해보인다.\n";
		break;
	case MON_HOBGOBRIN_TEMP:
		text_ += "홍마관에 새롭게 고용되었다. 가사를 돕는 요정으로 생김새는 무섭게 생겼다.\n";
		text_ += "약해보이지만 그는 사실 한때 최강의 몬스터로 몽둥이와 함께 흉폭한 데미지와\n";
		text_ += "던전을 탐험하는 초보자를 학살하는 최고의 플레이어 살인율을 자랑했다고 한다.\n";
		text_ += "환상향에 온걸 환영하네!\n";
		break;
	case MON_MAID_FAIRY:
		text_ += "홍마관에 일하고 있는 요정. 별다른 도움은 안되고 있다.\n";
		text_ += "메이드옷만 입은걸 빼면 길에 있는 요정들과 다를바 없어 보인다.\n";
		break;
	case MON_CHUPARCABRA:
		text_ += "홍마관에서 새로 기르고 있는 애완동물.\n";
		text_ += "습격한 상대의 피를 빨아먹는다. 애완동물을 죽이면 주인이 화낼까?\n";
		break;
	case MON_KOAKUMA:
		text_ += "악마중에서도 힘이 약하기때문에 소악마. 진짜 이름은 알려지지 않았다.\n";
		break;
	case MON_MEIRIN:
		text_ += "홍마관의 입구를 지키고 있는 문지기.\n";
		text_ += "체술에 자신이 있어서 그녀와 근접전을 벌이는건 좋은 생각이 아닐지도 모른다.\n";
		text_ += "홍마관의 입구에서 자고 있는 경우가 가끔 보인다고 한다.\n";
		break;
	case MON_SAKUYA:
		text_ += "홍마관의 완벽하고 소쇄한 메이드장.\n";
		text_ += "시간과 공간을 다뤄서 기묘한 움직임을 보여준다. 나이프가 주 무기\n";
		text_ += "시간을 멈출 수 있는 그녀에게 공격을 맞추기란 쉬워보이지않는다.\n";
		break;
	case MON_REMILIA:
		text_ += "홍마관의 주인인 흡혈귀.\n";
		text_ += "카리스마가 넘치는 그녀는 이 던전에서 중요한 물건을 숨기고 있는 것 같다.\n";
		text_ += "그녀를 이기거나 따돌려서 물건을 얻어내자!\n";
		break;
	case MON_EAGLE:
		text_ += "거대한 매.\n";
		text_ += "거대한 부리와 발톱이 위협적이다.\n";
		break;
	case MON_TIGER:
		text_ += "환상향에 살고 있는 호랑이.\n";
		text_ += "물리면 아플 것 같다.\n";
		break;
	case MON_RAIJUU:
		text_ += "조그만 쥐처럼 생긴 뇌수. 귀엽게 생겼지만 위험하다.\n";
		text_ += "강력한 전기를 발산하며 독을 품고 있다.\n";
		break;
	case MON_DRAGON_BABY:
		text_ += "조그만 쥐처럼 생긴 뇌수. 귀엽게 생겼지만 위험하다.\n";
		text_ += "강력한 전기를 발산하며 독을 품고 있다.\n";
		break;
	case MON_KASEN:
		text_ += "환상향에 살고 있는 선인. 오니일지도 모른다는 공공연한 비밀이 있다.\n";
		text_ += "잘못 걸리면 설교를 당한다. 다양한 동물과 요수를 사역하고 있다.\n";
		break;
	case MON_YAMAWARO_NINJA:
		text_ += "캇파의 아지트가 황폐화되면서 산으로 터전을 옮긴 본래 캇파들.\n";
		text_ += "한창 서바이벌 게임을 하고 있는 도중으로 보인다.\n";
		text_ += "멀리서 표창을 던지고 있으며 잡으면 10포인트를 준다.\n";
		break;
	case MON_YAMAWARO_WAWRRIOR:
		text_ += "캇파의 아지트가 황폐화되면서 산으로 터전을 옮긴 본래 캇파들.\n";
		text_ += "한창 서바이벌 게임을 하고 있는 도중으로 보인다.\n";
		text_ += "싸움을 좋아하는 성격으로 검을 들고 달려온다.\n";
		break;
	case MON_YAMAWARO_FLAG:
		text_ += "캇파의 아지트가 황폐화되면서 산으로 터전을 옮긴 본래 캇파들.\n";
		text_ += "한창 서바이벌 게임을 하고 있는 도중으로 보인다.\n";
		text_ += "싸움에는 큰 자신이 없어서 직접 전투에 참가하지않고 깃발을 담당하고 있다.\n";
		text_ += "동료들의 사기를 올려주고 있으며 잡으면 높은 포인트를 얻을 것 같다.\n";
		break;
	case MON_ONBASIRA:
		text_ += "카나코의 권능으로 구현화된 기둥.\n";
		text_ += "자리에 굳게 박혀서 이동을 막아준다. 원거리 공격은 아군적군 할거없이 관통된다.\n";
		text_ += "카나코를 믿은채로 바로 근처에 있으면 전투력 보너스를 받을 수 있다.\n";
		break;
	case MON_RED_UFO:
	case MON_GREEN_UFO:
	case MON_BLUE_UFO:
		text_ += "미확인비행물체. 요란한 소리를 내며 날라다닌다.\n";
		text_ += "요란스럽게 자신의 색깔을 바꾸는데 색이 바뀌면 내성과 공격속성도 불,전기,냉기로 달라지는 것 같다.\n";
		text_ += "원래는 다른 물건인거같지만 누군가의 정체불명의 힘에 의해 벤토라로 보이는 것 같다.\n";
		break;
		
	case MON_KOISHI:
		text_ += "무의식의 능력자인 코이시. 무의식으로 돌아다니는 그녀를 인식하는 건 어렵다.\n";
		text_ += "무의식으로 다니면서 무의식으로 싸움을 걸기때문에 무의식으로 돌아다니다보면 무의식중에 죽을 수 있다.\n";
		break;
	case MON_NUE:
		text_ += "정체불명의 힘을 사용하는 누에.\n";
		text_ += "정체불명이다.\n";
		break;
	case MON_SANPEI_FIGHTER:
		text_ += "캇파들이 만들어낸 수압으로 날라다니는 비행기. 상당히 튼튼하게 만들어져있다.\n";
		text_ += "빠른 속도로 날라다니면서 기체에 붙은 드릴로 상대를 갈아버린다.\n";
		break;
	case MON_VAMPIER_BAT:
		text_ += "홍마관에 살고있는 박쥐. 주인의 힘을 받아 보통의 박쥐와 비교할 수 없을 정도로 강력해진 것 같다.\n";
		text_ += "굉장한 속도로 날라다니면서 근처에 오는 칩입자를 공격한다.\n";
		break;
	case MON_DEAGAMA:
		text_ += "안개의 호수에서 살고있는 거대한 두꺼비요괴. 엄청나게 거대하다.\n";
		text_ += "길다란 혀로 상대를 끌어당긴다. 못된 장난을 하는 요정들을 잡아먹기도 하는 듯.\n";
		break;
	case MON_RABBIT:
		text_ += "길가에 돌아다니고 있는 토끼. 생각보다 사납다.\n";
		break;
	case MON_YOKAI_RABBIT:
		text_ += "토끼가 오랜 시간이 흘러 요괴화 되었다. 장난치는건 요정못지않게 좋아한다.\n";
		break;
	case MON_NAMAZ:
		text_ += "거대한 메기. 나마즈는 지진을 일으키는 메기다.\n";
		text_ += "거대한 몸집으로 한번 움직일때마다 큰 지진이 일어난다. 또한 전기도 낼 수 있는 모양이다.\n";
		break;
	case MON_HELL_CROW:
		text_ += "작열지옥터 근처에 살고있는 까마귀. 원령이나 시체를 먹어서 요괴화된 까마귀다.\n";
		text_ += "누군가가 키우고 있는 주인이 있는 모양.\n";
		break;
	case MON_RACCON:
		text_ += "누군가로 둔갑하기 좋아하는 너구리요괴.\n";
		break;
	case MON_LANTERN_YOUKAI:
		text_ += "제등의 모양을 하고 있는 츠쿠모가미의 요괴.\n";
		text_ += "불을 뿜어서 주변을 불바다로 만들어버린다.\n";
		break;
	case MON_YINYAN:
		text_ += "강력한 힘을 가진 음양옥이다. 예전엔 많은 요괴들에게 노려진 모양이다.\n";
		break;
	case MON_YUUGENMAGAN:
		text_ += "다섯개의 눈으로 이루어진 마계의 생물. 기괴하게 생겼다.\n";
		text_ += "상대에게 전기 공격을 가한다.\n";
		break;
	case MON_ELIS:
		text_ += "마계에 살고있는 악마. 박쥐의 날개를 달고 있다.\n";
		text_ += "빠르고 흡혈 공격을 한다.\n";
		break;
	case MON_SARIEL:
		text_ += "마계에 살고있는 타천사. 커다란 날개를 가지고 있다.\n";
		break;
	case MON_SARA:
		text_ += "마계의 문지기. 탄막을 뿌릴땐 빙글빙글 도는 것 같다.\n";
		break;
	case MON_LUIZE:
		text_ += "마계에 살고있다. 여행을 좋아해서 가끔 인간계로 놀러오는 것 같다.\n";
		break;
	case MON_YUKI:
		text_ += "마계의 빙설세계에 살고있다. 강력한 화염을 사용한다.\n";
		text_ += "너무 강렬한 추위는 화상과도 큰 차이가 없는 것 같다.\n";
		break;
	case MON_MAI:
		text_ += "마계의 빙설세계에 살고있다. 강력한 냉기를 사용한다.\n";
		text_ += "혼자 있을때는 입이 거칠고 속이 검어보인다.\n";
		break;
	case MON_YUMEKO:
		text_ += "신키의 직속 메이드. 가장 강력한 마족중 하나다.\n";
		text_ += "거대한 나이프(검?)을 던지면서 싸우는 마족 메이드.\n";
		break;
	case MON_MAGICAL_STAR:
		text_ += "사용자의 주변을 멤도는 옵션. 사용자의 근처에서 자동으로 적을 요격한다.\n";
		text_ += "미묘한 디자인이지만 행운의 아이템이라고도 불린다.\n";
		break;
	case MON_GOLEM:
		text_ += "마법을 통해 만들어진 골렘.\n";
		text_ += "크기와 강하기는 사용자의 마력에 따라 달라진다고 한다.\n";
		break;
	case MON_EVIL_EYE:
		text_ += "눈알의 형태를 지닌 괴기한 생명체.\n";
		text_ += "눈에서 전기를 쏘기도 한다고 한다.\n";
		break;
	case MON_LITTLE_IMP:
		text_ += "마계에 살고있는 약한 자코.\n";
		text_ += "물론 약하지만 대량으로 쏟아져나온다.\n";
		break;
	case MON_ENSLAVE_GHOST:		
		text_ += "유유코의 권능에 의해 사로잡힌 영혼.\n";
		text_ += "1명만 동료로 데려다닐 수 있다.\n";
		break;
	case MON_SCHEMA_EYE:		
		text_ += "틈새로부터 보이는 섬뜻한 눈.\n";
		text_ += "움직일 수 는 없지만 유카리로의 지원 사격을 받을 수 있다.\n";
		text_ += "체력이 낮은게 흠.\n";
		break;
	case MON_FLAN:
		text_ += "홍마관에 살고있는 레밀리아의 여동생.\n";
		text_ += "위험한 분위기가 흘러나오고있다. 정면승부는 피해야할지도 모른다.\n";
		break;
	case MON_FLAN_BUNSIN:
		text_ += "플랑드르가 소환한 분신.\n";
		text_ += "본체보단 약해보이지만 상당한 파워를 지닌 것 같다.\n";
		break;
	default:
		text_ += "찾아볼 수 없는 몬스터\n";
	}
	text_ += "\n\n";


	if(it->poison_resist)
	{
		if(it->poison_resist>0)
			text_ += "독에 대한 저항력이 있다.\n";
		else
			text_ += "독에 취약하다.\n";
	}
	if(it->fire_resist)
	{
		if(it->fire_resist==1)
			text_ += "화염에 대한 약간의 저항력이 있다.\n";
		else if(it->fire_resist==2)
			text_ += "화염에 대한 상당한 저항력이 있다.\n";
		else if(it->fire_resist>=3)
			text_ += "화염을 완벽하게 방어한다.\n";
		else
			text_ += "화염에 취약하다.\n";
	}
	if(it->ice_resist)
	{
		if(it->ice_resist==1)
			text_ += "냉기에 대한 약간의 저항력이 있다.\n";
		else if(it->ice_resist==2)
			text_ += "냉기에 대한 상당한 저항력이 있다.\n";
		else if(it->ice_resist>=3)
			text_ += "냉기를 완벽하게 방어한다.\n";
		else
			text_ += "냉기에 취약하다.\n";
	}
	if(it->elec_resist)
	{
		if(it->elec_resist==1)
			text_ += "전기가 잘 통하지 않는다.\n";
		else if(it->elec_resist==2)
			text_ += "전기가 거의 통하지 않는다.\n";
		else if(it->elec_resist>=3)
			text_ += "절연이다.\n";
	}
	if(it->speed != 10)
	{
		if(it->speed<=5)
			text_ += "행동이 매우 빠르다.\n";
		else if(it->speed<=7)
			text_ += "행동이 빠르다.\n";
		else if(it->speed<=9)
			text_ += "행동이 약간 빠르다.\n";
		else if(it->speed<=13)
			text_ += "행동이 약간 느리다.\n";
		else if(it->speed<=18)
			text_ += "행동이 느리다.\n";
		else
			text_ += "행동이 매우 느리다.\n";
	}
	if(it->isFly())
			text_ += "하늘을 날 수 있다.\n";
	if(it->flag & M_FLAG_CAN_SEE_INVI)
			text_ += "투명을 볼 수 있다.\n";

	if(it->resist >= 99)
			text_ += "디버프 마법에 대한 면역력이 무한이다.\n";


	
	if(it->flag & M_FLAG_SUMMON)
	{
		text_ += "\n\n이 몬스터는 소환된 상태로 시간이 지나면 사라진다. 또한 경험치를 주지도 않는다.\n";
	}
	return text_;

}