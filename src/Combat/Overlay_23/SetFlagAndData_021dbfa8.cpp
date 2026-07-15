#include <globaldefs.h>

extern int data_ov023_021ff9e0[];

struct Obj021dbfa8 { char pad[0x79b]; unsigned char flag : 1; };

// USA: func_ov023_021dbfa8
ARM void SetFlagAndData_021dbfa8(struct Obj021dbfa8* obj, int val) {
    if (val == 0) return;
    data_ov023_021ff9e0[1] = val;
    obj->flag = 1;
}
