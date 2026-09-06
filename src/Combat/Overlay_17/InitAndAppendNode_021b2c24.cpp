#include <globaldefs.h>

struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_ov017_021b2c4c(void* a);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b2c24  (semantic: InitAndAppendNode_021b2c24)
extern "C" ARM void func_ov017_021b2c24(char* p) {
	func_ov017_021b2c4c(*(void**)(p + 0x3738));
	char* base = p + 0x3000;
	void* list = *(void**)(base + 0x6fc);
	void* node = *(void**)(base + 0x738);
	AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
}
