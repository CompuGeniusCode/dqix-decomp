#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0215e250(void* base, void* dst, int flag);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufOv0215e1d0 { char pad[0xbd0]; void* buf; };
struct FieldOv0215e1d0 { char pad[0xbb8]; int field; };

// USA: func_ov002_0215e1d0  (semantic: InitBattleTag0215e1d0)
extern "C" ARM void func_ov002_0215e1d0(char* base) {
    func_ov002_0215be00(base, ((struct FieldOv0215e1d0*)(base + 0x1000))->field & 0xff, 1, 1);

    memset(((struct BufOv0215e1d0*)(base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215e250(base, ((struct BufOv0215e1d0*)(base + 0x1000))->buf, 0);

    func_0205d304(base + 0xec8, ((struct BufOv0215e1d0*)(base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);
}
