#include <globaldefs.h>

struct StateStruct02235500 { unsigned char pad[0x1c]; unsigned char field1c; unsigned char field1d; };
extern StateStruct02235500* data_ov031_02290cf4;

// USA: func_ov031_02235500
ARM void SetField1cAnd1d_02235500(int a) {
    data_ov031_02290cf4->field1c = (unsigned char)a;
    data_ov031_02290cf4->field1d = (a == 2) ? 4 : 6;
}
