#include <globaldefs.h>

struct StateStruct022351e4 { unsigned char pad[0x1d]; unsigned char field1d; };
extern StateStruct022351e4* data_ov031_02290cf4;

// USA: func_ov031_022351e4
ARM unsigned char GetField1d_022351e4(void) {
    return data_ov031_02290cf4->field1d;
}
