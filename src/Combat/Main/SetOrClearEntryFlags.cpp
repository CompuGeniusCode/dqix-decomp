#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_020b6ebc
ARM void SetOrClearEntryFlags(unsigned char* obj, int set, int mask) {
    unsigned int count = obj[0x18];
    unsigned char* base = (obj != NULL && *(int*)(obj + 8) != 0)
                          ? obj + *(int*)(obj + 8) : NULL;
    unsigned int i = 0;
    if (i < count) {
        unsigned char* p;
        do {
            unsigned char* q;
            p = base + 4;
            if (base != NULL) {
                unsigned char* e;
                if (p != NULL && i < base[5]) {
                    unsigned short off = *(unsigned short*)(base + 0xa);
                    unsigned short stride = *(unsigned short*)(p + off);
                    e = p + off + 4 + stride * i;
                } else {
                    e = NULL;
                }
                if (e != NULL) {
                    q = base + *(int*)e;
                    goto have_q;
                }
            }
            q = NULL;
        have_q:
            {
                unsigned short* pv = (unsigned short*)(q + 0x1e);
                if (set != 0) *pv |= mask;
                else *pv &= ~mask;
            }
            i++;
        } while (i < count);
    }
}
