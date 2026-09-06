#include <globaldefs.h>

extern "C" void func_ov009_02184e58(unsigned char *self);
struct Obj0205d2bc;
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(struct Obj0205d2bc*);
extern "C" void func_0204b088(void* p, int flag);
extern "C" void func_ov023_021d9a6c(char* obj);
extern "C" void _Z31RefreshFieldIfFlag4000_021d9d34Pc(char* obj);
extern "C" void _Z22BuildFieldTag_021d9e60Pc(char* obj);
extern "C" void func_ov023_021da1dc(unsigned char *self);

// USA: func_ov009_02184ca4
extern "C" ARM void func_ov009_02184ca4(unsigned char *self) {
    func_ov009_02184e58(self);
    signed char step = *(signed char*)(self + 0xc58);
    if (step == 0 || step == 0xc) return;
    if (*(int*)(self + 0xd9c) & 0x80) return;
    _Z19InitEntries0205d2bcP11Obj0205d2bc((struct Obj0205d2bc*)(self + 0x1f8));
    _Z19InitEntries0205d2bcP11Obj0205d2bc((struct Obj0205d2bc*)(self + 0x2b4));
    if (*(int*)(self + 0xd9c) & 0x1000) {
        func_0204b088(self + 0x158, 0);
        *(int*)(self + 0xd9c) &= ~0x1000;
    }
    if (*(int*)(self + 0xd9c) & 0x2000) {
        func_0204b088(self + 0x1b8, 0);
        signed char delta = step - 8;
        if ((unsigned char)delta <= 1) {
            func_0204b088(self + 0x198, 0);
        }
        *(int*)(self + 0xd9c) &= ~0x2000;
    }
    func_ov023_021d9a6c((char*)self);
    _Z31RefreshFieldIfFlag4000_021d9d34Pc((char*)self);
    _Z22BuildFieldTag_021d9e60Pc((char*)self);
    func_ov023_021da1dc(self);
}
