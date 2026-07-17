#include <globaldefs.h>

extern "C" int func_020c7e0c(void*, void*, int);
void CallGlobalWithArg_02205174(int);

// USA: func_ov031_022051a8
ARM int Func_022051a8(void* data, void* obj) {
	int flag = obj == NULL || (*((signed char*)obj + 0xd) & 1);
	int result = func_020c7e0c(data, obj, flag);
	if (result == 0) {
		CallGlobalWithArg_02205174((int)obj);
	}
	return result != 0 ? 0 : -0x2a;
}
