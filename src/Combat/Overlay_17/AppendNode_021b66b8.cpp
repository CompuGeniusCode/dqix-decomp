#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern "C" void func_ov017_021b6790(void* node);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b66b8
ARM void AppendNode_021b66b8(char* obj) {
	func_ov017_021b6790(*(void**)(obj + 0x3000 + 0xb00));
	AppendNodeToTail((struct TailList020469b4*)*(void**)(obj + 0x3000 + 0x6fc),
	                 (struct TailNode020469b4*)*(void**)(obj + 0x3000 + 0xb00));
	((unsigned char*)(*(void**)(obj + 0x3000 + 0xb00)))[0x1f] = 1;
}
