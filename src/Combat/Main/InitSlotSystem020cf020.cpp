#include <globaldefs.h>

void CallFunc020cad24_020cad18(void);
int IsSharedFlagBitSet(int bit, int index);
void SetIndexedFlagBit020cae24(int index, int value);
extern "C" void func_020cf294(void);

extern char data_02111818;

// USA: func_020cf020
ARM void InitSlotSystem020cf020(void) {
    if (*(unsigned short*)(&data_02111818 + 0x0) != 0) return;
    *(unsigned short*)(&data_02111818 + 0x0) = 1;
    *(int*)(&data_02111818 + 0xc) = 0;
    *(int*)(&data_02111818 + 0x10) = 0;
    *(int*)(&data_02111818 + 0x28) = 0;
    *(int*)(&data_02111818 + 0x14) = 0;
    *(int*)(&data_02111818 + 0x18) = 0;
    CallFunc020cad24_020cad18();
    while (IsSharedFlagBitSet(5, 1) == 0) {
    }
    SetIndexedFlagBit020cae24(5, (int)func_020cf294);
}
