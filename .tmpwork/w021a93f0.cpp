#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct Struct021a942c;
extern "C" void _Z20InitState57_021a942cP14Struct021a942c(struct Struct021a942c* p);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021a93f0
ARM void InitAndAppendState57_021a93f0(void* unused, int val1, int val2) {
    char* base = (char*)(long)func_ov017_0218b5b0() + 0x3000;
    struct TailList020469b4* list = *(struct TailList020469b4**)(base + 0x6fc);
    struct Struct021a942c* node = *(struct Struct021a942c**)(base + 0xb80);
    _Z20InitState57_021a942cP14Struct021a942c(node);
    *(int*)((char*)node + 0xc) = val1;
    *(int*)((char*)node + 0x10) = val2;
    AppendNodeToTail(list, (struct TailNode020469b4*)node);
}
