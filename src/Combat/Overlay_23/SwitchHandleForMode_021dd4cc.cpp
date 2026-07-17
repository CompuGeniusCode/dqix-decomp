#include <globaldefs.h>

extern "C" int GetData02104304Field4();
extern "C" void func_020301c8(int a, int b);
extern "C" int CallFunc0202fa38Mode2(int a, int b, int c, int d);
extern int data_ov023_021fdb40, data_ov023_021fdb52, data_ov023_021fdb60, data_ov023_021fdb72;

struct ModeHandleObj021dd4cc {
    char pad[0x774];
    unsigned short field774;
    char pad2[0x77d - 0x776];
    signed char field77d;
    signed char field77e;
    char pad3;
    int field780;
};

// USA: func_ov023_021dd4cc
ARM void SwitchHandleForMode_021dd4cc(struct ModeHandleObj021dd4cc* obj, int mode) {
    int handle = GetData02104304Field4();
    if (mode == obj->field77d) {
        if (obj->field780 < 0) return;
        func_020301c8(handle, obj->field780);
        obj->field780 = -1;
        obj->field77e = obj->field77d;
        return;
    }
    if (mode == obj->field77e) return;
    if (obj->field780 >= 0) {
        func_020301c8(handle, obj->field780);
        obj->field780 = -1;
        obj->field77e = -1;
    }
    if (mode == 2)
        obj->field780 = CallFunc0202fa38Mode2(handle, (int)&data_ov023_021fdb40, (int)&data_ov023_021fdb52, 0);
    else
        obj->field780 = CallFunc0202fa38Mode2(handle, (int)&data_ov023_021fdb60, (int)&data_ov023_021fdb72, 0);
    obj->field774 |= 8;
    obj->field77e = (signed char)mode;
}
