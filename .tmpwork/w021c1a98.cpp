#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void _Z23InitByteHeader_021c1accPh(unsigned char* p);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021c1a98
ARM void InitAndAppendNode_021c1a98(void* unused, int val) {
    char* base = (char*)(long)func_ov017_0218b5b0() + 0x3000;
    struct TailList020469b4* list = *(struct TailList020469b4**)(base + 0x6fc);
    char* node = *(char**)(base + 0xb78);
    _Z23InitByteHeader_021c1accPh((unsigned char*)node);
    *(int*)(node + 0xc) = val;
    AppendNodeToTail(list, (struct TailNode020469b4*)node);
}
