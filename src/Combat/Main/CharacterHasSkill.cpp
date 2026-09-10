#include <globaldefs.h>

// Tests whether the record at combatant+0x150 has the given skill. The bit array is 0x24 bytes at
// +0x8ec, so ids 0 through 287, and func_020862a8 and func_02085fb4 pass the same index here and to
// GetSkillTableStatBonus, which resolves it through FindEntryById0209a594 in the table at
// BattleStruct+0x572c that LoadSkillTableEntries builds from data/prm/skilltable.bin -- so these are
// skilltable entry ids. func_02083acc and func_02083b28 set and clear, func_02083a50 lists the set
// ids; 0x106 rescales a cost to 0.75 + 0.75x in func_02048350 and 0xd0 gates an ov000 roll.
extern "C" ARM int CharacterHasSkill(unsigned char* obj, int index) {
    unsigned char* p = obj + index / 8;
    return (1 << (index % 8)) & p[0x8ec];
}
