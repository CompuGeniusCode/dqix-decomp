#include <globaldefs.h>
#include "System/Cache.h"

extern "C" void func_020c5b98(void *p, int a, unsigned int size);
extern "C" void func_ov031_0223e2c0(int a, int b);

extern void* data_ov031_02250bf4;

// USA: func_ov031_02223a24
ARM void InitBuffer_02223a24(int arg0) {
	CleanInvalidateCacheRange(data_ov031_02250bf4, 0xc0);
	func_020c5b98(data_ov031_02250bf4, 0, 0xc0);
	func_ov031_0223e2c0(1, arg0);
}
