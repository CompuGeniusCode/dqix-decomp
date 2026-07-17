#include <globaldefs.h>

ARM void SetField54IfTagNot9Or10(int v);
extern "C" void func_ov031_0223a374(void);
int SetupSlot13AndSetField54_02239ad8(void);
ARM void SetField40AndNotify_02239368(int val);

struct Arg02239aa4 { unsigned char pad[2]; unsigned short field2; };

// USA: func_ov031_02239aa4
ARM void CheckField2ThenDispatch_02239aa4(Arg02239aa4* obj) {
    unsigned short v = obj->field2;
    if (v != 0) {
        SetField54IfTagNot9Or10(v);
        func_ov031_0223a374();
        return;
    }
    if (SetupSlot13AndSetField54_02239ad8() != 0) {
        return;
    }
    SetField40AndNotify_02239368(9);
}
