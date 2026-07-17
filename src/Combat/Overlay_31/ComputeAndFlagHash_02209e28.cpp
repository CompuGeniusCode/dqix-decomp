#include <globaldefs.h>
#include "System/Interrupts.h"

void InitSha1State_0220b8a0(void* ctx);
extern "C" void func_ov031_0220b8f4(void* ctx, const void* data, unsigned int len);
void FinalizeSha1Digest_0220b9ac(void* ctx, const void* data);
extern unsigned char data_ov031_0224e528[0x14];
extern unsigned char data_ov031_0224e3b0;

// USA: func_ov031_02209e28
ARM void ComputeAndFlagHash_02209e28(void* buf, unsigned int len) {
	unsigned char ctx[0x5c];
	InitSha1State_0220b8a0(ctx);
	int oldState = DisableIRQInterrupts();
	func_ov031_0220b8f4(ctx, data_ov031_0224e528, 0x14);
	func_ov031_0220b8f4(ctx, buf, len);
	FinalizeSha1Digest_0220b9ac(ctx, data_ov031_0224e528);
	SetIRQInterruptState(oldState);
	data_ov031_0224e3b0 = 1;
}
