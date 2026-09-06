#include <globaldefs.h>

struct FieldStruct021a85d4 {
    char pad[0x24];
    int field0x24;
    char pad2[0x10];
    unsigned short field0x38;
};

// USA: func_ov017_021a85d4
ARM void SetFieldndMaybe_021a85d4_021a85d4(struct FieldStruct021a85d4* obj, int val) {
    obj->field0x24 = val;
    if (val == 5) {
        obj->field0x38 = 0x3c;
    }
}
