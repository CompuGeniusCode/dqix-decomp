#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);

struct Obj0216aed0 {
    char pad0[0x38];
    short field38;
    char pad38[8];
    short field42;
    char pad42[1];
    unsigned char field45;
};

// USA: func_ov004_0216aed0  (semantic: SetField38IfType8AndCond_0216aed0)
extern "C" ARM int func_ov004_0216aed0(void* a, int b, int c, int d) {
    Obj0216aed0* obj = (Obj0216aed0*)func_ov023_021f6880(func_ov011_021849c8(a), b);
    if (!obj) return (int)obj;
    int type = func_ov023_021f6f10(obj);
    if (type == 8 && (obj->field38 = (short)c, d == 1)) {
    } else {
        return type;
    }
    obj->field45 = (obj->field45 & ~0x7e) | 4;
    obj->field42 = 0;
    return 0;
}
