#include <globaldefs.h>

int IsNotInList0224e22c_02207180(void* v);
extern "C" ARM int func_ov031_02205814(void* obj);

struct Obj022056bc {
    char pad0[0x70];
    short field70;
    char pad72;
    signed char field73;
    short field74;
};

// USA: func_ov031_022056bc  (semantic: SetValueIfValid_022056bc)
extern "C" ARM int func_ov031_022056bc(Obj022056bc* obj, int val) {
    if (IsNotInList0224e22c_02207180(obj)) {
        return ~0x1b;
    }
    int flag = 0;
    if (obj == NULL) goto checkFlag;
    if (!(obj->field70 & 1)) goto checkFlag;
    flag = 1;
checkFlag:
    if (!flag) {
        return ~0x26;
    }
    if (obj->field70 & 2) {
        return ~6;
    }
    obj->field74 = (short)val;
    if (obj->field73 != 1) {
        return 0;
    }
    return func_ov031_02205814(obj);
}
