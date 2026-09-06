#include <globaldefs.h>

extern "C" int DisableTextureImageVRAMBanks();
extern "C" int DisableTexturePaletteVRAMBanks();
extern "C" int DisableMainBGVRAMBanks();
extern "C" int DisableMainObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" int DisableSubObjVRAMBanks();

struct FieldSet02097bc4 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char pad18[6];
    unsigned char field1e;
};

// USA: func_02097bc4
ARM void SetFieldGroupFromFlags02097bc4(struct FieldSet02097bc4* obj, int flags) {
    obj->field1e = (unsigned char)flags;
    if (flags & 1) {
        obj->field0 = DisableTextureImageVRAMBanks();
        obj->field4 = DisableTexturePaletteVRAMBanks();
        obj->field8 = DisableMainBGVRAMBanks();
        obj->fieldC = DisableMainObjVRAMBanks();
    }
    if (flags & 2) {
        obj->field10 = DisableSubBGVRAMBanks();
        obj->field14 = DisableSubObjVRAMBanks();
    }
}
