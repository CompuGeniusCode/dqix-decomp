#include <globaldefs.h>

struct EntryA0204b088 { int words[4]; };
struct EntryB0204b088 { void* fns[4]; };
extern EntryA0204b088 data_020e7b98[];
extern EntryB0204b088 data_020f0218[];

typedef void (*Fn0204b088)(int, int, int);

// USA: func_0204b088
ARM void Dispatch0204b088(char* obj, int val) {
    if (val == 0) {
        val = *(int*)(obj + 0x14);
    }
    if (val == 0) {
        return;
    }
    unsigned char b1c = *(unsigned char*)(obj + 0x1c);
    unsigned char b1f = *(unsigned char*)(obj + 0x1f);
    int idx1 = *(int*)(obj + 0x18);
    int lowNibble = b1c & 0xF;
    int highNibble = b1c >> 4;
    EntryA0204b088* a = &data_020e7b98[b1f];
    EntryB0204b088* b = &data_020f0218[lowNibble];
    int ctx = a->words[idx1];
    Fn0204b088 fn = (Fn0204b088)b->fns[highNibble];
    fn(val, 0, ctx);
}
