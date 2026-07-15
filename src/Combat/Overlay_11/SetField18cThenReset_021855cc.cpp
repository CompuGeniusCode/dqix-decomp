#include <globaldefs.h>

extern "C" void* func_ov017_021b2164(void);
extern "C" int func_ov011_021849d8(void* p);
extern "C" void func_ov011_021849d0(void* p, int v);
extern "C" void func_020301c8(int a, int b);
int GetData02104304Field4(void);

// USA: func_ov011_021855cc
ARM int SetField18cThenReset_021855cc(void) {
    void* obj = func_ov017_021b2164();
    int val = func_ov011_021849d8(obj);
    int f = GetData02104304Field4();
    func_020301c8(f, val);
    func_ov011_021849d0(obj, -1);
    return 1;
}
