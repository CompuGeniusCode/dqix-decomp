#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int func_ov031_0221b158(void* p);
extern "C" void func_ov031_02236570(int v);

struct Base02236174 { void* field0; };
extern Base02236174 data_ov031_02290cfc;

// USA: func_ov031_02236174  (semantic: CopyHeaderAndProcess_02236174)
extern "C" ARM void func_ov031_02236174(void) {
	unsigned char* base = (unsigned char*)data_ov031_02290cfc.field0;
	unsigned char* src = base + 0x400;
	unsigned char f4 = src[0xf4];
	unsigned char* dst = base + (f4 << 8);

	int n = 0x78;
	unsigned char* d = dst;
	unsigned char* s = src;
	do {
		unsigned char a = s[0];
		unsigned char b = s[1];
		s += 2;
		d[0] = a;
		d[1] = b;
		d += 2;
	} while (--n);

	int d0;
	if (src[0xf5] != 0) {
		VectorizedMemset(dst + 0xc0, 0, 4);
		VectorizedMemset(dst + 0xc4, 0, 4);
		d0 = 0;
	} else {
		VectorizedInvertedMemcpy(src + 0xc0, dst + 0xc0, 4);
		VectorizedInvertedMemcpy(src + 0xc4, dst + 0xc4, 4);
		d0 = func_ov031_0221b158(src + 0xf0);
	}
	dst[0xd0] = d0;

	if (src[0xf6] != 0) {
		VectorizedMemset(dst + 0xc8, 0, 8);
	} else {
		VectorizedInvertedMemcpy(src + 0xc8, dst + 0xc8, 8);
	}

	func_ov031_02236570(src[0xf4]);
}
