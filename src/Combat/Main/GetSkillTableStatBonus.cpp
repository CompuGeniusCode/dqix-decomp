#include <globaldefs.h>

struct Entry0201137c { int a; unsigned int b; };
extern "C" struct Entry0201137c* func_0209a594(void* p, int id);

// Reads the 8-bit field packed at bits 12..19 of a skill's record in the skill table, which
// func_0201133c parks at +0x572c of the battle struct as an {entries, count} header after
// LoadSkillTableEntries runs data/prm/skilltable.bin through the script interpreter. The argument is
// a skill id, keyed 11 bits wide and capped at 0x11f; eleven of the 22 call sites gate on
// CharacterHasSkill for the same id, and func_02084a64 sums the results over a fixed per-stat skill
// list before clamping to 999. That the field is a stat bonus is inferred from that use only.
extern "C" ARM int GetSkillTableStatBonus(char* base, int id) {
    struct Entry0201137c* e;
    unsigned int result = 0;
    e = func_0209a594(base + 0x572c, id);
    if (e != NULL) {
        result = (e->b << 12) >> 24;
    }
    return result;
}
