#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void* func_ov031_022133f8(unsigned int flags);

// USA: func_ov031_0221314c
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0221314c(unsigned char* name, void* src, int mode) {
	unsigned char* obj = (unsigned char*)func_ov031_022133f8(0x10);

	obj[0xd0c] = (obj[0xd0c] & ~0xf) | 1;
	VectorizedMemset(obj, 0, 0xf0);

	int i = 0;
	do {
		unsigned char c = name[i];
		if (c == 0) break;
		unsigned char* p = obj + i;
		i++;
		p[0x40] = c;
	} while (i < 0x20);

	if (src == 0 || mode == 0) {
		obj[0xe6] = obj[0xe6] & ~3;
		return;
	}

	int size;
	if (mode == 1) {
		size = 5;
	} else if (mode == 2) {
		size = 0xd;
	} else {
		size = 0x10;
	}
	VectorizedInvertedMemcpy(src, obj + 0x80, size);
	unsigned int t = (unsigned char)mode;
	t = t & 3;
	obj[0xe6] = (obj[0xe6] & ~3) | t;
}
