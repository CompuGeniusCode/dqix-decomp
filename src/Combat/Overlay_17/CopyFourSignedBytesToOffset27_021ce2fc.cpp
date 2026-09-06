#include <globaldefs.h>

// USA: func_ov017_021ce2fc
ARM void CopyFourSignedBytesToOffset27_021ce2fc(int unused0, unsigned char* src, int unused2, unsigned char* ov) {
	unsigned char* dst = *(unsigned char**)(ov + 0x3000 + 0xb30);
	signed char* s = (signed char*)(src + 4);
	for (int i = 0; i < 4; i++) {
		*(signed char*)(dst + i + 0x1b) = s[i];
	}
}
