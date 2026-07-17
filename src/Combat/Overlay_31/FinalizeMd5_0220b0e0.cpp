#include <globaldefs.h>

void CopyForward_0220ab94(void* dst, const void* src, unsigned int length);
extern "C" void func_ov031_0220b028(void* ctx, const void* data, unsigned int len);
extern unsigned char data_ov031_022497a4[];

// USA: func_ov031_0220b0e0
ARM void FinalizeMd5_0220b0e0(void* ctx, void* out) {
	CopyForward_0220ab94(out, (char*)ctx + 0x10, 8);
	int bytePos = (*(unsigned int*)((char*)ctx + 0x10) >> 3) & 0x3f;
	int padLen = (bytePos < 0x38) ? (0x38 - bytePos) : (0x78 - bytePos);
	func_ov031_0220b028(ctx, data_ov031_022497a4, padLen);
	func_ov031_0220b028(ctx, out, 8);
	CopyForward_0220ab94(out, ctx, 0x10);
}
