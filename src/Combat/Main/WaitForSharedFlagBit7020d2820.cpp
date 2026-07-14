#include <globaldefs.h>

void SetIndexedFlagBit020cae24(int index, int value);
int TriggerAndPollRegister04fff200(void);
int IsSharedFlagBitSet(int bit, int index);
void InvokeCallbackWithInterruptsDisabled020d27fc(int channel, int packed);
extern "C" void func_020c976c(int);

// USA: func_020d2820
ARM void WaitForSharedFlagBit7020d2820(void) {
    SetIndexedFlagBit020cae24(7, (int)InvokeCallbackWithInterruptsDisabled020d27fc);
    if (TriggerAndPollRegister04fff200() == 0) return;
    if (IsSharedFlagBitSet(7, 1) != 0) return;
    do {
        func_020c976c(100);
    } while (IsSharedFlagBitSet(7, 1) == 0);
}
