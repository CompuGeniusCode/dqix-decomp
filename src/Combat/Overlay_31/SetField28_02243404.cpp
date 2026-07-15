#include <globaldefs.h>

extern int data_ov031_02291e04;

// USA: func_ov031_02243404
ARM void SetField28_02243404(void) {
	*(int*)((char*)&data_ov031_02291e04 + 0x1c) = 1;
}
