#include <globaldefs.h>

struct EntityStruct02225604 { unsigned char pad[0xc0]; int* fieldC0; };

struct OffWrap02225604 { int v; };
struct HiWrap02225604 { int v; };

extern EntityStruct02225604* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int a, int idx, struct OffWrap02225604 off, struct HiWrap02225604 hi);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225678(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_02225604  (semantic: AdvanceLoadStage3_02225604)
extern "C" ARM void func_ov031_02225604(void* obj) {
    EntityStruct02225604* e = data_ov031_02250bfc;
    int val = *e->fieldC0;
    unsigned char e11d = *((unsigned char*)e + 0x11d);
    struct HiWrap02225604 hi;
    struct OffWrap02225604 off;
    hi.v = (unsigned int)(val & 0x1ff0000) >> 0x10;
    off.v = (val & 0xff) + 0xc;
    func_ov031_02224ca4(e11d, 3, off, hi);
    if (off.v < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02225678);
}
