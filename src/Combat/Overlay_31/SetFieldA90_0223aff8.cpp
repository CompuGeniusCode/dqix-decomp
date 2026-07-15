#include <globaldefs.h>

struct StructA90_0223aff8 { unsigned char pad[0xa90]; unsigned char fieldA90; };
extern struct StructA90_0223aff8* data_ov031_02290d20;

// USA: func_ov031_0223aff8
ARM void SetFieldA90_0223aff8(void) {
	data_ov031_02290d20->fieldA90 = 0xc;
}
