#include <globaldefs.h>

struct EntityStruct022256ec { unsigned char pad[0x60]; int* field60; };

struct OffWrap022256ec { int v; };
struct HiWrap022256ec { int v; };

extern EntityStruct022256ec* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int a, int idx, struct OffWrap022256ec off, struct HiWrap022256ec hi);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225760(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_022256ec  (semantic: AdvanceLoadStage1_022256ec)
extern "C" ARM void func_ov031_022256ec(void* obj) {
    EntityStruct022256ec* e = data_ov031_02250bfc;
    int val = *e->field60;
    unsigned char e11d = *((unsigned char*)e + 0x11d);
    struct HiWrap022256ec hi;
    struct OffWrap022256ec off;
    hi.v = (unsigned int)(val & 0x1ff0000) >> 0x10;
    off.v = (val & 0xff) + 0xc;
    func_ov031_02224ca4(e11d, 1, off, hi);
    if (off.v < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02225760);
}
