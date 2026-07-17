#include <globaldefs.h>

extern void* data_ov031_0224e588;

extern "C" void func_ov031_0221038c(int state);
extern "C" void* func_020c8074(void* node);
extern "C" void func_ov031_02207428(int a, int b);
struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8* node);

struct Ctx02210250 {
	char pad[0x1b8];
	int field1b8;
	char pad2[0x1bc - 0x1bc];
};

// USA: func_ov031_02210250
ARM int HandleState2AndRelease_02210250(void) {
	if (data_ov031_0224e588 == NULL) {
		return 1;
	}
	func_ov031_0221038c(2);
	if (((Ctx02210250*)data_ov031_0224e588)->field1b8 >= 0) {
		func_020c8074((char*)data_ov031_0224e588 + 0x1bc);
		volatile Ctx02210250* ctx = (volatile Ctx02210250*)data_ov031_0224e588;
		if (ctx->field1b8 >= 0) {
			func_ov031_02207428(ctx->field1b8, 2);
		}
		ReleaseNodeRef020c80f8((struct RefNode020c80f8*)((char*)data_ov031_0224e588 + 0x1bc));
	}
	return 1;
}
