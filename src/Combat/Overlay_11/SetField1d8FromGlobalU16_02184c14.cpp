#include <globaldefs.h>

extern "C" unsigned short GetSubBGVRAMBanks(void);

struct StateStruct_02184c14 {
    char pad[0x1d8];
    unsigned int field_1d8;
};

// USA: func_ov011_02184c14
ARM void SetField1d8FromGlobalU16_02184c14(StateStruct_02184c14* obj) {
    obj->field_1d8 = GetSubBGVRAMBanks();
}
