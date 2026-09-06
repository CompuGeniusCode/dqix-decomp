#include <globaldefs.h>

struct Shorts5c_374e0;
void SetShorts0x5cTo0x60(struct Shorts5c_374e0* obj, short a, short b, short c);
extern "C" int func_020370a0(void* self, int a, int b);

struct Obj0208f36c { char pad[8]; struct Shorts5c_374e0* field8; };

ARM void* TestFusion(struct Obj0208f36c* obj, struct Shorts5c_374e0* val) {
    if (!val) {
        obj->field8 = val;
        return val;
    }
    obj->field8 = val;
    SetShorts0x5cTo0x60(val, 0x10a, 0x10a, 0x10a);
    return (void*)func_020370a0(obj->field8, 0, 0);
}
