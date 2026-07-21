#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220eb88  (semantic: GetSetInterruptFlag26a_0220eb88)
extern "C" ARM int func_ov031_0220eb88(int newVal) {
    unsigned int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    unsigned char old = *(unsigned char*)(base + 0x2000 + 0x26a);
    int ret;
    if (newVal) {
        ret = (old != 0);
        *(unsigned char*)(base + 0x2000 + 0x26a) = 1;
    } else {
        ret = (old != 0);
        *(unsigned char*)(base + 0x2000 + 0x26a) = 0;
    }
    SetIRQInterruptState(state);
    return ret;
}
