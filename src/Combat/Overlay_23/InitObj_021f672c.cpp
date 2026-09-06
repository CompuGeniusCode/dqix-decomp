#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov023_021f6788(void*);

struct Obj021f672c {
    int field0;
    int field4;
    char pad8[0x20];
    int field28;
    short field2c;
    short field2e;
    char entries[3][0x16];
};

// USA: func_ov023_021f672c
ARM void InitObj_021f672c(struct Obj021f672c* obj) {
    obj->field0 = 0;
    obj->field4 = -1;
    memset((char*)obj + 8, 0, 0x20);
    obj->field28 = 0;
    obj->field2c = 0;
    obj->field2e = 1;
    for (int i = 0; i < 3; i++) {
        func_ov023_021f6788(obj->entries[i]);
    }
}
