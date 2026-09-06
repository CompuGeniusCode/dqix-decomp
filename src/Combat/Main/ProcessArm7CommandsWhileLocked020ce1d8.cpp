#include <globaldefs.h>

unsigned int GetIRQInterruptState(void);
int GetProcessorMode(void);
void HandleCommandReceivedFromArm7(void);

struct Ctx021117ec { unsigned char pad[0x1c]; int field1c; };
extern Ctx021117ec data_021117ec;
extern int data_02111808;

// USA: func_020ce1d8  (semantic: ProcessArm7CommandsWhileLocked020ce1d8)
extern "C" ARM void func_020ce1d8(void) {
    int* flagPtr = &data_02111808;
    if (data_021117ec.field1c == 0) return;
    volatile unsigned short* imeReg = (volatile unsigned short*)0x4000208;
    do {
        if (GetIRQInterruptState() == 0x80 || *imeReg == 0 || GetProcessorMode() == 0x12) {
            HandleCommandReceivedFromArm7();
        }
    } while (*flagPtr != 0);
}
