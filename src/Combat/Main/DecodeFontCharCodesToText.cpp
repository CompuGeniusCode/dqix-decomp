#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_020425b4(int idx, int tableIdx);
extern unsigned char data_020e7a50;

// Expands a string of one-byte character codes into the text the font actually draws. Each code
// indexes font `fontIndex`'s character table; an entry is a pointer to the character's bytes plus a
// six-bit length, so one code can expand to several, and an unknown code falls back to the space at
// data_020e7a50+8. func_02042944 registers data_0210782c[0] and [1] from data/pack_lv5/fi_s7.bin
// and fi_me.bin; "me" adds "<capslock>", "<shift>" and "<back>", so it is presumably the keyboard's.
// The pair table func_020425e4 reads is kerning: all 22 s7 pairs, like F+'.' and L+T, adjust by -1.
extern "C" ARM void DecodeFontCharCodesToText(unsigned char* src, char* dst, int n) {
    if (!dst) return;
    if (!src) {
        if (dst) *dst = 0;
        return;
    }
    unsigned char b9;
    unsigned char b8 = *((unsigned char*)&data_020e7a50 + 8);
    b9 = *((unsigned char*)&data_020e7a50 + 9);
    unsigned char local[2];
    for (;;) {
        unsigned char ch = *src;
        if (ch == 0) {
            *dst = 0;
            return;
        }
        local[0] = b8;
        local[1] = b9;
        void* copySrc = local;
        int size = 1;
        void* entry = func_020425b4(ch, n);
        if (entry != NULL) {
            copySrc = *(void**)entry;
            signed char raw = *((signed char*)entry + 5);
            size = (raw << 26) >> 26;
        }
        memcpy(dst, copySrc, size);
        src++;
        dst += size;
    }
}
