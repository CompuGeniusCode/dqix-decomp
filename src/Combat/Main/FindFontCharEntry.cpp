#include <globaldefs.h>

extern int data_0210782c[];
extern "C" int memcmp(int val, int key, int field5);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

// Finds the table entry for the character at the head of the string: an entry holds a pointer to
// the character's own bytes and, in a 6 bit field, its byte length, which is the advance callers
// step by (memcmp is memcmp). The index presumably selects the font -- func_02042804 loads
// data/pack_lv5/fd_%s.bin and fi_%s.bin and func_02042944 calls it with "s7" for index 0 and "me"
// for index 1, the only four files there -- but "font" is inferred from those prefixes and the
// text-measuring caller. The lookup at 0x020425e4 keys a second array on two bytes, likely kerning.
extern "C" ARM struct Entry0204254c* FindFontCharEntry(int key, int tableIdx) {
    char* header;
    unsigned int i;
    if (key == 0) {
        return NULL;
    }
    header = (char*)data_0210782c[tableIdx];
    for (i = 0; i < *(unsigned int*)(header + 4); i++) {
        struct Entry0204254c* e = *(struct Entry0204254c**)(header + 0x10) + i;
        if (memcmp(e->val, key, e->field5) == 0) {
            return e;
        }
    }
    return NULL;
}
