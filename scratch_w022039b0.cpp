#include <globaldefs.h>

struct Candidate022039b0 { char pad[8]; unsigned char field8; unsigned char field9; };
struct Ctx022039b0 { char pad[0xa4]; Candidate022039b0* candidate; };
struct Global022039b0 { char pad[4]; Ctx022039b0* ctx; };
extern struct Global022039b0 data_02111304;
extern unsigned char data_ov031_0224c980;

extern "C" ARM void func_ov031_02201414(void* a, int b, Candidate022039b0* c);
extern "C" ARM void func_ov031_02201364(void* a, int b, Candidate022039b0* c);
extern "C" ARM int func_ov031_0220a87c(void* a, int b, void* c, int d, Candidate022039b0* e);
extern "C" ARM int func_ov031_022037a8(void* a, int b, void* c, int d, Candidate022039b0* e);

// USA: func_ov031_022039b0
extern "C" ARM int NotifyCandidateHandlers022039b0(void* objA, int flagA, void* objB, int flagB) {
	Ctx022039b0* ctx = data_02111304.ctx;
	Candidate022039b0* c = ctx->candidate;
	if (!c) goto zero;
	int result;
	if (c->field8 == 0xa) {
		if (flagA) func_ov031_02201414(objA, flagA, c);
		if (flagB) func_ov031_02201414(objB, flagB, c);
		result = flagA + flagB;
	} else if (c->field8 == 0xb) {
		if (flagA) func_ov031_02201364(objA, flagA, c);
		if (flagB) func_ov031_02201364(objB, flagB, c);
		result = flagA + flagB;
	} else {
		if (c->field9 != 0)
			result = func_ov031_0220a87c(objA, flagA, objB, flagB, c);
		else
			result = func_ov031_022037a8(objA, flagA, objB, flagB, c);
	}
	if (!data_ov031_0224c980) return result;
zero:
	return 0;
}
