#include <globaldefs.h>

struct Elem8_0223baa0 { int a, b; };
struct ElemArray_0223baa0 { int pad0, pad1; Elem8_0223baa0* arr; };

extern "C" Elem8_0223baa0* func_ov031_0223baa0(ElemArray_0223baa0* obj, int idx);
extern "C" void func_ov031_0223bab4(void* obj, int idx, int value, int flag);
extern "C" void func_ov031_0223bb58(void* obj, int idx, int a, int b);
struct Entry0223bcc8;
struct Obj0223bcc8;
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);
extern "C" void func_020b20b0(void* elem, int b1, int b2, int a1, int a2, int zero, int field2c, int two);

struct Param0223ca54 {
    char pad[0x2c];
    unsigned short field2c;
    unsigned char field2e;
    unsigned char field2f;
};

// USA: func_ov031_0223ca54
extern "C" ARM void ResetAndDispatchEntry_0223ca54(Param0223ca54* a0, int a1, int a2, ElemArray_0223baa0* a3, int a4) {
    Elem8_0223baa0* elem = func_ov031_0223baa0(a3, 0);
    func_ov031_0223bab4(a3, -1, 0, 0);
    func_ov031_0223bb58(a3, -1, 0, 0xf);
    SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)a3, -1, a4);
    func_020b20b0(elem, a0->field2e, a0->field2f, a1, a2, 0, a0->field2c, 2);
}
