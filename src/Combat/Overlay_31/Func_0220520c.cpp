#include <globaldefs.h>

struct InitData020c7de4;
void InitStruct020c7de4(InitData020c7de4*, int, int);
int Func_022051a8(void*, void*);
extern "C" void func_020c7ea0(void*, int*, int);

// USA: func_ov031_0220520c
ARM int Func_0220520c(void* a, void* b) {
	int result;
	int scratch;
	char buf[0x20];
	if (*((signed char*)b + 0xd) == 1) {
		InitStruct020c7de4((InitData020c7de4*)buf, (int)&scratch, 1);
		*(void**)((char*)b + 8) = buf;
		Func_022051a8(a, b);
		func_020c7ea0(buf, &result, 1);
	} else {
		*(void**)((char*)b + 8) = NULL;
		result = Func_022051a8(a, b);
	}
	return result;
}
