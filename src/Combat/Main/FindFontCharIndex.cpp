#include <globaldefs.h>

extern int data_0210782c[];
extern "C" int memcmp(int lhs, int key, int length);

struct FontCharEntry {
    int charBytes;
    char glyphWidth;
    signed char field5 : 6;
    signed char unused2 : 2;
    char unknown6[2];
};

// Returns the index of the entry that matches a character, or -1 when nothing matches or the string
// pointer is null. It is the search FindFontCharEntry does over the same data_0210782c[tableIdx]
// tables, returning the index instead of the entry; each entry holds a pointer to the character's
// bytes and, in a six-bit field, how many to compare, so multi-byte characters match whole.
// MeasureStringWidth uses the result both to fetch the entry and as the kerning key. Reading the
// tables as fonts is inference from the "fd_%s.bin"/"fi_%s.bin" names, whose me and s7 files give
// the two tableIdx. The table header holds the entry count at +0x4 and the entry array at +0x10,
// and byte 4 of an entry is the glyph width MeasureStringWidth adds one to for the advance.
extern "C" ARM int FindFontCharIndex(int key, int tableIdx) {
    char* header;
    unsigned int entryIndex;
    if (key == 0) {
        return -1;
    }
    header = (char*)data_0210782c[tableIdx];
    for (entryIndex = 0; entryIndex < *(unsigned int*)(header + 4); entryIndex++) {
        struct FontCharEntry* entry = *(struct FontCharEntry**)(header + 0x10) + entryIndex;
        if (memcmp(entry->charBytes, key, entry->field5) == 0) {
            return entryIndex;
        }
    }
    return -1;
}
