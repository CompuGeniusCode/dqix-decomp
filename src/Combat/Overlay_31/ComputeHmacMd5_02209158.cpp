#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_ov031_0220b028(void* ctx, const void* data, unsigned int len);
void InitMd5Ctx_0220afe0(void* ctx);
void FinalizeMd5_0220b0e0(void* ctx, void* out);
extern unsigned char data_ov031_02249754[];
extern unsigned char data_ov031_0224975c[];

// USA: func_ov031_02209158  (semantic: ComputeHmacMd5_02209158)
extern "C" ARM void func_ov031_02209158(void* obj, void* out, int mode) {
	unsigned char pad[0x30];
	void* ctx = (char*)obj + 0x3a4;
	if ((*(unsigned char*)((char*)obj + 0x454) ^ mode) != 0) {
		func_ov031_0220b028(ctx, data_ov031_02249754, 4);
	} else {
		func_ov031_0220b028(ctx, data_ov031_0224975c, 4);
	}
	func_ov031_0220b028(ctx, obj, 0x30);
	VectorizedMemset(pad, 0x36, 0x30);
	func_ov031_0220b028(ctx, pad, 0x30);
	FinalizeMd5_0220b0e0(ctx, out);
	InitMd5Ctx_0220afe0(ctx);
	func_ov031_0220b028(ctx, obj, 0x30);
	VectorizedMemset(pad, 0x5c, 0x30);
	func_ov031_0220b028(ctx, pad, 0x30);
	func_ov031_0220b028(ctx, out, 0x10);
	FinalizeMd5_0220b0e0(ctx, out);
}
