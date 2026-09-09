#include <globaldefs.h>

struct S_10088_inner {
    char unk[0x14];
    int flags;
};

struct S_10088 {
    char unk[0x138];
    struct S_10088_inner* inner;
};

// Reads bit 0 of the 32-bit flag word at +0x14 in the combatant's ModifiableCombatStats, the
// block CombatantStruct keeps at +0x138 as currentStats. The offset is not in doubt:
// func_020882f8 is handed the same c->currentStats pointer for the same word. All 78
// callers are battle code -- ov000, ov023, ov024, ov026 and three sites in main -- and each treats
// the bit as a reason to skip the combatant; it is the first test in IsCombatantIneligible_02155f9c
// and reads like a KO bit, but nothing decompiled sets it, so the name stays mechanical.
extern "C" ARM int IsCombatantModStatsFlag0x14Bit0Set(struct S_10088* obj) {
    return (obj->inner->flags & 1) != 0;
}
