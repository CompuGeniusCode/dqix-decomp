#include <globaldefs.h>

// USA: func_ov017_02191ba0
ARM void SetIndexedFieldsIfValid_02191ba0(char* base, int index, unsigned short val) {
	int valid = index >= 0 && index <= 3;
	if (!valid) {
		return;
	}
	char* p = base + index * 4;
	*(unsigned short*)(p + 0x4400 + 0x9e) = val;
	*(unsigned char*)(p + 0x4000 + 0x49c) = 1;
}
