#include <globaldefs.h>

static inline int isPositive(int value) {
    return value > 0;
}

// True while a master-brightness fade is still running on either screen. The object carries two
// identical channels -- current at +0xc, target at +0x10, remaining at +0x14 for the main screen,
// +0x18/+0x1c/+0x20 for the sub -- which func_0203af48 steps each frame and func_0203b080 encodes
// into MASTER_BRIGHT at 0x400006c and 0x400106c. func_ov023_021e3f34 starts a full fade to black
// over 15 frames on *(int*)GetBattleStruct() and then returns early each frame while this is
// non-zero.
extern "C" ARM int IsScreenFadeActive(int* obj) {
    if (isPositive(obj[5]) || isPositive(obj[8])) {
        return 1;
    }
    return 0;
}
