#include <globaldefs.h>

unsigned int GetSubBg0ScreenBaseAddr(void);
unsigned int GetBg1ScreenBaseAddr(void);
unsigned int GetBgCharBaseAddress020c4d1c(void);

// USA: func_ov023_021db2b8  (semantic: GetBgBaseAddrBySelector_021db2b8)
extern "C" ARM unsigned int func_ov023_021db2b8(int mode, int layer) {
    if (mode == 1) {
        return GetSubBg0ScreenBaseAddr();
    }
    if (layer != 0) {
        return GetBg1ScreenBaseAddr();
    }
    return GetBgCharBaseAddress020c4d1c();
}
