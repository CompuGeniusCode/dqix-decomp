#include <globaldefs.h>
extern "C" int GetData02104304Field4();
extern "C" void func_020301c8(int a, int b);
extern "C" int CallFunc0202fa38Mode2(int a, int b, int c, int d);
extern int data_ov023_021fdb40, data_ov023_021fdb52, data_ov023_021fdb60, data_ov023_021fdb72;
struct ObjC { char pad[0x774]; unsigned short f774; char pad2[0x77d-0x776]; signed char f77d; signed char f77e; char pad3; int f780; };
ARM void test(struct ObjC* obj, int mode) {
    int handle = GetData02104304Field4();
    if (mode == obj->f77d) {
        if (obj->f780 < 0) return;
        func_020301c8(handle, obj->f780);
        obj->f780 = -1;
        obj->f77e = obj->f77d;
        return;
    }
    if (mode == obj->f77e) return;
    if (obj->f780 >= 0) {
        func_020301c8(handle, obj->f780);
        obj->f780 = -1;
        obj->f77e = -1;
    }
    if (mode == 2)
        obj->f780 = CallFunc0202fa38Mode2(handle, (int)&data_ov023_021fdb40, (int)&data_ov023_021fdb52, 0);
    else
        obj->f780 = CallFunc0202fa38Mode2(handle, (int)&data_ov023_021fdb60, (int)&data_ov023_021fdb72, 0);
    obj->f774 |= 8;
    obj->f77e = (signed char)mode;
}
