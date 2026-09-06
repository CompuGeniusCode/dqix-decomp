#include <globaldefs.h>
struct EntityStruct02222e80 { unsigned char pad[0x18]; unsigned char field18; };
extern EntityStruct02222e80* data_ov031_02250ba8;
// USA: func_ov031_02222e80
ARM void ClearField18_02222e80(void) {
	data_ov031_02250ba8->field18 = 0;
}
