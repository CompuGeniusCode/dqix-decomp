#include <globaldefs.h>

extern int data_02112148;

unsigned int DisableInterrupts(void);
int IsReadyAndBit0Clear(void);
unsigned int RestoreInterrupts(unsigned int mask);
void UpdateDataAccessPermission(unsigned int clearMask, unsigned int setMask);

// USA: func_020d15b4
ARM void SetModeFlagAndUpdatePermission020d15b4(int flag) {
    unsigned int savedIntr = DisableInterrupts();
    data_02112148 = flag;
    if (!IsReadyAndBit0Clear()) {
        UpdateDataAccessPermission(0xf000, flag != 0 ? 0x1000 : 0x5000);
    }
    RestoreInterrupts(savedIntr);
}
