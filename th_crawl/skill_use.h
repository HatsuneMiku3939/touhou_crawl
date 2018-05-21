//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: skill_use.h
//
// ����: ��ų ����(����)
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __SKILL_USE_H__
#define  __SKILL_USE_H__


#include "monster.h"
#include "enum.h"

enum spell_list
{
	SPL_NONE = 0,
	SPL_MON_TANMAC_SMALL,
	SPL_MON_TANMAC_MIDDLE,
	SPL_MON_WATER_GUN, 
	SPL_FLAME,	SPL_FROST,	SPL_MEDICINE_CLOUD,	SPL_COLD_BEAM,	SPL_SUMMON_BUG,	SPL_CONFUSE,	SPL_SLOW,
	SPL_SELF_HEAL,	SPL_BLINK,	SPL_SMITE,	SPL_BURN,	SPL_FIRE_WALL,	SPL_FROZEN,	SPL_FREEZE,	SPL_STING,
	SPL_CURE_POISON,	SPL_TWIST,	SPL_SUMMON_MOOK,	SPL_FIRE_BRAND,	SPL_COLD_BRAND,	SPL_POISON_BRAND,
	SPL_SHOCK,	SPL_CHAIN_LIGHTNING,	SPL_DISCHARGE,	SPL_LEVITATION,	SPL_GLOW,	SPL_GRAZE,	SPL_VEILING,
	SPL_INVISIBLE,	SPL_HASTE,	SPL_SILENCE,	SPL_SWIFT,	SPL_MAGIC_TANMAC,	SPL_FIRE_BALL,	SPL_FIRE_BOLT,
	SPL_ICE_BOLT,	SPL_VENOM_BOLT,	SPL_CONFUSE_CLOUD,	SPL_POISON_CLOUD,	SPL_ICE_CLOUD,	SPL_SUMMON_BIRD,
	SPL_RECALL, SPL_TELEPORT_OTHER, SPL_TELEPORT_SELF, SPL_WHIRLWIND, SPL_SUMMON_PENDULUM, SPL_SUMMON_SEKIBANKI,
	SPL_WATER_CANNON, SPL_KYOKO_SMITE, SPL_SUMMON_OPTION, SPL_SUMMON_GOLEM,
	SPL_HYPNOSIS, SPL_MUTE, SPL_SELF_INJURY, SPL_CHARM, SPL_LASER, SPL_SPARK,
	SPL_SUMMON_UNZAN, SPL_SUMMON_UNZAN_PUNCH, SPL_SUMMON_ZOMBIE_FAIRY, SPL_SUMMON_UFO,
	SPL_HASTE_OTHER, SPL_HEAL_OTHER, SPL_MIND_BENDING,
	SPL_STONE_PUNCH, SPL_STONE_ARROW, SPL_STONE_TRAP, SPL_STONE_UPLIFT, SPL_KANAME_DRILL,
	SPL_DIAMOND_HARDNESS, SPL_POISON_SKIN, SPL_STONE_FORM,
	SPL_KNIFE_COLLECT, SPL_FLAN_BUSIN, SPL_BURST, SPL_SUICIDE_BOMB,SPL_RABBIT_HORN,
	SPL_SUMMON_LESSOR_DEMON,
	SPL_LUMINUS_STRIKE, SPL_FIRE_STORM, SPL_BLIZZARD, SPL_PERFERT_FREEZE, SPL_DRAW_POWER, SPL_ANIMAL_CHANGE,
	SPL_FIELD_VIOLET, SPL_TIME_PARADOX, SPL_PRIVATE_SQ, SPL_CONTROLED_BLINK, SPL_THE_WORLD,
	SPL_HASTE_ALL, SPL_HEAL_ALL, SPL_MOON_COMMUNICATION, SPL_MOON_GUN, SPL_SUMMON_DREAM, SPL_MANA_DRAIN, SPL_INSANE,
	SPL_BLOOD_SMITE, SPL_CALL_HOUND, SPL_CANNON, SPL_DOLLS_WAR, SPL_FAKE_DOLLS_WAR, SPL_FIRE_SPREAD,
	SPL_STASIS, SPL_JUMP_ATTACK, SPL_ALERT_NOISE, SPL_SUMMON_NAMAZ, SPL_SCHEMA_TANMAC,
	SPL_CHANGE, SPL_UNLUCK, SPL_THUNDER, SPL_AIR_STRIKE, SPL_SUMMON_RACOON, SPL_SUMMON_YOUKAI,
	SPL_MAMIZO_EVADE, SPL_MACRO_BURST, SPL_SHATTER, SPL_SUMMON_YOSHIKA, SPL_NESY_CANNON, SPL_MERMAID_SONG,
	SPL_EMERALD_CITY, SPL_AUTUMN_BLADE, SPL_PHILOSOPHERS_STONE, SPL_SUMMON_ANCHOR,
	SPL_REAPER_MET, SPL_AFTERLITE,
	SPL_PRISM_CALL, SPL_PSYCHOKINESIS, SPL_SUMMON_TRASH, SPL_TRASH_RUSH,
	SPL_KOKORO_CHANGE, SPL_THUNDER_BOLT, SPL_SANTUARY,
	SPL_MISTIA_SONG, SPL_MESS_CONFUSION, SPL_THROW_DISH,
	SPL_SLEEP_SMITE, SPL_TARGET_ELEC, SPL_SUMMON_ELEC_BALL,
	SPL_DREAM_CALL, SPL_HYPER_BEAM, SPL_KAGUYA_SPELL,
	SPL_THROW_SWORD, SPL_THROW_KNIFE, SPL_THROW_PLAYER,
	SPL_MAX
};

