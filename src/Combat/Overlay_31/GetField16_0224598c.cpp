#include <globaldefs.h>

extern int data_ov031_02291f24;

// USA: func_ov031_0224598c
ARM int GetField16_0224598c(void) {
	return *(int*)((char*)&data_ov031_02291f24 + 0x10);
}
