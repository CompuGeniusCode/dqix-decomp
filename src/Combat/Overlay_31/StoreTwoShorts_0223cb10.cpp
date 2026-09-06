#include <globaldefs.h>

struct TwoShorts0223cb10 {
	unsigned short a;
	unsigned short b;
};

// USA: func_ov031_0223cb10  (semantic: StoreTwoShorts_0223cb10)
extern "C" ARM void func_ov031_0223cb10(unsigned short a, unsigned short b, TwoShorts0223cb10* out) {
	out->a = a;
	out->b = b;
}
