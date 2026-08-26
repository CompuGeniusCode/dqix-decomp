#include <globaldefs.h>

struct Triple9_020ca7d0 {
    unsigned int x, y, z;
};

struct ClearedStruct36_020ca7d0 {
    Triple9_020ca7d0 a, b, c;
};

// USA: func_020ca7d0  (semantic: ClearStruct36_020ca7d0)
extern "C" THUMB void func_020ca7d0(ClearedStruct36_020ca7d0* obj) {
    Triple9_020ca7d0 zero;
    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    obj->a = zero;
    obj->b = zero;
    obj->c = zero;
}
