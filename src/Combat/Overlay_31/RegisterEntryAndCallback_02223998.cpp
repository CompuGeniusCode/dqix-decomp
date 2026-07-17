#include <globaldefs.h>

extern int data_ov031_0224b3c0[];
extern int data_ov031_02250bf4;

int SetName_02223478(int);
int LoadFileWithFallback_0223b61c(int, int, int);
extern "C" int func_020ca4b4(int, int, int);
void ForwardArgsAndNotify_0223b710(int);
void InitBuffer_02223a24(void);
extern "C" void* CallWithZeroExtra_0223e218(void*, void*, void*, int);

// USA: func_ov031_02223998
ARM void RegisterEntryAndCallback_02223998(int index) {
	int v = SetName_02223478(data_ov031_0224b3c0[index]);
	int handle = LoadFileWithFallback_0223b61c(v, 0, 4);
	func_020ca4b4(handle, data_ov031_02250bf4, 0xc0);
	ForwardArgsAndNotify_0223b710(handle);
	CallWithZeroExtra_0223e218((void*)1, (void*)InitBuffer_02223a24, NULL, 0x78);
}
