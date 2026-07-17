#include <globaldefs.h>

extern "C" void func_ov031_02214520(void);

// USA: func_ov031_02214d38
ARM int UpdateNibble_02214d38(unsigned char *obj) {
	obj[0xd15] = 0;
	unsigned int b = obj[0xd0b];
	unsigned char hi = (unsigned char)(((b << 24) >> 28) + 1);
	unsigned int lo = b & ~0xf0u;
	obj[0xd0b] = (unsigned char)(lo | (((unsigned int)hi << 28) >> 24));
	func_ov031_02214520();
	obj[0xd11] = 1;
	return 3;
}
