#include <globaldefs.h>

struct S0216a85c {
	unsigned short a0;
	unsigned short a2;
	unsigned char a4;
	unsigned char pad5[3];
	int a8;
	int ac;
	int a10;
	int a14;
};

// USA: func_ov003_0216a85c
ARM void ClearFields_0216a85c(S0216a85c* obj) {
	obj->a0 = 0;
	obj->a2 = 0;
	obj->a4 = 0;
	obj->a14 = 0;
	obj->a10 = 0;
	obj->ac = 0;
	obj->a8 = 0;
}
