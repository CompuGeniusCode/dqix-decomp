#include <globaldefs.h>

extern "C" void func_020c8074(void*);
struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8*);

extern struct RefNode020c80f8 data_ov031_02290f8c;
extern int data_ov031_02290f88;

// USA: func_ov031_0223fa60
ARM int AcquireOnceFlag_0223fa60(void) {
	func_020c8074(&data_ov031_02290f8c);
	int wasZero = (data_ov031_02290f88 == 0);
	if (wasZero) {
		data_ov031_02290f88 = 1;
	}
	ReleaseNodeRef020c80f8(&data_ov031_02290f8c);
	return wasZero;
}
