#include <globaldefs.h>
void WaitDmaIdleAndResetChannel0(int);

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

extern int data_020f226c;

// USA: func_020c3a0c
ARM int SetActiveDmaChannel020c3a0c(int channel) {
    int old = *(int*)((char*)&data_020f226c + 4);
    if (old != -1) {
        WaitDmaIdleAndResetChannel0((int)(old));
    }
    unsigned int mask = DisableInterrupts();
    *(int*)((char*)&data_020f226c + 4) = channel;
    RestoreInterrupts(mask);
    return old;
}
