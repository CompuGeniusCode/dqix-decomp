#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int FastIntModulus(int numer, int denom);

struct RingQueue0223bfa0 {
    unsigned short count;
    unsigned char head;
    unsigned char tail;
};

// USA: func_ov031_0223bfa0  (semantic: PopRingQueue_0223bfa0)
extern "C" ARM int func_ov031_0223bfa0(struct RingQueue0223bfa0* q) {
    int value = 0;
    unsigned int irq = DisableSpecificInterrupts(1);
    if (q->head != q->tail) {
        int newTail = FastIntModulus(q->tail + q->count - 1, q->count);
        q->tail = newTail;
        value = *(int*)((char*)q + q->tail * 4 + 4);
    }
    EnableSpecificInterrupts(irq);
    return value;
}
