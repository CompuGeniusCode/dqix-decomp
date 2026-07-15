#include <globaldefs.h>
struct EntityStruct02222e98 { unsigned char pad[0x18]; unsigned char field18; };
extern EntityStruct02222e98* data_ov031_02250ba8;
// USA: func_ov031_02222e98
ARM void SetField18_02222e98(void) {
	data_ov031_02250ba8->field18 = 1;
}
