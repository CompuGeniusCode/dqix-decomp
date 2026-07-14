#include <globaldefs.h>

unsigned int GetCpsrIrqDisableBit(void);
extern "C" void func_020caf1c(void);

struct Ctx021117ec { unsigned char pad[0x1c]; int field1c; };
extern Ctx021117ec data_021117ec;
extern int data_02111808;

// USA: func_020ce188
ARM void WaitWhileInterruptsDisabled020ce188(void) {
    int* flagPtr = &data_02111808;
    if (data_021117ec.field1c == 0) return;
    volatile unsigned short* imeReg = (volatile unsigned short*)0x4000208;
    do {
        if (GetCpsrIrqDisableBit() == 0x80 || *imeReg == 0) {
            func_020caf1c();
        }
    } while (*flagPtr != 0);
}
