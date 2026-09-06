#include <globaldefs.h>

// USA: func_ov023_021e33a0
ARM void CopyByteFieldToNextAndSet_021e33a0_021e33a0(char* p, signed char v) {
	*(signed char*)(p + 0x4e7) = *(signed char*)(p + 0x400 + 0xe6);
	*(signed char*)(p + 0x4e6) = v;
}
