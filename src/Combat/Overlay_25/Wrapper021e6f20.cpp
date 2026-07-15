#include <globaldefs.h>

extern "C" int func_ov025_021ed110(void*, int);

struct Work021ef988_021e6f20 {
    char pad[0xc];
    char* base;
};
extern struct Work021ef988_021e6f20 data_ov025_021ef988;

struct Obj021e6f20 {
    char pad8[8];
    short v;
};

// USA: func_ov025_021e6f20
ARM int Wrapper021e6f20(struct Obj021e6f20* obj) {
    func_ov025_021ed110(data_ov025_021ef988.base + 0x22c, obj->v);
    return 1;
}
