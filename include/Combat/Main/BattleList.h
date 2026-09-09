#pragma once

struct PrimaryCombatStats {
    unsigned short currHP;
    unsigned short currMP;
    unsigned short maxHP;
    unsigned short maxMP;
    unsigned short attack;
    unsigned short defense;
    unsigned short agility;
    unsigned short unk;
    unsigned int charm : 10;
    unsigned int magicalMight : 10;
    unsigned int magicalMending : 10;
};

struct BaseCombatStats {
    char unk[0x2C];
    struct PrimaryCombatStats primaryStats;
};

struct ModifiableCombatStats {
    struct PrimaryCombatStats primaryStats; // 0xE
    char unk1[0x44];
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
};

struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats; // TODO: holds more general info than just stats
    struct ModifiableCombatStats* currentStats; // includes things like buffs being applied
};

// The name looks wrong once the call graph in config/usa/arm9/relocs.txt is counted. 2,002
// functions call GetBattleStruct and only 229 of them are in ov000 (battle). The rest are spread
// over ov017 gamemain (397), ov003 shisetsu (164), ov004 menucallback (136), the ov023-ov026 sub_*
// family, ov002 topmenu, ov005 equipmenu, ov006 renkin, ov020 title, ov021 charamake and even
// ov031 wifi -- modules that never enter a battle. Accessors on it also reach +0x2a04 and +0x5721,
// so the real object is at least 0x5722 bytes rather than the 0x3ac declared here. It reads as the
// global game state root with the combatant list living inside it, not as a battle structure.
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9]; // TODO: validate this size as well as this struct as a whole
};
struct BattleStruct* GetBattleStruct();
struct CombatantStruct* GetCombatantFromList(struct BattleStruct* battleStruct, int id);
