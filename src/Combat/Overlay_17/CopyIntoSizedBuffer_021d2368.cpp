#include <globaldefs.h>
#include "std_library_functions.h"

struct SrcHdr021d2368 { unsigned char pad[4]; unsigned short low2 : 2; unsigned short off : 14; };

// USA: func_ov017_021d2368
ARM void CopyIntoSizedBuffer_021d2368(int unused0, unsigned char* srcRaw, int unused2, unsigned char* base) {
	SrcHdr021d2368* src = (SrcHdr021d2368*)srcRaw;
	unsigned char* ptr = *(unsigned char**)(base + 0x3000 + 0xb30);
	if (ptr[2] == 0) return;
	unsigned char* arrBase = *(unsigned char**)(ptr + 0x288);
	if (arrBase == NULL) return;
	unsigned int off = src->off;
	unsigned int len = 0xe;
	if (off + 0xe > 0x2e0) len = 0x2e0 - off;
	if ((int)len < 0) return;
	memcpy(arrBase + off, srcRaw + 6, len);
}
