#include <globaldefs.h>

extern char data_021015a0;

// Latches the first error the wireless link driver hits: callers pass a WM callback's errcode - the
// halfword at +2 of the callback block - or a request wrapper's return, then set data_021015a0+0x10
// to state 9 or 10; refusing to store while already in those states keeps the original failure
// rather than the one it cascaded into. The getter at 0x0202d6b8 reads it back, the session reset at
// 0x0202da2c clears it. data_021015a0 is the wireless driver block, +0 the local slot; the wrappers
// from 0x020d4fa4 on are WM api ids, 0x18 capping a payload at 0x70 and 0x0a a channel to 1-14.
extern "C" ARM void RecordWirelessErrorCode(int arg) {
    if ((unsigned)(*(int*)(&data_021015a0 + 0x10) - 9) > 1)
        *(int*)(&data_021015a0 + 0x48) = arg;
}
