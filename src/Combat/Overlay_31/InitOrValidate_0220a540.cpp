#include <globaldefs.h>

extern "C" int func_ov031_022032a4(void* self);
void InitSha1State_0220b8a0(void* ctx);
void InitMd5Ctx_0220afe0(void* ctx);
extern "C" void func_ov031_0220a474(void* self);

// USA: func_ov031_0220a540
ARM int InitOrValidate_0220a540(void* self) {
	unsigned char field8 = *((unsigned char*)self + 8);
	void* ctx = *(void**)((char*)self + 0xc);
	if (field8 != 4) {
		if (func_ov031_022032a4(self) != 0) {
			return 1;
		}
	}
	*((unsigned char*)ctx + 0x455) = 0;
	*(int*)((char*)ctx + 0x1d4) = 0;
	*((unsigned char*)ctx + 0x454) = 0;
	InitSha1State_0220b8a0((char*)ctx + 0x2ec);
	InitMd5Ctx_0220afe0((char*)ctx + 0x3a4);
	func_ov031_0220a474(self);
	return 0;
}
