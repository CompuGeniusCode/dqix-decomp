#include <globaldefs.h>

extern "C" ARM int func_ov017_0218b5b0(void);
struct Struct021a942c;
void InitState57_021a942c(Struct021a942c* p);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a93f0  (semantic: CreateAndAppendState57Node_021a93f0)
extern "C" ARM void func_ov017_021a93f0(void* unused, int val0xc, int val0x10) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + 0x6fc);
	Struct021a942c* node = *(Struct021a942c**)(base + 0xb80);
	InitState57_021a942c(node);
	*(int*)((char*)node + 0xc) = val0xc;
	*(int*)((char*)node + 0x10) = val0x10;
	AppendNodeToTail(list, (TailNode020469b4*)node);
}
