#include <globaldefs.h>

extern void* SetupBuffer_02223478(const unsigned char*);
extern "C" void* func_ov031_0223b61c(void*, int*, int);
extern "C" void func_ov031_0223b710(void*);
extern "C" void func_020ca4b4(void*, void*, int);
extern void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
extern void* data_ov031_0224b3c0;
extern void* data_ov031_02250bf4;
extern "C" void func_ov031_02223a24(void*);

// USA: func_ov031_02223998
ARM void SetupAndCopy_02223998(int idx) {
	const unsigned char* name = (const unsigned char*)((void**)&data_ov031_0224b3c0)[idx];
	void* buf = SetupBuffer_02223478(name);
	void* p = func_ov031_0223b61c(buf, 0, 4);
	func_020ca4b4(p, data_ov031_02250bf4, 0xc0);
	func_ov031_0223b710(p);
	CallWithZeroExtra_0223e218((void*)1, (void*)func_ov031_02223a24, 0, 0x78);
}
