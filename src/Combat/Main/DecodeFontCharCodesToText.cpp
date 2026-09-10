#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_020425b4(int idx, int tableIdx);
extern unsigned char data_020e7a50;

// Expands a string of one-byte character codes into the text the font actually draws. Each code
// indexes font `fontIndex`'s character table; an entry is a pointer to the character's bytes plus a
// six-bit length, so one code can expand to several, and an unknown code falls back to the space at
// data_020e7a50+8, whose two bytes are read into spaceByte0 and spaceByte1 although the fallback
// size of 1 means only the first is ever copied. func_02042944 registers data_0210782c[0] and [1]
// from data/pack_lv5/fi_s7.bin
// and fi_me.bin; "me" adds "<capslock>", "<shift>" and "<back>", so it is presumably the keyboard's.
// The pair table func_020425e4 reads is kerning: all 22 s7 pairs, like F+'.' and L+T, adjust by -1.
extern "C" ARM void DecodeFontCharCodesToText(unsigned char* codes, char* text, int fontIndex) {
    if (!text) return;
    if (!codes) {
        if (text) *text = 0;
        return;
    }
    unsigned char spaceByte1;
    unsigned char spaceByte0 = *((unsigned char*)&data_020e7a50 + 8);
    spaceByte1 = *((unsigned char*)&data_020e7a50 + 9);
    unsigned char fallbackChar[2];
    for (;;) {
        unsigned char ch = *codes;
        if (ch == 0) {
            *text = 0;
            return;
        }
        fallbackChar[0] = spaceByte0;
        fallbackChar[1] = spaceByte1;
        void* copySrc = fallbackChar;
        int size = 1;
        void* entry = func_020425b4(ch, fontIndex);
        if (entry != NULL) {
            copySrc = *(void**)entry;
            signed char raw = *((signed char*)entry + 5);
            size = (raw << 26) >> 26;
        }
        memcpy(text, copySrc, size);
        codes++;
        text += size;
    }
}
