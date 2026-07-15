#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);
extern "C" void func_020c9be0(void);

// USA: func_ov031_0223a040
ARM void RunTagIfShort2Is8_0223a040(short* p) {
	if (*(unsigned short*)((char*)p + 2) == 8) {
		func_ov031_02239368(9);
		func_020c9be0();
	}
}
