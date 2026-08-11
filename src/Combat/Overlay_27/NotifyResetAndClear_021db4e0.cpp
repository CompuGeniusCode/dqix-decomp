#include <globaldefs.h>

struct FieldHolder_021db4e0 {
	unsigned char pad0[8];
	unsigned char* ptr;
	unsigned char* ptrC;
};

extern FieldHolder_021db4e0 data_ov027_021e33e0;

typedef void (*NotifyFn021db4e0)(int, int);

// USA: func_ov027_021db4e0  (semantic: NotifyResetAndClear_021db4e0)
extern "C" ARM void func_ov027_021db4e0(int a) {
	data_ov027_021e33e0.ptr[0x50d] = 0;
	*(unsigned short*)(data_ov027_021e33e0.ptrC + 0x1300 + 0x16) = 0;
	NotifyFn021db4e0 fn = *(NotifyFn021db4e0*)(data_ov027_021e33e0.ptr + 0x51c);
	if (fn) fn(0x11, a);
}
