#include <globaldefs.h>

// USA: func_ov031_02201d58  (semantic: CompareEncodedFields_02201d58)
extern "C" ARM int func_ov031_02201d58(void* r0, unsigned short* r1, void* r2) {
	int result = 0;
	int flag1 = 0;
	int flag3 = 0;
	int flag2 = 0;
	unsigned char type = *(unsigned char*)((char*)r2 + 0x8);
	if (type != 0xa && type != 0xb) flag1 = 1;
	if (flag1) {
		unsigned short v = r1[1];
		unsigned short target = *(unsigned short*)((char*)r2 + 0xa);
		if (target == (unsigned short)((v >> 8) | (v << 8))) flag2 = 1;
	}
	if (flag2) {
		unsigned short v2 = r1[0];
		unsigned short target2 = *(unsigned short*)((char*)r2 + 0x18);
		if (target2 == (unsigned short)((v2 >> 8) | (v2 << 8))) flag3 = 1;
	}
	if (flag3) {
		unsigned short lo = *(unsigned short*)((char*)r0 + 0xe);
		unsigned short hi = *(unsigned short*)((char*)r0 + 0xc);
		unsigned int targetD = *(unsigned int*)((char*)r2 + 0x1c);
		unsigned int combined = ((unsigned int)(unsigned short)((hi >> 8) | (hi << 8)) << 16) | (unsigned short)((lo >> 8) | (lo << 8));
		if (targetD == combined) result = 1;
	}
	return result;
}
