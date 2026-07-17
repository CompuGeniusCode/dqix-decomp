#include <globaldefs.h>

struct Inner_0223a47c { unsigned char pad[0x40]; int field40; };
struct Outer_0223a47c { unsigned char pad[4]; struct Inner_0223a47c* inner; };
extern struct Outer_0223a47c data_ov031_02290d18;
extern "C" void func_020c9be0(void);
extern "C" void func_ov031_02239368(int);
extern "C" int func_020d503c(int);
void SetTagFromFlag2_02239b98(short* p);

// USA: func_ov031_0223a47c
ARM int RunTagPairAndDispatch_0223a47c(void) {
	if (data_ov031_02290d18.inner->field40 != 1) {
		func_020c9be0();
	}
	func_ov031_02239368(3);
	if (func_020d503c((int)SetTagFromFlag2_02239b98) == 2) {
		return 1;
	}
	func_ov031_02239368(9);
	return 0;
}