enum skill_list
{
	SKL_NONE = 0,
	SKL_KANAKO_1,
	SKL_KANAKO_2,
	SKL_KANAKO_3,
	SKL_GRAZE,
	SKL_GRAZE_OFF,
	SKL_LEVITATION,
	SKL_LEVITATION_OFF,
	SKL_INVISIBLE,
	SKL_INVISIBLE_OFF,
	SKL_EIRIN_0,
	SKL_EIRIN_1,
	SKL_EIRIN_2,
	SKL_BYAKUREN_1,
	SKL_BYAKUREN_2,
	SKL_MINORIKO_1,
	SKL_MINORIKO_2,
	SKL_SIZUHA_1,
	SKL_SIZUHA_2,
	SKL_SIZUHA_3,
	SKL_YUUGI_1,
	SKL_YUUGI_2,
	SKL_YUUGI_3,
	SKL_YUUGI_3_THROW,
	SKL_YUUGI_4,
	SKL_YUUGI_5,
	SKL_SATORI_1,
	SKL_SATORI_2,
	SKL_SHINKI_1,
	SKL_SHINKI_2,
	SKL_SHINKI_3,
	SKL_YUYUKO_ON,
	SKL_YUYUKO_OFF,
	SKL_YUYUKO_1,
	SKL_YUYUKO_2,
	SKL_YUYUKO_3,
	SKL_YUKARI_1,
	SKL_YUKARI_2,
	SKL_YUKARI_3,
	SKL_YUKARI_4,
	SKL_SWAKO_JUMP,
	SKL_SWAKO_TEMPLE,
	SKL_SWAKO_WATER_GUN,
	SKL_SWAKO_TOUGUE,
	SKL_SWAKO_CURSE,
	SKL_SWAKO_DIGGING,
	SKL_SWAKO_SUMMON_FLOG,
	SKL_SWAKO_STATUE,
	SKL_SWAKO_RAIN,
	SKL_SWAKO_SLEEP,
	SKL_SWAKO_MISYAGUZI,
	SKL_HINA_1,
	SKL_HINA_2,
	SKL_HINA_3,
	SKL_HINA_4,
	SKL_HINA_5,
	SKL_JUMPING_ATTACK,
	SKL_BREATH,
	SKL_TORMENT,
	SKL_ABANDON_GOD,
	SKL_SEIJA_GIFT,
	SKL_SEIJA_1,
	SKL_SEIJA_2,
	SKL_LILLY_1,
	SKL_LILLY_2,
	SKL_LILLY_3,
	SKL_LILLY_4,
	SKL_PHILOSOPHERS_1,
	SKL_PHILOSOPHERS_2,
	SKL_PHILOSOPHERS_3,
	SKL_PHILOSOPHERS_4,
	SKL_PHILOSOPHERS_5,
	SKL_OKINA_1,
	SKL_OKINA_2,
	SKL_OKINA_3,
	SKL_OKINA_4,
	SKL_OKINA_5,
	SKL_JUNKO_1,
	SKL_JUNKO_2,
	SKL_JUNKO_3,
	SKL_JUNKO_4,
	SKL_JOON_AND_SION_1,
	SKL_JOON_AND_SION_2,
	SKL_JOON_AND_SION_3,
	SKL_JOON_AND_SION_4,
	SKL_JOON_AND_SION_OFF,
	SKL_MIKO_1,
	SKL_MIKO_2,
	SKL_MIKO_3,
	SKL_MIKO_4,
	SKL_MIKO_5,
	SKL_MIKO_6,
	SKL_MAX
};

