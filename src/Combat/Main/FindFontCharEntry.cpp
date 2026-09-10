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

// Finds the table entry for the character at the head of the string: an entry holds a pointer to
// the character's own bytes and, in a 6 bit field, its byte length, which is the advance callers
// step by (memcmp is memcmp). The index presumably selects the font -- func_02042804 loads
// data/pack_lv5/fd_%s.bin and fi_%s.bin and func_02042944 calls it with "s7" for index 0 and "me"
// for index 1, the only four files there -- but "font" is inferred from those prefixes and the
// text-measuring caller. The lookup at 0x020425e4 keys a second array on two bytes, likely kerning.
// The table header holds the entry count at +0x4 and the entry array at +0x10, and byte 4 of an
// entry is the glyph width MeasureStringWidth adds one to for the advance.
extern "C" ARM struct FontCharEntry* FindFontCharEntry(int key, int tableIdx) {
    char* header;
    unsigned int entryIndex;
    if (key == 0) {
        return NULL;
    }
    header = (char*)data_0210782c[tableIdx];
    for (entryIndex = 0; entryIndex < *(unsigned int*)(header + 4); entryIndex++) {
        struct FontCharEntry* entry = *(struct FontCharEntry**)(header + 0x10) + entryIndex;
        if (memcmp(entry->charBytes, key, entry->field5) == 0) {
            return entry;
        }
    }
    return NULL;
}
