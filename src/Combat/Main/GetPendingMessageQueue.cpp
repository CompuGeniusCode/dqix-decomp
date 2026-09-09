#include <globaldefs.h>

struct ResetObj020d7a5c;
extern struct ResetObj020d7a5c data_0214e34c;

// Returns the static message queue at data_0214e34c: three 0x70-byte text slots, the 0x150 bytes
// func_020d806c clears at static init, with the pending count in the low six bits of the flag byte
// at +0x150. func_020d7e10 strcpy's a message into the next free slot after a strcmp against slot
// 0 to drop duplicates. Twenty-two of the thirty-three callers only want the pointer to hand to
// func_020d7aa0, which empties the queue but also cancels the 0x02109400 object's loader tasks and
// reinits its controller, presumably at a scene teardown.
extern "C" ARM struct ResetObj020d7a5c* GetPendingMessageQueue() {
    return &data_0214e34c;
}
