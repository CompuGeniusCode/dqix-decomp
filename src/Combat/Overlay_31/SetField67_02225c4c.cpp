#include <globaldefs.h>
struct EntityStruct02225c4c { unsigned char pad[0x67]; unsigned char field67; };
extern EntityStruct02225c4c* data_ov031_02250c00;

// USA: func_ov031_02225c4c
ARM void SetField67_02225c4c(unsigned char v) {
	data_ov031_02250c00->field67 = v;
}
