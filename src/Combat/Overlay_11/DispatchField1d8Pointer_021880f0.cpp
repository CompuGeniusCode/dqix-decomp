#include <globaldefs.h>

extern "C" {
    void* func_ov017_021b2164(void);
    void MapVRAMBanksToSubBG(void* p);
}

struct Obj_021880f0 {
    char pad[0x1d8];
    void* field_1d8;
};

// USA: func_ov011_021880f0
ARM int DispatchField1d8Pointer_021880f0(void) {
    Obj_021880f0* obj = (Obj_021880f0*)func_ov017_021b2164();
    MapVRAMBanksToSubBG(obj->field_1d8);
    return 1;
}
