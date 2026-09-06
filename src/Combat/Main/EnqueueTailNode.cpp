#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct MsgNode020d248c {
    MsgNode020d248c* next;   /* 0x0 */
};
struct MsgQueue020d248c {
    int _pad[2];             /* 0x0,0x4 */
    MsgNode020d248c* head;   /* 0x8 */
    MsgNode020d248c* tail;   /* 0xc */
};
extern MsgQueue020d248c data_02112780;

// USA: func_020d248c
ARM void EnqueueTailNode(MsgNode020d248c* node) {
    unsigned int mask = DisableIRQInterrupts();
    MsgNode020d248c* tail = data_02112780.tail;
    if (tail == 0) {
        data_02112780.head = node;
        data_02112780.tail = node;
    } else {
        tail->next = node;
        data_02112780.tail = node;
    }
    node->next = 0;
    SetIRQInterruptState(mask);
}
