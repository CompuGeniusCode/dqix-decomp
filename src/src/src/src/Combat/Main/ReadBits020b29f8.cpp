#include <globaldefs.h>

struct BitReader020b29f8 {
    unsigned char* data;   /* 0x0 */
    signed char count;     /* 0x4 */
    unsigned char buf;     /* 0x5 */
};

// USA: func_020b29f8
ARM int ReadBits020b29f8(BitReader020b29f8* r, int n) {
    int count = r->count;
    unsigned int buf = r->buf;
    int result;
    if (count < n) {
        int need = n - count;
        unsigned char* p = r->data;
        r->data = p + 1;
        unsigned char newByte = *p;
        r->buf = newByte;
        r->count = 8;
        result = ReadBits020b29f8(r, need) | (buf << need);
    } else {
        r->count = count - n;
        result = buf >> (count - n);
    }
    return result & (0xff >> (8 - n));
}
