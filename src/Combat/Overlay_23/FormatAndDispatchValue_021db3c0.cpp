#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);
extern "C" long long func_0200c578(int x);
extern "C" int sprintf(void* dst, void* fmt, int a, int b);
extern "C" int func_020420e8(void* builder, int obj);
extern "C" void func_0204f41c(int a, short b, short c, void* buf, int d, int e, void* f, void* g, int h);
extern char data_ov023_021fdb28;

// USA: func_ov023_021db3c0
ARM void FormatAndDispatchValue_021db3c0(int param0, int param1, short param2, int param3, unsigned char param4) {
    char buf[0x40];
    func_0200f374(buf, 0x40);
    long long val = func_0200c578(param3);
    sprintf(buf, &data_ov023_021fdb28, (int)val, (int)(val >> 32));
    int r1val = func_020420e8(buf, 0);
    short sum = (short)(param1 - r1val);
    short outA;
    short outB;
    func_0204f41c(param0, sum, param2, buf, 8, param4, &outA, &outB, 0);
}
