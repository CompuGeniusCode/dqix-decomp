#include <globaldefs.h>

struct FontCharEntry {
    int bytes;
    char unknown4;
    signed char byteLength : 6;
    signed char unused2 : 2;
    char unknown6[2];
};

extern "C" struct FontCharEntry* FindFontCharEntry(int key, int tableIdx);
extern "C" int FindFontCharIndex(int key, int tableIdx);

// The inverse of DecodeFontCharCodesToText: matches each character of the text against the byte sequences in
// font `fontIndex`'s table, writes that entry's index as one byte, and returns the count. A space
// becomes 0xff (the only entry containing one is index 0, "< >"), anything unmatched becomes 0,
// and index 0 is unreachable since only idx > 0 overrides the default. An entry is eight bytes: the
// pointer at +0 to the character's own bytes and the six-bit byteLength at +5, the pair
// FindFontCharEntry hands to memcmp and the step this loop takes over the text; +4 and +6 are not
// established. UpdateFollowingCompletion encodes the name at combatant+0x134 with fontIndex 1 into
// clearedBy_, as that field's header comment already says; asciiName and the inline guess in the
// .cpp have the direction backwards.
extern "C" ARM int EncodeTextToFontCharCodes(char* str, unsigned char* out, int fontIndex) {
    if (out == 0) return 0;
    if (str == 0) {
        if (out != 0) *out = 0;
        return 0;
    }
    int count = 0;
    for (;;) {
        signed char ch = *str;
        if (ch == 0) {
            *out = 0;
            break;
        }
        int step = 1;
        int code = 0;
        struct FontCharEntry* entry = FindFontCharEntry((int)str, fontIndex);
        if (entry != 0) {
            step = entry->byteLength;
        }
        if (ch == 0x20) code = 0xff;
        int idx = FindFontCharIndex((int)str, fontIndex);
        if (idx > 0) code = idx & 0xff;
        *out++ = (unsigned char)code;
        str += step;
        count++;
    }
    return count;
}
