#include <globaldefs.h>

extern "C" void func_ov031_02208c14(void* ctx, int unused, int field);
extern "C" void func_ov031_02207b44(void* ctx, int a, int b);
extern "C" void func_ov031_02208f50(void* ctx);
void BuildAndCopyContext_02208ef0(void* ctx);

// USA: func_ov031_0220911c
ARM void RunPostBattleSequence_0220911c(void* ctx) {
	int garbage;
	func_ov031_02208c14(ctx, garbage, *(int*)((char*)ctx + 0x81c));
	BuildAndCopyContext_02208ef0(ctx);
	func_ov031_02207b44(ctx, 0, 0);
	func_ov031_02208f50(ctx);
	*((unsigned char*)ctx + 0x455) = 5;
}
