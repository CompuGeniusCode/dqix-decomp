#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern "C" ARM int func_ov017_0218b5b0(void);
void InitByteHeader_021c1acc(unsigned char* self);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021c1a98
ARM void InitAndAppendNode_021c1a98(void* unused, void* value) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	void* list = *(void**)(base + 0x6fc);
	unsigned char* node = *(unsigned char**)(base + 0xb78);
	InitByteHeader_021c1acc(node);
	*(void**)(node + 0xc) = value;
	AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
}
