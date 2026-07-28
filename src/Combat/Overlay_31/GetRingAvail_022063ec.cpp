#include <globaldefs.h>

struct Ring022063ec { char pad[0x100]; unsigned short head; unsigned short tail; };
struct Obj022063ec { char pad[0x68]; Ring022063ec* ring; };

// USA: func_ov031_022063ec  (semantic: GetRingAvail_022063ec)
extern "C" ARM int func_ov031_022063ec(Obj022063ec* obj) {
    Ring022063ec* ring = obj->ring;
    int capacity = *(int*)((char*)ring + 0xf8);
    volatile unsigned short* headp = &ring->head;
    unsigned short head = *headp;
    int diff = ring->tail - head - 1;
    if (diff < 0) diff += capacity;
    return diff;
}
