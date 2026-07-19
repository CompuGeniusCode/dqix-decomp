#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int, int);

struct Obj021f5410 {
    char pad0[0xc];
    short fieldc;
    char pad2[2];
    int field10;
    int field14;
};

// USA: func_ov023_021f5410  (semantic: ReleaseHandleAndClearFields_021f5410)
extern "C" ARM int func_ov023_021f5410(struct Obj021f5410* obj) {
    int v = GetData02104304Field4();
    if (obj->field10 >= 0) {
        func_020301c8(v, obj->field10);
        obj->field10 = -1;
    }
    obj->fieldc = 0;
    obj->field14 = 0;
    return 1;
}
