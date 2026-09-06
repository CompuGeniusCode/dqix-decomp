#include <globaldefs.h>

struct Src_021cc1d8 { unsigned char pad0[4]; unsigned char flagByte; unsigned char pad1[3]; int val; };
struct Tgt_021cc1d8 { unsigned char pad[0xf]; unsigned char outByte; signed char cmpByte; };

// USA: func_ov017_021cc1d8
ARM void CopyByteIfFlagMatches_021cc1d8(int unused0, Src_021cc1d8* src, int unused2, unsigned char* base) {
	Tgt_021cc1d8* tgt = *(Tgt_021cc1d8**)(base + 0x3000 + 0xb2c);
	if (tgt->cmpByte == src->flagByte) {
		tgt->outByte = (unsigned char)src->val;
	}
}
