#include <globaldefs.h>
#include "std_library_functions.h"

struct Buffer020294cc {
    unsigned int unused0;
    char text[0x2f];
};

// USA: func_020294cc  (semantic: CopyTruncatedSjisString020294cc)
extern "C" ARM void func_020294cc(struct Buffer020294cc* self, unsigned char* src) {
    int len;
    int extra;
    unsigned char* p;
    unsigned char c;
    int newLen;

    if (src == 0) return;

    len = 0;
    p = src;
    while ((c = *p) != 0) {
        extra = 0;
        if ((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xea)) {
            c = *++p;
            extra++;
            if (c == 0) break;
        }
        newLen = len + (extra + 1);
        p++;
        if ((unsigned int)newLen > 0x2e) break;
        len = newLen;
    }
    memcpy(self->text, src, len);
    self->text[len] = 0;
}
