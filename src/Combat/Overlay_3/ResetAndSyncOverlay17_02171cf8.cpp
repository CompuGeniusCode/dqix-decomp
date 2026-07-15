#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0();
extern "C" void func_ov017_021b1e24(void* a, void* b);

struct S02171cf8 {
	unsigned char flag0;
	char pad1[0x730 - 0x1];
	unsigned char flag730;
	unsigned char flag731;
	unsigned char flag732;
	unsigned char flag733;
};

// USA: func_ov003_02171cf8
ARM void ResetAndSyncOverlay17_02171cf8(struct S02171cf8* obj) {
	char* base = func_ov017_0218b5b0();
	char* p = *(char**)(base + 0x3b48);
	char* q = *(char**)(base + 0x36fc);
	func_ov017_021b1e24(p, q);
	if (*(int*)(base + 0x4494) != 0) return;
	if (((unsigned char*)p)[0x28] != 0) {
		obj->flag730 &= ~0x2;
		obj->flag733 = 1;
	}
	base = func_ov017_0218b5b0();
	*(int*)(base + 0x4494) = 1;
	obj->flag0 = 0;
	obj->flag731 = 2;
	obj->flag732 = 3;
}
