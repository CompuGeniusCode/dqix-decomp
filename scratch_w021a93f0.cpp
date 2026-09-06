#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;
struct Struct021a942c;
void InitState57_021a942c(Struct021a942c* p);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" ARM int func_ov017_0218b5b0(void);

// USA: func_ov017_021a93f0
ARM void InitAndAppendState57_021a93f0(void* unused, int val1, int val2) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	void* list = *(void**)(base + 0x6fc);
	Struct021a942c* node = *(Struct021a942c**)(base + 0xb80);
	InitState57_021a942c(node);
	*(int*)((char*)node + 0xc) = val1;
	*(int*)((char*)node + 0x10) = val2;
	AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
}
