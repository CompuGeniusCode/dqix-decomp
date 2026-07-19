#include <globaldefs.h>

struct Struct0217ef24;
void InitStruct_0217ef24(struct Struct0217ef24* p);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_0218d77c  (semantic: SetNodeField8AndAppend_0218d77c)
extern "C" ARM void func_ov017_0218d77c(char* self, int value) {
	InitStruct_0217ef24(*(struct Struct0217ef24**)(self + 0x3b40));
	*(int*)((char*)(*(void**)(self + 0x3b40)) + 0x8) = value;
	AppendNodeToTail(*(struct TailList020469b4**)(self + 0x36fc), *(struct TailNode020469b4**)(self + 0x3b40));
}
