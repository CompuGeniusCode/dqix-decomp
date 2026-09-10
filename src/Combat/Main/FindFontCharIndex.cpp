#include <globaldefs.h>

extern int data_0210782c[];
extern "C" int memcmp(int val, int key, int field5);

struct Entry020424e4 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

// Returns the index of the entry that matches a character, or -1 when nothing matches or the string
// pointer is null. It is the search FindFontCharEntry does over the same data_0210782c[tableIdx]
// tables, returning the index instead of the entry; each entry holds a pointer to the character's
// bytes and, in a six-bit field, how many to compare, so multi-byte characters match whole.
// MeasureStringWidth uses the result both to fetch the entry and as the kerning key. Reading the
// tables as fonts is inference from the "fd_%s.bin"/"fi_%s.bin" names, whose me and s7 files give
// the two tableIdx.
extern "C" ARM int FindFontCharIndex(int key, int tableIdx) {
    char* header;
    unsigned int i;
    if (key == 0) {
        return -1;
    }
    header = (char*)data_0210782c[tableIdx];
    for (i = 0; i < *(unsigned int*)(header + 4); i++) {
        struct Entry020424e4* e = *(struct Entry020424e4**)(header + 0x10) + i;
        if (memcmp(e->val, key, e->field5) == 0) {
            return i;
        }
    }
    return -1;
}
