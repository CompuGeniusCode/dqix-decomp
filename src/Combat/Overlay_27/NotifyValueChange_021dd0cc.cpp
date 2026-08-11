#include <globaldefs.h>

struct FieldHolder_021dd0cc {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern FieldHolder_021dd0cc data_ov027_021e33e0;

struct NotifyArgs021dd0cc { unsigned short a; unsigned short b; };
typedef void (*NotifyFn021dd0cc)(int, NotifyArgs021dd0cc*);

// USA: func_ov027_021dd0cc  (semantic: NotifyValueChange_021dd0cc)
extern "C" ARM void func_ov027_021dd0cc(int a, int b) {
	if (b == 2 || b == 0) return;
	volatile unsigned short sb;
	volatile unsigned short sa;
	sa = (unsigned short)a;
	unsigned char* p = data_ov027_021e33e0.ptr;
	sb = (unsigned short)b;
	NotifyFn021dd0cc fn = *(NotifyFn021dd0cc*)(p + 0x51c);
	fn(0xff, (NotifyArgs021dd0cc*)&sa);
}
