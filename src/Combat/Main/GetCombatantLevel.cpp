#include <globaldefs.h>

// The character record hanging off a combatant at +0x150 stores one level per vocation: +0x950 is
// the current vocation index and the halfwords from +0x16c are indexed by it. func_02082fc4 proves
// both halves - it formats that same +0x950 into "data/prm/level%d.bin", of which the ROM holds
// level0 through level12, and then uses record[0x16c + vocation*2] as the row to read out of the
// loaded table. Callers agree: ov003 compares the result with 99 for max level and ov024 buckets
// it at 25, 50 and 75.
extern "C" ARM unsigned short GetCombatantLevel(void* obj) {
    char* p = *(char**)((char*)obj + 0x150);
    int index = *(int*)(p + 0x950);
    return *(unsigned short*)(p + index * 2 + 0x16c);
}
