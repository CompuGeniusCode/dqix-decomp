#include <globaldefs.h>

extern int data_ov031_02291e04;
extern int data_ov031_02291e68;
void SetField10PairAndFlag_022115d8(void* obj, int value);

// USA: func_ov031_0224342c  (semantic: SetGlobalField10AndPairFlag_0224342c)
extern "C" ARM void func_ov031_0224342c(int value) {
	*(int*)((char*)&data_ov031_02291e04 + 0x10) = value;
	SetField10PairAndFlag_022115d8(&data_ov031_02291e68, value);
}
