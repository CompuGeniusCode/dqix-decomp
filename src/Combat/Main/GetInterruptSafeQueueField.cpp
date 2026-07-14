#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct MsgQueue020d26ec {
    int _pad0;       /* 0x0 */
    int slot4;       /* 0x4 */
    void* head;      /* 0x8 */
    int _pad1[5];    /* 0xc..0x1c */
    int slot20;      /* 0x20 */
};
extern MsgQueue020d26ec data_02112780;

// USA: func_020d26ec
ARM int GetInterruptSafeQueueField(void) {
    unsigned int mask = DisableIRQInterrupts();
    int result;
    if (data_02112780.head == 0)
        result = data_02112780.slot4;
    else
        result = data_02112780.slot20;
    SetIRQInterruptState(mask);
    return result;
}
