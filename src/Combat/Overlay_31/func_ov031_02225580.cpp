#include <globaldefs.h>

struct Elem8_02225580 { int a; int b; };
struct ElemArray_02225580 { int pad0, pad1; Elem8_02225580* arr; };
extern "C" Elem8_02225580* func_ov031_0223baa0(ElemArray_02225580* obj, int idx);

struct EntityStruct02225580 { unsigned char pad[0xfc]; ElemArray_02225580* fieldFC; };
extern EntityStruct02225580* data_ov031_02250bfc;

struct OffWrap02225580 { int v; };
struct HiWrap02225580 { int v; };
extern "C" void func_ov031_02224ca4(int a, int idx, struct OffWrap02225580 off, struct HiWrap02225580 hi);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225604(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_02225580  (semantic: AdvanceLoadStage4_02225580)
extern "C" ARM void func_ov031_02225580(void* obj) {
    Elem8_02225580* elem = func_ov031_0223baa0(data_ov031_02250bfc->fieldFC, 0);
    int val = elem->a;
    EntityStruct02225580* e = data_ov031_02250bfc;
    unsigned char e11d = *((unsigned char*)e + 0x11d);
    struct HiWrap02225580 hi;
    struct OffWrap02225580 off;
    hi.v = (unsigned int)(val & 0x1ff0000) >> 0x10;
    off.v = (val & 0xff) + 0xc;
    func_ov031_02224ca4(e11d, 4, off, hi);
    if (off.v < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02225604);
}
