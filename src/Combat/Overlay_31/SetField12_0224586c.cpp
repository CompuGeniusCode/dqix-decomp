#include <globaldefs.h>

extern int data_ov031_02291f24;

// USA: func_ov031_0224586c
ARM void SetField12_0224586c(int v) {
	*(int*)((char*)&data_ov031_02291f24 + 0xc) = v;
}
