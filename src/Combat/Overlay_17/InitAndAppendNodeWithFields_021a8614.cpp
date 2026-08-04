#include <globaldefs.h>

extern "C" ARM int func_ov017_0218b5b0(void);
ARM void InitObj_021a8670(char* obj);
ARM void SetBoolFieldAt20_021a932c(void* obj, int val);
struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021a8614  (semantic: InitAndAppendNodeWithFields_021a8614)
extern "C" ARM void func_ov017_021a8614(void* unused, int val, unsigned char b0, unsigned char b1, int b2, int b3) {
	char* base = (char*)(int)func_ov017_0218b5b0() + 0x3000;
	struct TailList020469b4* list = *(struct TailList020469b4**)(base + 0x6fc);
	char* node = *(char**)(base + 0xb7c);
	InitObj_021a8670(node);
	SetBoolFieldAt20_021a932c(node, val);
	node[0x18] = b0;
	node[0x19] = b1;
	node[0x1a] = b2;
	node[0x1b] = b3;
	AppendNodeToTail(list, (struct TailNode020469b4*)node);
}
