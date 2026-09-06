#include <globaldefs.h>

struct StateStruct0223521c { unsigned char pad[0x1e]; unsigned char field1e; };
extern StateStruct0223521c* data_ov031_02290cf4;

// USA: func_ov031_0223521c
ARM void SetField1e_0223521c(void) {
    data_ov031_02290cf4->field1e = 1;
}
