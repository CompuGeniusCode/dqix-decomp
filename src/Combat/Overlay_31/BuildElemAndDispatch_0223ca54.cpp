#include <globaldefs.h>

extern "C" void* func_ov031_0223baa0(void* arr, int idx);
extern "C" void func_ov031_0223bab4(void* obj, int index, int val, int zero);
extern "C" void func_ov031_0223bb58(void* obj, int idx, int a, int b);
struct Obj0223bcc8;
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);
extern "C" void func_020b20b0(void* p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7);

struct AObj0223ca54 { unsigned char pad[0x2c]; unsigned short field2c; unsigned char field2e; unsigned char field2f; };

// USA: func_ov031_0223ca54  (semantic: BuildElemAndDispatch_0223ca54)
extern "C" ARM void func_ov031_0223ca54(AObj0223ca54* a, int b, int c, void* d, int e) {
    void* elem = func_ov031_0223baa0(d, 0);
    func_ov031_0223bab4(d, -1, 0, 0);
    func_ov031_0223bb58(d, -1, 0, 0xf);
    SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)d, -1, e);
    func_020b20b0(elem, a->field2e, a->field2f, b, c, 0, a->field2c, 2);
}
