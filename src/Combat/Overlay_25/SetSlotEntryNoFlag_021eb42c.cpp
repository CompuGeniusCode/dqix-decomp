#include <globaldefs.h>

struct Obj021e8a20 {
    int a;
    short b;
    short c;
    unsigned char d;
    unsigned char e;
};

void Init021e8a20(struct Obj021e8a20* obj);
extern "C" int func_ov025_021eb188(void* arg0, struct Obj021e8a20* obj);

// USA: func_ov025_021eb42c
ARM int SetSlotEntryNoFlag_021eb42c(void* arg0, short b, short c) {
    struct Obj021e8a20 local;
    Init021e8a20(&local);
    local.b = b;
    local.c = c;
    local.d = 0;
    return func_ov025_021eb188(arg0, &local);
}
