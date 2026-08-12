#include <globaldefs.h>

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* func_ov017_021b2164(void);
extern "C" int func_ov011_021849d8(void* p);
int GetData02104304Field4(void);
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern "C" void func_ov011_021849d0(void* p, int v);

extern const char data_ov011_02188b6c[];

struct S0218554c { int type; int field4; };

// USA: func_ov011_0218554c  (semantic: FormatAndDispatchValue_0218554c)
extern "C" ARM int func_ov011_0218554c(struct S0218554c* p) {
    int v = (p->type == 2) ? p->field4 : 0;
    if (v == 0) return 0;
    void* ctx = func_ov017_021b2164();
    if (func_ov011_021849d8(ctx) >= 0) return 0;
    int data4 = GetData02104304Field4();
    char buf[0x50];
    sprintf(buf, data_ov011_02188b6c, v);
    int r = CallFunc0202fa38ZeroPad(data4, (int)buf, 0);
    func_ov011_021849d0(ctx, r);
    return 1;
}
