#include <globaldefs.h>
#include "System/Memory.h"

struct PtrHolder022364c0 {
	unsigned char* field0;
};

extern struct PtrHolder022364c0 data_ov031_02290cfc;

extern "C" void func_020ca390(int, void*, int);
extern "C" void func_ov031_0221bfe8(void*);
extern "C" void* func_ov031_0221b8e4(void*);
extern "C" void func_ov031_02236570(int);

// USA: func_ov031_022364c0
ARM void InitAndDispatchFour_022364c0(void) {
	func_020ca390(0, data_ov031_02290cfc.field0, 0x400);

	int i = 0;
	do {
		unsigned char* p = data_ov031_02290cfc.field0 + (i << 8);
		p[0xe7] = 0xff;
		i++;
	} while (i < 3);

	int buf[5];
	func_ov031_0221bfe8(buf);
	void* handle = func_ov031_0221b8e4(buf);

	int off = 0;
	int j = 0;
	do {
		VectorizedInvertedMemcpy(handle, data_ov031_02290cfc.field0 + off + 0xf0, 0xe);
		j++;
		off += 0x100;
	} while (j < 2);

	int k = 0;
	do {
		func_ov031_02236570(k);
		k++;
	} while (k < 4);
}
