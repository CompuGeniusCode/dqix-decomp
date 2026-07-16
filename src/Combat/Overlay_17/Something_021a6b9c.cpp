#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void Init021a6be4(unsigned char* self);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021a6b9c
ARM void Something_021a6b9c(int unused0, unsigned char byteVal) {
    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    unsigned char* p2 = *(unsigned char**)(base + 0x3000 + 0x6fc);
    unsigned char* p1 = *(unsigned char**)(base + 0x3000 + 0xb90);
    Init021a6be4(p1);
    p1[0x10] = byteVal;
    AppendNodeToTail((struct TailList020469b4*)p2, (struct TailNode020469b4*)p1);
    *(unsigned short*)(base + 0x4400 + 0xae) = 0;
    *(unsigned short*)(base + 0x4400 + 0xb0) = 0;
}
