#include <globaldefs.h>

struct Entry020426bc {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

extern "C" struct Entry020426bc* FindFontCharEntry(int key, int tableIdx);
extern "C" int FindFontCharIndex(int key, int tableIdx);

// The inverse of DecodeFontCharCodesToText: matches each character of the text against the byte sequences in
// font `fontIndex`'s table, writes that entry's index as one byte, and returns the count. A space
// becomes 0xff (the only entry containing one is index 0, "< >"), anything unmatched becomes 0,
// and index 0 is unreachable since only idx > 0 overrides the default. UpdateFollowingCompletion
// encodes the name at combatant+0x134 with fontIndex 1 into clearedBy_, as that field's header
// comment already says; asciiName and the inline guess in the .cpp have the direction backwards.
extern "C" ARM int EncodeTextToFontCharCodes(char* str, unsigned char* out, int id) {
    if (out == 0) return 0;
    if (str == 0) {
        if (out != 0) *out = 0;
        return 0;
    }
    int count = 0;
    for (;;) {
        signed char c = *str;
        if (c == 0) {
            *out = 0;
            break;
        }
        int step = 1;
        int code = 0;
        struct Entry020426bc* e = FindFontCharEntry((int)str, id);
        if (e != 0) {
            step = e->field5;
        }
        if (c == 0x20) code = 0xff;
        int idx = FindFontCharIndex((int)str, id);
        if (idx > 0) code = idx & 0xff;
        *out++ = (unsigned char)code;
        str += step;
        count++;
    }
    return count;
}
