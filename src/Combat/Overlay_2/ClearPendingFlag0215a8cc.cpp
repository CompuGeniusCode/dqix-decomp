#include <globaldefs.h>

extern "C" void func_ov002_0215a920(void*);
extern "C" int func_ov017_0218b5b0(void);

// USA: func_ov002_0215a8cc
ARM int ClearPendingFlag0215a8cc(char* p) {
    if (*(unsigned char*)(p + 0x2000 + 0x53c) == 0) return 0;
    unsigned int val1 = *(unsigned int*)(p + 0x2000 + 0x540);
    *(short*)(p + 0x1b00 + 0xe0) = (short)val1;
    void* blk = (void*)(p + 0x13c + 0x2400);
    unsigned int val2 = *(unsigned int*)(p + 0x2000 + 0x544);
    *(short*)(p + 0x1b00 + 0xfe) = (short)val2;
    func_ov002_0215a920(blk);
    char* other = (char*)func_ov017_0218b5b0();
    void* obj2 = *(void**)(other + 0x3000 + 0x71c);
    func_ov002_0215a920((char*)obj2 + 0x24);
    return 1;
}
