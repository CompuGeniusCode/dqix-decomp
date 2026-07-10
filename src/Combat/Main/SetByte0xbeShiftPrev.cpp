#include <globaldefs.h>

extern "C" int func_02033ce8(void* obj, int val);

struct Bytes02033b88 {
    char pad[0xbe];
    unsigned char cur;
    unsigned char prev;
};

// USA: func_02033b88
ARM int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val) {
    p->prev = p->cur;
    p->cur = (unsigned char)val;
    return func_02033ce8(p, val);
}
