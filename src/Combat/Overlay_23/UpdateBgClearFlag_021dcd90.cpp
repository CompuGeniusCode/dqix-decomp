#include <globaldefs.h>
#include "std_library_functions.h"

unsigned int GetBg1ScreenBaseAddr(void);
unsigned int GetBgCharBaseAddress020c4d1c(void);
void ResetPendingSlotsAndFlags_021dcdf4(void* obj);

struct Obj021dcd90 {
    char pad[0x79b];
    unsigned char bit0 : 1;
    unsigned char flagBit1 : 1;
    unsigned char rest : 6;
};

// USA: func_ov023_021dcd90  (semantic: UpdateBgClearFlag_021dcd90)
extern "C" ARM void func_ov023_021dcd90(Obj021dcd90* obj, unsigned char enable) {
    if (obj->flagBit1 && !enable) {
        memset((void*)GetBg1ScreenBaseAddr(), 0, 0x800);
        memset((void*)GetBgCharBaseAddress020c4d1c(), 0, 0x800);
        ResetPendingSlotsAndFlags_021dcdf4(obj);
    }
    obj->flagBit1 = enable;
}
