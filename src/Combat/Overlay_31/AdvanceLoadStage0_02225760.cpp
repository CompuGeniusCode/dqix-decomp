#include <globaldefs.h>

struct EntityStruct02225760 { unsigned char pad[0x30]; int* field30; };

struct OffWrap02225760 { int v; };
struct HiWrap02225760 { int v; };

extern EntityStruct02225760* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int a, int idx, struct OffWrap02225760 off, struct HiWrap02225760 hi);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_022257d4(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_02225760  (semantic: AdvanceLoadStage0_02225760)
extern "C" ARM void func_ov031_02225760(void* obj) {
    EntityStruct02225760* e = data_ov031_02250bfc;
    int val = *e->field30;
    unsigned char e11d = *((unsigned char*)e + 0x11d);
    struct HiWrap02225760 hi;
    struct OffWrap02225760 off;
    hi.v = (unsigned int)(val & 0x1ff0000) >> 0x10;
    off.v = (val & 0xff) + 0xc;
    func_ov031_02224ca4(e11d, 0, off, hi);
    if (off.v < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_022257d4);
}
