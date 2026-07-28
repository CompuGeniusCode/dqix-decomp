#include <globaldefs.h>

extern "C" void func_ov003_021612c0(void*);
extern "C" int func_ov003_02161344(void*);

struct Struct4a3_02163f60 { char pad[0x4a3]; unsigned char code; unsigned char step; };

// USA: func_ov003_02163f60  (semantic: AdvanceStep_02163f60)
#pragma optimize_for_size off
extern "C" ARM void func_ov003_02163f60(Struct4a3_02163f60* obj) {
    if (obj->step == 0) {
        func_ov003_021612c0(obj);
        obj->step = obj->step + 1;
        return;
    }
    if (obj->step != 1) return;
    int r = func_ov003_02161344(obj);
    if (r != -1) {
        if (r != 1) return;
        *(short*)((char*)obj + 0x484) = 0x2b;
        obj->step = 0;
        return;
    }
    obj->code = 10;
    obj->step = 0;
}
