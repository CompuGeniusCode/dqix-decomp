#include <globaldefs.h>

extern "C" void func_ov031_0220b18c(void*, void*, int);
extern "C" void func_ov031_0220b8f4(void*, void*, int);
extern int data_ov031_022498e4;

// USA: func_ov031_0220b9ac
ARM void FinalizeSha1Digest_0220b9ac(void* ctx, void* out) {
	func_ov031_0220b18c(out, (char*)ctx + 0x14, 8);
	unsigned int lenBits = *(unsigned int*)((char*)ctx + 0x18);
	int rem = (lenBits >> 3) & 0x3f;
	int padLen = (rem < 0x38) ? (0x38 - rem) : (0x78 - rem);
	func_ov031_0220b8f4(ctx, &data_ov031_022498e4, padLen);
	func_ov031_0220b8f4(ctx, out, 8);
	func_ov031_0220b18c(out, ctx, 0x14);
}
