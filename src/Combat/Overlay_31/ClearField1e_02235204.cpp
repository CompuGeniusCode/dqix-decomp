#include <globaldefs.h>

struct StateStruct02235204 { unsigned char pad[0x1e]; unsigned char field1e; };
extern StateStruct02235204* data_ov031_02290cf4;

// USA: func_ov031_02235204
ARM void ClearField1e_02235204(void) {
    data_ov031_02290cf4->field1e = 0;
}
