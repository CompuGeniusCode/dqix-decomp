#include <globaldefs.h>

struct StateStruct022351d0 { unsigned char pad[0x1a]; unsigned char field1a; };
extern StateStruct022351d0* data_ov031_02290cf4;

// USA: func_ov031_022351d0
ARM unsigned char GetField1a_022351d0(void) {
    return data_ov031_02290cf4->field1a;
}
