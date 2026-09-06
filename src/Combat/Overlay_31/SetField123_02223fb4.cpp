#include <globaldefs.h>

struct EntityStruct02223fb4 { unsigned char pad[0x123]; unsigned char field123; };
extern EntityStruct02223fb4* data_ov031_02250bfc;

// USA: func_ov031_02223fb4
ARM void SetField123_02223fb4(int v) {
    data_ov031_02250bfc->field123 = (unsigned char)v;
}
