#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_ov031_022157f8(int a, void *buf);
extern "C" int func_02001aec(void *a, void *b, int n);
extern char data_ov031_02249b3c;

// USA: func_ov031_02215778
#pragma optimize_for_size off
ARM void CopyBufferIfMatch_02215778(int a, void *dst) {
	unsigned int buf[6];
	func_ov031_022157f8(a, buf);
	if (func_02001aec(buf, &data_ov031_02249b3c, 8) == 0) {
		VectorizedInvertedMemcpy(&buf[2], dst, 0xa);
	}
}
