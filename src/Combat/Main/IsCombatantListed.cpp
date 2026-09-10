#include <globaldefs.h>

struct ArrayContainsByteStruct {
    char pad[0xf78];
    unsigned char arr[4];
    unsigned char count;
};

// Answers whether a combatant id appears in the four-entry list at +0xf78 of the block returned by
// GetPlayerData, whose count is the byte at +0xf7c; siblings on the same layout (func_02086b98,
// func_020874bc, func_02086aec) turn each listed byte into a CombatantStruct. func_02086d88 removes a
// key from three maps in this block and then from each listed combatant's own slot list, which reads
// like consuming something held both by the bag and by each listed character. What the list means is
// still open: ov017 rewrites it from a selection routine, so it may be a per-action set, not a roster.
extern "C" ARM int IsCombatantListed(struct ArrayContainsByteStruct* s, int val) {
    int i;
    for (i = 0; i < s->count; i++) {
        if (val == s->arr[i]) {
            return 1;
        }
    }
    return 0;
}
