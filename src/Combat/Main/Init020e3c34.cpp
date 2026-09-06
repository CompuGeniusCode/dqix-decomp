#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct CombatState020e3c34 {
    unsigned char header;    // 0
    unsigned char pad1[7];   // 1..7
    unsigned char byte8;     // 8
    unsigned char byte9;     // 9
    unsigned short half_a;   // 0xa
    int word_c;              // 0xc
    int word_10;             // 0x10
    int words_14[2];         // 0x14, 0x18
    int word_1c;             // 0x1c
    int word_20;             // 0x20
    unsigned char byte_24;   // 0x24
};

// USA: func_020e3c34
ARM void Init020e3c34(CombatState020e3c34* obj) {
    int i;
    ResetByteHeader((ByteHeader0204693c*)obj);
    obj->header = 0x4d;
    obj->word_1c = 0;
    obj->word_20 = 0;
    for (i = 0; i < 2; i++) {
        obj->words_14[i] = -1;
    }
    obj->byte8 = 0;
    obj->byte9 = 0;
    obj->half_a = 0;
    obj->word_c = 0;
    obj->word_10 = 0;
    obj->byte_24 = 1;
}
