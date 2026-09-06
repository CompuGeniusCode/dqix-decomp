#include <globaldefs.h>

struct StateStruct022376e4 { unsigned char pad[0x1370]; int field1370; };
extern StateStruct022376e4* data_ov031_02290d0c;

// USA: func_ov031_022376e4
ARM void SetField1370_022376e4(int val) {
    data_ov031_02290d0c->field1370 = val;
}
