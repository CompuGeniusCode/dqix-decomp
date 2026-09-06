#include <globaldefs.h>

struct StateStruct02234f34 { unsigned char pad[0x604]; unsigned char field604; };
extern StateStruct02234f34* data_ov031_02290ce8;

// USA: func_ov031_02234f34
ARM void SetField604_02234f34(void) {
    data_ov031_02290ce8->field604 = 1;
}
