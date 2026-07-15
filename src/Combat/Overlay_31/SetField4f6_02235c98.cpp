#include <globaldefs.h>

struct Struct02235c98 { unsigned char pad[0x4f6]; unsigned char field4f6; };
extern Struct02235c98* data_ov031_02290cfc;

// USA: func_ov031_02235c98
ARM void SetField4f6_02235c98(unsigned char val) {
    data_ov031_02290cfc->field4f6 = val;
}
