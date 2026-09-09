#include <globaldefs.h>

struct BattleContext020d404c { unsigned char pad[0x18]; int arr[1]; };

extern char data_021142e0;

// Installs a callback for one ARM7 reply opcode: the array at +0x18 of the context behind
// data_021142e0+4 is a function-pointer table, and the dispatcher func_020d42e0 reads the incoming
// message's opcode and calls the entry it indexes, passing the message. Each of the 27 small
// callers passes a fixed id here and the same id to func_020d40bc, which packs it into a separate
// buffer from func_020d4064, cleans the cache over that buffer and calls SendCommandToArm7. The
// opcode split and PXI tag 0xa look like NitroSDK's WM library, so presumably WMi_SetCallbackTable.
extern "C" ARM void SetArm7ReplyCallback(int index, int value) {
    struct BattleContext020d404c* ctx = *(struct BattleContext020d404c**)(&data_021142e0 + 4);
    ctx->arr[index] = value;
}
