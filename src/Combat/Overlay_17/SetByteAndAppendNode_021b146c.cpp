#include <globaldefs.h>

struct Obj021b14a0;
void InitState37_021b14a0(struct Obj021b14a0* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b146c  (semantic: SetByteAndAppendNode_021b146c)
extern "C" ARM void func_ov017_021b146c(void* self, unsigned char param1) {
	InitState37_021b14a0((struct Obj021b14a0*)*(void**)((char*)self + 0x3000 + 0xb44));
	*(unsigned char*)((char*)*(void**)((char*)self + 0x3000 + 0xb44) + 0x49) = param1;
	AppendNodeToTail((struct TailList020469b4*)*(void**)((char*)self + 0x3000 + 0x6fc),
	                 (struct TailNode020469b4*)*(void**)((char*)self + 0x3000 + 0xb44));
}
