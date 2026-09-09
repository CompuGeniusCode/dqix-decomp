#include <globaldefs.h>

struct Timer021d9494 {
    char pad0[0x84];
    long long f84;
    long long f8c;
    int f94;
    int f98;
    unsigned char f9c;
    char pad9d[3];
    long long fa0;
    long long fa8;
};

extern "C" void func_ov028_021d8b90(void* obj);

// USA: func_ov028_021d9494
extern "C" ARM void func_ov028_021d9494(void* p) {
    struct Timer021d9494* obj = (struct Timer021d9494*)p;
    func_ov028_021d8b90(p);
    obj->f8c = 0;
    obj->f84 = obj->f8c;
    obj->f94 = obj->f98 = 0;
    obj->fa8 = 0;
    obj->fa0 = obj->fa8;
    obj->f9c = 0;
}
