#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

struct Mgr021112e0_c08 {
    char pad0[0x30];
    void* slot;   /* 0x30 */
};
extern struct Mgr021112e0_c08 data_021112e0;

// USA: func_020c7c08
ARM void* SwapGlobalPointer020c7c08(void* value) {
    unsigned int mask = DisableInterrupts();
    void* old = data_021112e0.slot;
    data_021112e0.slot = value;
    RestoreInterrupts(mask);
    return old;
}
