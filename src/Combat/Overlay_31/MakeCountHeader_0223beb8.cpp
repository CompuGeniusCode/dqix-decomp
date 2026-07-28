#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);

struct Hdr0223beb8 { short field0; unsigned char field2; unsigned char field3; };

// USA: func_ov031_0223beb8  (semantic: MakeCountHeader_0223beb8)
extern "C" ARM void* func_ov031_0223beb8(int n) {
	unsigned int size = (n + 1) * 4 + 8;
	Hdr0223beb8* p = (Hdr0223beb8*)func_ov031_0223cf4c(size, 4);
	p->field0 = n + 1;
	p->field2 = 0;
	p->field3 = 0;
	return p;
}
