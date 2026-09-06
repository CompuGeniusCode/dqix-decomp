#include <globaldefs.h>

int GetData02104304Field4(void);
int GetField0x124(void* obj);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_0219b624(void* obj);

struct Obj021b2b68 {
	unsigned char pad0[8];
	int f8;
	unsigned char pad1[0x38 - 0xc];
	int f38;
};

// USA: func_ov017_021b2b68
ARM int SomeFunc_021b2b68(Obj021b2b68* p) {
	if (GetField0x124((void*)GetData02104304Field4()) > 0) {
		return p->f8;
	}
	func_ov017_0219b624((void*)func_ov017_0218b5b0());
	p->f38 &= ~4;
	return 3;
}
