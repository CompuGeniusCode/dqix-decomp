#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_ov003_02169b30(void* obj);

// USA: func_ov003_02168cc8
ARM void SwitchSetField4ec_02168cc8(void* obj) {
    int g = GetGlobalField0x1c020421a0();
    if (*(int*)(g + 0x9a0) == 3) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
    }
    int ret = func_ov003_02169b30(obj);
    switch (ret) {
        case -1:
            return;
        case 0:
            *((unsigned char*)obj + 0x4ec) = 3;
            break;
        case 1:
            *((unsigned char*)obj + 0x4ec) = 4;
            break;
        case -2:
        case 2:
            *((unsigned char*)obj + 0x4ec) = 5;
            break;
    }
}
