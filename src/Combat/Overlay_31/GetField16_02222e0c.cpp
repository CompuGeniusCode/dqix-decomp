#include <globaldefs.h>
struct EntityStruct02222e0c { unsigned char pad[0x16]; signed char field16; };
extern EntityStruct02222e0c* data_ov031_02250ba8;

// USA: func_ov031_02222e0c
ARM int GetField16_02222e0c(void) {
	return data_ov031_02250ba8->field16;
}
