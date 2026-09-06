#include <globaldefs.h>

extern "C" void func_ov028_021d8b44(void* obj, void* alloc);
unsigned long long GetCurrentTimestamp(void);

struct Obj9530 {
    char pad84[0x84];
    unsigned long long p84;
    unsigned long long p8c;
    int f94;
    int f98;
    unsigned char f9c;
    char pad9d[3];
    unsigned int fa0;
    unsigned int fa4;
};

// USA: func_ov028_021d9530
extern "C" ARM void func_ov028_021d9530(Obj9530* obj, void* alloc) {
    func_ov028_021d8b44(obj, alloc);
    obj->p8c = 0;
    obj->p84 = obj->p8c;
    obj->f98 = 0;
    obj->f94 = 0;
    obj->f9c = 0;
    unsigned long long ts = GetCurrentTimestamp();
    obj->fa0 = (unsigned int)ts;
    obj->fa4 = (unsigned int)(ts >> 32);
}