enum skill_flag
{
	S_FLAG_SMITE = 1<<0, //������Ʈ���ΰ�? false: ������
	S_FLAG_PENETRATE = 1<<1, //����ǳ�?
	S_FLAG_CLOSE_DANGER = 1<<2, //�������� �����Ѱ�?
	S_FLAG_SEIF = 1<<3, //�ڽſ��� ����Ҽ��ִ°�?
	S_FLAG_CLOUD = 1<<4, //�������ΰ�? (�������� �̹� ��� ���� �ִٸ� �����ʴ´�.)
	S_FLAG_HEAL = 1<<5, //ȸ��
	S_FLAG_DEBUF = 1<<6, //�������
	S_FLAG_SUMMON = 1<<7, //��ȯ��
	S_FLAG_SPEAK = 1<<8, //�ֹ��� �ʿ��Ѱ�
	S_FLAG_IMMEDIATELY = 1<<9, //������� �ߵ��ϴ°�?
	S_FLAG_DIREC = 1<<10, //�������� �ߵ��ϴ°�? (S_FLAG_IMMEDIATELY�� ��ø�Ұ�)
	S_FLAG_NO_COM = 1<<11, //AI�� ��������ʴ� ����ΰ�?
	S_FLAG_TOGLE = 1<<12, //����� �������?(�ѹ� ����ϸ� �ذų� �ٽ� ����Ҷ����� ����������)
	S_FLAG_BUF = 1<<13, //������
	S_FLAG_OTHER_BUF = 1<<14, //���� ���������ִ� ���(���� ai��)
	S_FLAG_RANGE_ATTACK = 1<<15, //�� ���� (�ַ� ai��) ��Ÿ��ȿ� �ö� ���ݰ����� ����̴�.
	S_FLAG_SUKIMA = 1<<16, //��Ű����
	S_FLAG_RECT = 1<<17, //�簢�� �þ�
	S_FLAG_NO_TARGET = 1<<18, //���͸� Ÿ������ �����ʴ´�.
	S_FLAG_UNSIGHT = 1<<19, //�þ߿� ������ ��밡��.
	S_FLAG_GOD = 1<<20, //���� ��ų
	S_FLAG_DELAYED = 1<<21, //�Ƿΰ� ���̸� �� �� ����.
};

float GetSpellSector(spell_list spell_);
bool SpellFlagCheck(spell_list skill, skill_flag flag);
int SpellLength(spell_list skill);
bool isMonsterhurtSpell(monster* use_, monster* target_, spell_list spell_);
bool isMonSafeSkill(spell_list skill, monster* order, coord_def &target);
const char* SpellString(spell_list skill);
int SpellCap(spell_list skill);
int SpellLevel(spell_list skill);
int SpellNoise(spell_list skill);
int SpellSpeed(spell_list skill);
int Spellsize(spell_list skill);
int SpellDiffer(int level);
int SpellMiscastingLevel(int level_, int fail_);
int SpellMiscasting(int miscasting_level_);
int SpellHunger(int level);
skill_type SpellSchool(spell_list skill, int num);
bool SpellAiCondition(spell_list skill, monster *mon); //�ΰ������� ������ ���� �߰� ����(true�� ��밡�� false�� ���Ұ�)




bool SkillFlagCheck(skill_list skill, skill_flag flag);
int SkillLength(skill_list skill);
const char* SkillString(skill_list skill); //��ų �̸�
int SkillCap(skill_list skill);//��ų�Ŀ� ����
int SkillNoise(skill_list skill); //��ų ����
int SkillPow(skill_list skill);//��ų�� �Ŀ��� ����
int SkillDiffer(skill_list skill);//100�� �ְ�� �������� �����Ѵ�.
int SkillDiffer_simple(int differ, skill_type s1, skill_type s2, skill_type s3);//������ ������ ������ �����.
int SkillMana(skill_list skill);//��뿡 ��� ������ ���
bool SkillPlusCost(skill_list skill,bool check_);//�߰����� �ڽ�Ʈ 
void SkillUseTraning(skill_list skill);
const char* SkillCostString(skill_list skill);//�ڽ�Ʈǥ������

monster* BaseSummon(int id_, int time_, bool targeting_, bool random_, int range_, unit* order, coord_def target, SUMMON_KIND kind_, int max_num_);
void BaseBomb(coord_def pos, textures* t_, attack_infor& att_, unit* except_ = NULL);
int GetSpellBombRange(skill_list skill);//���߳���
int GetSpellBombRange(spell_list spell);


bool skill_elec_passive(int power, unit* order);
bool skill_elec_ball_bomb(int power, unit* order);




void SetSpell(monster_index id, monster *mon_, vector<item_infor> *item_list_, bool* random_spell);


bool MonsterUseSpell(spell_list skill, bool short_, monster* order, coord_def &target, int pow_ = -1);
bool PlayerUseSpell(spell_list skill, bool short_, coord_def &target);
bool CheckDangerSpell(int danger_);
bool CheckSucide(coord_def pos, coord_def target, bool self, int size, int smite);
int UseSkill(skill_list skill, bool short_, coord_def &target);
void SpellUse(char auto_, int auto_direc_);
void SpellView();
void SkillUse(char auto_);


string GetSpellInfor(spell_list spell);
string GetSkillInfor(skill_list skill);
string GetSpellSchoolString(spell_list spell);


#endif // __SKILL_USE_H__