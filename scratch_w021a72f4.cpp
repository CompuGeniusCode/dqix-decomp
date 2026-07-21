#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern "C" ARM int func_ov017_0218b5b0(void);
void InitObj_021a7328(char* obj);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021a72f4
ARM void InitAndAppendNode_021a72f4(void* unused, void* value) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	void* list = *(void**)(base + 0x6fc);
	char* node = *(char**)(base + 0xb94);
	InitObj_021a7328(node);
	*(void**)(node + 0xc) = value;
	AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
}
