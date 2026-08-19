#include <globaldefs.h>

int GetGlobal02109400(void);
extern "C" int _Z18AlwaysTrue02094b4cv(void);
extern "C" void _Z21BlankFunction02094b3cv(void);
extern "C" void _Z21BlankFunction02094b34v(void);
struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);

static inline char* Sub2000_021561b0(void* self) { return (char*)self + 0x2000; }

#pragma opt_common_subs off
// USA: func_ov002_021561b0  (semantic: ResetOrFinalizeLoaderState_021561b0)
extern "C" ARM void func_ov002_021561b0(void* self) {
    unsigned int flags = *(unsigned int*)(Sub2000_021561b0(self) + 0x47c);
    if ((flags & 2) == 0) {
        return;
    }
    unsigned char state = *(unsigned char*)(Sub2000_021561b0(self) + 0x47a);
    if (state == 0) {
        void* g = (void*)GetGlobal02109400();
        func_02094ab0((struct Obj02094ab0*)g);
        ((void (*)(void*, int)) & _Z21BlankFunction02094b3cv)(g, 0xc);
        ((void (*)(void*, int, int, int, int)) & _Z21BlankFunction02094b34v)(g, 0x64, 0x208, 0, 0);
        unsigned char* cnt = (unsigned char*)(Sub2000_021561b0(self) + 0x47a);
        *cnt = *cnt + 1;
        return;
    }
    if (state != 1) {
        return;
    }
    GetGlobal02109400();
    if (!_Z18AlwaysTrue02094b4cv()) {
        return;
    }
    unsigned int* fp = (unsigned int*)(Sub2000_021561b0(self) + 0x47c);
    *fp = *fp & ~2;
    *(unsigned char*)(Sub2000_021561b0(self) + 0x47a) = 0;
}
