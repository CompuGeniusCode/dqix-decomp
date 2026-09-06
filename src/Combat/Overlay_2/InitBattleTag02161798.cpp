#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_02157030(void* base, int type, short* a, short* b, short* c, short* d);
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0216186c(void* base, void* dst, int flag);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufOv02161798 { char pad[0xbd0]; void* buf; };
struct FieldOv02161798 { char pad[0xbb8]; int field; };

// USA: func_ov002_02161798
ARM void InitBattleTag02161798(char* base) {
    short s16 = 0, s14 = 0, s12 = 1, s10 = 1;
    func_ov002_02157030(base, 0x27, &s16, &s14, &s12, &s10);
    s16 = s16 + 2;
    s14 = s14 + 0xb;
    func_ov002_0215be00(base, ((struct FieldOv02161798*)(base + 0x1000))->field & 0xff, s16, s14);

    memset(((struct BufOv02161798*)(base + 0x1000))->buf, 0, 0x960);
    func_ov002_0216186c(base, ((struct BufOv02161798*)(base + 0x1000))->buf, 0);

    func_0205d304(base + 0xec8, ((struct BufOv02161798*)(base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);
}
