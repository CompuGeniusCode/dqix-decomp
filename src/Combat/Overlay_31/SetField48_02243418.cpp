#include <globaldefs.h>

extern int data_ov031_02291e04;

// USA: func_ov031_02243418
ARM void SetField48_02243418(void) {
	*(int*)((char*)&data_ov031_02291e04 + 0x30) = 1;
}
