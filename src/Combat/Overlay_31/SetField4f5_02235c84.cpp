#include <globaldefs.h>

struct Struct02235c84 { unsigned char pad[0x4f5]; unsigned char field4f5; };
extern Struct02235c84* data_ov031_02290cfc;

// USA: func_ov031_02235c84
ARM void SetField4f5_02235c84(unsigned char val) {
    data_ov031_02290cfc->field4f5 = val;
}
