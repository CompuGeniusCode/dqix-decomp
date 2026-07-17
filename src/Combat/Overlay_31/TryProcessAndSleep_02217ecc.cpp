#include <globaldefs.h>

extern "C" void func_020c9b10(void *p);
extern "C" void func_ov031_02209e28(void *p, int n);
extern "C" void* func_020c8074(void *node);
void SleepCurrentContext(unsigned int arg);

struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8 *node);

// USA: func_ov031_02217ecc
ARM int TryProcessAndSleep_02217ecc(char *self) {
	if (*(int*)(self + 0x1000 + 0x130) == 1) {
		func_020c9b10(self + 0x1800 + 0x1d4);
		func_ov031_02209e28(self + 0x1800 + 0x1d4, 0x20);
	}
	func_020c8074(self + 0x1800 + 0x3f8);
	int w = *(int*)(self + 0x1000 + 0xc10);
	if (w == 1) {
		ReleaseNodeRef020c80f8((struct RefNode020c80f8*)(self + 0x1800 + 0x3f8));
		return 0;
	}
	ReleaseNodeRef020c80f8((struct RefNode020c80f8*)(self + 0x1800 + 0x3f8));
	SleepCurrentContext(0xa);
	return 1;
}
