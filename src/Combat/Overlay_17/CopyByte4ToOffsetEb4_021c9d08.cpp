#include <globaldefs.h>

extern "C" void* func_ov017_021b8468(void*);

// USA: func_ov017_021c9d08
ARM void CopyByte4ToOffsetEb4_021c9d08(void* unused0, void* src, void* unused2, void* obj) {
	void* dst = func_ov017_021b8468(*(void**)((char*)obj + 0x3718));
	if (dst) {
		*((unsigned char*)dst + 0xeb4) = *((unsigned char*)src + 0x4);
	}
}
