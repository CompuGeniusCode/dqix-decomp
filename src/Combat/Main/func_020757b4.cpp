#include <globaldefs.h>
#include "std_library_functions.h"

// KEEP-NAME: the ROM symbol is the mangled C++ name, not a func_ tag.
// USA: func_020757b4

// "<LG>" -- the placeholder this replaces.
extern char data_020f0dc2[];
// One two-letter code per system language: ja, en, fr, de, it, es.
extern char* data_020f0da0[];

char* FindSubstring(char* haystack, char* needle);
int StringLength(const char* s);

// Copies `src` into `dst`, then replaces every "<LG>" with the language's code, shifting the
// rest of the string to fit when the code and the tag are different lengths.
char* StringReplaceLanguageTag(const char* src, char* dst, int language) {
    if (src == 0 || dst == 0) {
        return dst;
    }

    char* const tag = data_020f0dc2;
    strcpy(dst, src);
    char* at = FindSubstring(dst, tag);
    char* code = data_020f0da0[language];
    int codeLength = StringLength(code);
    int shift = StringLength(code) - StringLength(tag);

    while (at != 0) {
        if (shift > 0) {
            memmove(at + shift, at, StringLength(at) + 1);
        } else if (shift < 0) {
            memmove(at, at - shift, shift + StringLength(at) + 1);
        }
        memmove(at, code, codeLength);
        at = FindSubstring(dst, tag);
    }
    return dst;
}
