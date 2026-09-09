#include <globaldefs.h>

extern int data_02107800;

// Returns the message system's global work area: the 0x1e2c-byte object func_020421c4 allocates into
// data_02107800+0x1c, one of the five buffers it wires in being the 0x960-byte one at +0x5c that
// twenty-one call sites clear and fill with marked-up message text before handing it to a UI
// element. The writers for the 0xff0b, 0xff0c, 0xff10 and 0xff1c control codes park their operands
// at +0x1948 through +0x1960 of the same object. Whether the rest of it -- 0x80 entries of 0x1c
// bytes at +0x9b8, the substruct at +0x19e0 -- is message state is not established.
extern "C" ARM int GetMessageWork() {
    return *(int*)((char*)&data_02107800 + 0x1c);
}
