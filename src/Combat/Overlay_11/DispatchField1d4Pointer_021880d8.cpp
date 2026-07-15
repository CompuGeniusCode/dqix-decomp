#include <globaldefs.h>

extern "C" {
    void* func_ov017_021b2164(void);
    void func_020c3b64(void* p);
}

struct Obj_021880d8 {
    char pad[0x1d4];
    void* field_1d4;
};

// USA: func_ov011_021880d8
ARM int DispatchField1d4Pointer_021880d8(void) {
    Obj_021880d8* obj = (Obj_021880d8*)func_ov017_021b2164();
    func_020c3b64(obj->field_1d4);
    return 1;
}
