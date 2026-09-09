#include <globaldefs.h>

extern "C" unsigned short func_0202df58(void);

struct CheckField0AndGlobalHalfStruct0202c508 { int field0; };

// True when the argument's first word is clear, or it is set and the halfword at data_021015a0 is
// 0; every call site passes GetMultiplayerState's object. That halfword is the local machine's index --
// func_0202bd68 swaps in its own record at self+0x7c0 exactly when the 0..3 loop reaches it -- and
// index 0 seems to be the host, since func_0202c958 sets it to 0 while setting +0xa to 1 and
// data_021015a0 sits in the DS wireless work area. What the first word means is not established:
// EnqueueGamemainEvent drops every global record when it is zero. IsMultiplayerLocalSlotNonZero is its mirror.
extern "C" ARM int IsHostOrSinglePlayer(CheckField0AndGlobalHalfStruct0202c508* obj) {
    int cond = obj->field0 != 0;
    if (cond) {
        return func_0202df58() == 0;
    }
    return 1;
}
