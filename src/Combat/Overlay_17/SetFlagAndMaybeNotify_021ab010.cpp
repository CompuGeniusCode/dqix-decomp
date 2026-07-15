#include <globaldefs.h>

extern "C" void func_ov017_021aaf08(void* p);
int IsHandleB8Active0209c6bc(void* obj);
extern "C" void func_0209c5e8(void* obj);
extern "C" void func_0209c2e0(void* obj, int a, int b);

extern int data_02109bf4;

struct Obj021ab010 {
    unsigned char pad0[1];
    unsigned char b1;
};

// USA: func_ov017_021ab010
ARM void SetFlagAndMaybeNotify_021ab010(void* p, int flag) {
    func_ov017_021aaf08(p);
    if (flag) {
        if (!IsHandleB8Active0209c6bc(&data_02109bf4)) {
            func_0209c5e8(&data_02109bf4);
            func_0209c2e0(&data_02109bf4, 0x7f, 0);
        }
    }
    ((Obj021ab010*)p)->b1 = 1;
}
