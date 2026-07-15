#include <globaldefs.h>
struct EntityStruct02225c60 { unsigned char pad[0x68]; unsigned char field68; };
extern EntityStruct02225c60* data_ov031_02250c00;

// USA: func_ov031_02225c60
ARM void SetField68_02225c60(unsigned char v) {
	data_ov031_02250c00->field68 = v;
}
