#include <globaldefs.h>

struct Ctx0220a594 {
	unsigned char pad0[0x456];
	unsigned char flag456;
	unsigned char pad1[0x824 - 0x456 - 1];
	void* field824;
	int field828;
	int field82c;
};
struct Session0220a594 { unsigned char pad[0xc]; Ctx0220a594* ctx; };

ARM int CopyStreamedData_02209840(void* dst, int remaining, void* session);
extern "C" void func_ov031_022098d8(Ctx0220a594* ctx, void* p);
extern "C" int func_ov031_02209b58(Session0220a594* session);
extern void* data_ov031_0224c9c0;

// USA: func_ov031_0220a594
extern "C" ARM void* func_ov031_0220a594(int* out, Session0220a594* session) {
	Ctx0220a594* ctx = session->ctx;
	if (ctx->field824 != NULL && ctx->flag456 == 0) {
		int consumed = ctx->field82c;
		int total = ctx->field828;
		int r = CopyStreamedData_02209840((char*)ctx->field824 + consumed, total - consumed, session);
		if (r != 0) {
			void (*cb)(void*) = *(void (**)(void*))&data_ov031_0224c9c0;
			cb(ctx->field824);
			ctx->field824 = NULL;
			*out = 0;
			return NULL;
		}
		func_ov031_022098d8(ctx, ctx->field824);
		if (ctx->flag456 == 0) {
			ctx->field824 = NULL;
		}
	}
	if (ctx->field824 == NULL) {
		while (1) {
			int st = func_ov031_02209b58(session);
			if (st == 9) {
				*out = 0;
				return NULL;
			}
			if (ctx->field824 != NULL) break;
		}
	}
	*out = ctx->field828 - ctx->field82c;
	return (char*)ctx->field824 + ctx->field82c;
}
