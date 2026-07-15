#include <globaldefs.h>
struct EntityStruct02222e20 { unsigned char pad[0x16]; signed char field16; };
extern EntityStruct02222e20* data_ov031_02250ba8;

// USA: func_ov031_02222e20
ARM void SetField16IfMinusOne_02222e20(int v) {
	if (data_ov031_02250ba8->field16 == -1) {
		data_ov031_02250ba8->field16 = (signed char)v;
	}
}
