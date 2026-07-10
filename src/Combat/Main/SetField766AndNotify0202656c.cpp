#include <globaldefs.h>

extern int data_020ef6d0;
extern "C" void func_02003ce8(void* dst, void* src, int arg3);

struct Obj0202656c {
    char pad[0x766];
    unsigned short f766;
};

// USA: func_0202656c
ARM void SetField766AndNotify0202656c(struct Obj0202656c* p, int val) {
    p->f766 = val;
    if (p->f766 == 0) return;
    if (p->f766 >= 0x3e8) return;
    func_02003ce8((char*)p + 0x6ec, &data_020ef6d0, val);
}
