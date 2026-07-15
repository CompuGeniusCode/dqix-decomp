#include <globaldefs.h>

// USA: func_ov017_021d49ac
struct S021d49ac { int a; int b; int c; int d; };

ARM int OrNonZero_021d49ac(struct S021d49ac s) {
	return s.a != 0 || s.b != 0;
}
