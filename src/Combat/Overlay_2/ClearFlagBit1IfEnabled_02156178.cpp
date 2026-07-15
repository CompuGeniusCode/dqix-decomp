#include <globaldefs.h>

extern "C" int func_ov023_021dc488(void* obj);

// USA: func_ov002_02156178
ARM void ClearFlagBit1IfEnabled_02156178(unsigned char* obj) {
    if ((*(int*)(obj + 0x2000 + 0x47c) & 1) == 0) return;
    if (func_ov023_021dc488(obj + 0x50) != 0) {
        *(int*)(obj + 0x2000 + 0x47c) &= ~1;
    }
}
