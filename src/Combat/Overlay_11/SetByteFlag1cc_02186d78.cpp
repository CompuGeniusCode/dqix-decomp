#include <globaldefs.h>

extern "C" void* func_ov017_021b2164(void);

struct Obj_02186d78 {
    char pad[0x1cc];
    unsigned char flag_1cc;
};

// USA: func_ov011_02186d78
ARM int SetByteFlag1cc_02186d78(void) {
    Obj_02186d78* obj = (Obj_02186d78*)func_ov017_021b2164();
    obj->flag_1cc = 1;
    return 1;
}
