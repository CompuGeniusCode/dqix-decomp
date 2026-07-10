#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

struct Mgr021112e0_c74 {
    char pad0[0x4];
    unsigned int counter;   /* 0x4 */
};
extern struct Mgr021112e0_c74 data_021112e0;

// USA: func_020c7c74
ARM unsigned int DecrementCounterIfNonzero020c7c74(void) {
    unsigned int mask = DisableInterrupts();
    unsigned int old = 0;
    unsigned int count = data_021112e0.counter;
    if (count != 0) {
        old = count;
        data_021112e0.counter = count - 1;
    }
    RestoreInterrupts(mask);
    return old;
}
