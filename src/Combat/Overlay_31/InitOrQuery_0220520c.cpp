#include <globaldefs.h>

struct InitData020c7de4 {
    int a; int b; int c; int d;
    int e; int f; int g; int h;
};

ARM void InitStruct020c7de4(InitData020c7de4* s, int e, int f);
extern "C" ARM int func_020c7ea0(void* data, int* out, int count);
extern "C" ARM int func_ov031_022051a8(void* a, void* b);

struct Obj0220520c {
    unsigned char pad0[8];
    void* field8;
    unsigned char pad1[1];
    signed char field0d;
};

// USA: func_ov031_0220520c  (semantic: InitOrQuery_0220520c)
extern "C" ARM int func_ov031_0220520c(void* obj1, Obj0220520c* obj2) {
    int result;
    if (obj2->field0d == 1) {
        int outVal;
        InitData020c7de4 initData;
        InitStruct020c7de4(&initData, (int)&outVal, 1);
        obj2->field8 = &initData;
        func_ov031_022051a8(obj1, obj2);
        func_020c7ea0(&initData, &result, 1);
    } else {
        obj2->field8 = NULL;
        result = func_ov031_022051a8(obj1, obj2);
    }
    return result;
}
