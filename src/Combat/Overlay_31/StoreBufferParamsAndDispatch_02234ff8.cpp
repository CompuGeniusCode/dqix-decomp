#include <globaldefs.h>

extern int data_ov031_02290ce8;
extern void CopyBufferAndNotify_02235034(int a);
extern void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);

// USA: func_ov031_02234ff8  (semantic: StoreBufferParamsAndDispatch_02234ff8)
extern "C" ARM void func_ov031_02234ff8(int a, int b, int c) {
	*(int*)((char*)&data_ov031_02290ce8 + 0x4) = a + (b << 5);
	*(int*)((char*)&data_ov031_02290ce8 + 0x8) = (c << 5) + 0x5000000;
	CallWithZeroExtra_0223e218((void*)1, (void*)CopyBufferAndNotify_02235034, NULL, 0x78);
}
