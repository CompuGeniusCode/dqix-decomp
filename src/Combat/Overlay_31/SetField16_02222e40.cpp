#include <globaldefs.h>
struct EntityStruct02222e40 { unsigned char pad[0x16]; signed char field16; };
extern EntityStruct02222e40* data_ov031_02250ba8;

// USA: func_ov031_02222e40
ARM void SetField16_02222e40(int v) {
	data_ov031_02250ba8->field16 = (signed char)v;
}
