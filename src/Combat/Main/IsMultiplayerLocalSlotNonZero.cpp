#include <globaldefs.h>

extern "C" unsigned short func_0202df58(void);

struct CheckField0AndGlobalHalfStruct { int field0; };

// True when a multiplayer session is running (field0 of what GetMultiplayerState returns) and the
// halfword at data_021015a0+0 is non-zero. That halfword is this console's slot: func_0202bd68 and
// func_02046be08 walk slots 0..3 and read the local record at self+0x7c0 when the loop index equals
// it, and GetLocalPlayerId indexes the 16 signed bytes at state+0x1038 with it. IsHostOrSinglePlayer is the
// exact inverse. The only decompiled writes to the halfword store 0, so what a non-zero slot means
// is not established.
extern "C" ARM int IsMultiplayerLocalSlotNonZero(CheckField0AndGlobalHalfStruct* obj) {
    int cond = obj->field0 != 0;
    if (cond) {
        return func_0202df58() != 0;
    }
    return 0;
}
