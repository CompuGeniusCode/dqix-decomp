#include <globaldefs.h>
#include "System/Interrupts.h"

int HwDivideRemainder(int numer, int denom);
extern "C" void func_020c9be0(void);

struct Ctx0223bf48 { unsigned short field0; unsigned char field2; unsigned char field3; };

// USA: func_ov031_0223bf48
ARM void PushSlotAndCheckIndex_0223bf48(Ctx0223bf48* ctx, void* val) {
	unsigned int irq = DisableSpecificInterrupts(1);
	int idx = HwDivideRemainder(ctx->field3 + 1, ctx->field0);
	if (idx == ctx->field2) {
		func_020c9be0();
	}
	*(void**)((char*)ctx + ctx->field3 * 4 + 4) = val;
	ctx->field3 = idx;
	EnableSpecificInterrupts(irq);
}
