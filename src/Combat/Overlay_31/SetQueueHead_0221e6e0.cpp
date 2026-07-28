#include <globaldefs.h>

#pragma optimize_for_size off

struct Queue0221e6e0 {
    int head;
    short count;
    short limit;
};

// USA: func_ov031_0221e6e0  (semantic: SetQueueHead_0221e6e0)
extern "C" THUMB void func_ov031_0221e6e0(int head, Queue0221e6e0* q) {
    q->head = head;
    q->count = 1;
}
