#include <globaldefs.h>

int GetField260_0220d540(void);
extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" void func_ov031_02214520(int mode);
extern "C" int func_ov031_0220cae0(void* p, void* fn);
extern "C" void func_ov031_02213c10(void* p);
extern void SetFieldCAndA_022134cc(int v);

struct S022151d4 { int a; int b; int c; int d; };

// USA: func_ov031_022151d4
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022151d4(void) {
    int f260 = GetField260_0220d540();
    unsigned char* handler = (unsigned char*)func_ov031_022133f8(0x10);
    if (f260 == 1) {
        S022151d4 local;
        local.a = handler[0xd0a];
        local.b = 0;
        local.c = 0;
        local.d = 0;
        func_ov031_02214520(0);
        int r = func_ov031_0220cae0(&local, (void*)func_ov031_02213c10);
        if (r == 1 || r >= 4) {
            SetFieldCAndA_022134cc(1);
            return 0x11;
        }
    } else {
        return 1;
    }
    return 2;
}
