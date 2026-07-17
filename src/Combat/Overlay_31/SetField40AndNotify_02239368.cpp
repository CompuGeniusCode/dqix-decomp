#include <globaldefs.h>

ARM void SetField40AndNotify_02239368(int val);
ARM void SetField54IfTagNot9Or10(int v);

struct Arg02239b64 { unsigned char pad[2]; unsigned short field2; };

// USA: func_ov031_02239b64
ARM void DispatchByField2_02239b64(Arg02239b64* obj) {
    unsigned short v = obj->field2;
    if (v != 0) {
        SetField40AndNotify_02239368(9);
        SetField54IfTagNot9Or10(obj->field2);
        return;
    }
    SetField40AndNotify_02239368(1);
}
