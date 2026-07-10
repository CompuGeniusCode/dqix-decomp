#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int a, int handle);

struct Obj020dfe88 {
    char pad[0xe];
    short field_e;
    int handle;
    int field_14;
};

// USA: func_020dfe88
ARM int ResetHandleState020dfe88(struct Obj020dfe88* obj) {
    int src = GetData02104304Field4();
    if (obj->handle >= 0) {
        func_020301c8(src, obj->handle);
        obj->handle = -1;
    }
    obj->field_e = 0;
    obj->field_14 = 0;
    return 1;
}
