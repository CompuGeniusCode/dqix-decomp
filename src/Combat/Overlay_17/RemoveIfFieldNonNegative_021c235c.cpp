#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int a, int b);

// USA: func_ov017_021c235c
ARM void RemoveIfFieldNonNegative_021c235c(char* self) {
	int list = GetData02104304Field4();
	short v = *(short*)(self + 8);
	if (v > -1) func_020301c8(list, v);
}
