#include <globaldefs.h>

struct EntityStruct02223fc8 { unsigned char pad[0x124]; unsigned char field124; };
extern EntityStruct02223fc8* data_ov031_02250bfc;

// USA: func_ov031_02223fc8
ARM void SetField124_02223fc8(int v) {
    data_ov031_02250bfc->field124 = (unsigned char)v;
}
