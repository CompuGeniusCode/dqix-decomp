#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

struct Mgr021112e0_c40 {
    char pad0[0x4];
    unsigned int counter;   /* 0x4 */
};
extern struct Mgr021112e0_c40 data_021112e0;

// USA: func_020c7c40
ARM unsigned int IncrementCounterIfNotMax020c7c40(void) {
    unsigned int mask = DisableInterrupts();
    unsigned int old;
    unsigned int count = data_021112e0.counter;
    if (count < 0xffffffff) {
        old = count;
        data_021112e0.counter = count + 1;
    }
    RestoreInterrupts(mask);
    return old;
}
