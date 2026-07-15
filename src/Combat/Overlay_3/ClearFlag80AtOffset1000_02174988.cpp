#include <globaldefs.h>

extern "C" int func_ov023_021dc488(void* obj);

// USA: func_ov003_02174988
ARM void ClearFlag80AtOffset1000_02174988(char* self) {
    if ((*(unsigned short*)(self + 0x1000 + 0x46) & 0x80) == 0) {
        return;
    }
    if (func_ov023_021dc488(self + 0x3c) != 0) {
        *(unsigned short*)(self + 0x1000 + 0x46) &= ~0x80;
    }
}
