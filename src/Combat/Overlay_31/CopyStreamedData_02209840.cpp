#include <globaldefs.h>
#include "System/Memory.h"

int WaitOrCycle_02203500(unsigned int* out, void* obj);
extern "C" void func_ov031_022035e0(int count, void* obj);

// USA: func_ov031_02209840
ARM int CopyStreamedData_02209840(void* dst, int remaining, void* obj) {
	unsigned int count;
	do {
		int src = WaitOrCycle_02203500(&count, obj);
		if (count == 0) {
			return -1;
		}
		if (count > remaining) {
			count = remaining;
		}
		VectorizedInvertedMemcpy((const void*)src, dst, count);
		func_ov031_022035e0(count, obj);
		remaining -= count;
		dst = (char*)dst + count;
	} while (remaining > 0);

	return 0;
}
