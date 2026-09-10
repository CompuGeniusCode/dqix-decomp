#include <globaldefs.h>

extern void* data_021142e0[];

// Returns the ARM9-side work block of the wireless manager; data_021142e0 is a state halfword
// followed by this pointer. The module is the Nintendo wireless library: func_020d559c refuses an
// aid outside 1..15 or missing from the child bitmap, func_020d4168 hands command blocks to ARM7 as
// IPC command 0xa, and func_020d4b58 folds the MAC bytes at 0x027ffcf4 into a 200..219 value that
// is presumably a beacon period, though nothing in the ROM says so. The +4 status block is written
// by ARM7, which is why every reader invalidates it first; the reply callback table is at +0x18.
extern "C" ARM void* GetWirelessArm9Work(void) {
    return data_021142e0[1];
}
