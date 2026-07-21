#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void _Z16InitObj_021a8670Pc(char* p);
extern "C" void _Z25SetBoolFieldAt20_021a932cPvi(void* p, int v);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021a8614
ARM void InitAndAppendNodeWithFlags_021a8614(void* unused, int val1, unsigned char val2, unsigned char val3, int val4, int val5) {
    char* base = (char*)(long)func_ov017_0218b5b0() + 0x3000;
    struct TailList020469b4* list = *(struct TailList020469b4**)(base + 0x6fc);
    char* node = *(char**)(base + 0xb7c);
    _Z16InitObj_021a8670Pc(node);
    _Z25SetBoolFieldAt20_021a932cPvi(node, val1);
    node[0x18] = val2;
    node[0x19] = val3;
    node[0x1a] = val4;
    node[0x1b] = val5;
    AppendNodeToTail(list, (struct TailNode020469b4*)node);
}
