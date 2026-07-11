#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c9ec4(int channel);

extern int data_020f226c;

// USA: func_020c3a0c
ARM int SetActiveDmaChannel020c3a0c(int channel) {
    int old = *(int*)((char*)&data_020f226c + 4);
    if (old != -1) {
        func_020c9ec4(old);
    }
    unsigned int mask = DisableInterrupts();
    *(int*)((char*)&data_020f226c + 4) = channel;
    RestoreInterrupts(mask);
    return old;
}
