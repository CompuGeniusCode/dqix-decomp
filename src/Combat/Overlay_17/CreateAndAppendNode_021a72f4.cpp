#include <globaldefs.h>

extern "C" ARM int func_ov017_0218b5b0(void);
void InitObj_021a7328(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a72f4  (semantic: CreateAndAppendNode_021a72f4)
extern "C" ARM void func_ov017_021a72f4(void* unused, int val) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + 0x6fc);
	char* node = *(char**)(base + 0xb94);
	InitObj_021a7328(node);
	*(int*)(node + 0xc) = val;
	AppendNodeToTail(list, (TailNode020469b4*)node);
}
