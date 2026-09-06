#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_0218b5b0(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

struct Obj021b2ad8 {
	unsigned char pad0[8];
	int f8;
	unsigned char pad1[0x38 - 0xc];
	int f38;
};

// USA: func_ov017_021b2ad8
ARM int SomeFunc_021b2ad8(Obj021b2ad8* p) {
	if (*(int*)((char*)func_02012fe4() + 0x424) != 0) {
		return p->f8;
	}
	ClearBitsInField4((unsigned int*)func_ov017_0218b5b0(), 2);
	p->f38 &= ~1;
	return 3;
}
