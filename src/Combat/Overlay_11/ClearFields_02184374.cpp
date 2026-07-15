#include <globaldefs.h>

struct Obj_02184374 {
    short f0;
    short f2;
    char pad[0x74 - 4];
    int f74;
    int f78;
};

// USA: func_ov011_02184374
ARM void ClearFields_02184374(Obj_02184374* obj) {
    obj->f0 = 0;
    obj->f2 = 0;
    obj->f74 = 0;
    obj->f78 = 0;
}
