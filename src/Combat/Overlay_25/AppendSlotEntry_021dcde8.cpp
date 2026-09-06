#include <globaldefs.h>

struct FiveWordsAndByte_021dcd28 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned char b;
};

void CopyFiveWordsAndByte_021dcd28(struct FiveWordsAndByte_021dcd28* dst, struct FiveWordsAndByte_021dcd28* src);

// USA: func_ov025_021dcde8
ARM void AppendSlotEntry_021dcde8(unsigned char* obj, struct FiveWordsAndByte_021dcd28* src) {
    if (*(unsigned char*)(obj + 0x6f00) >= 5) {
        return;
    }
    CopyFiveWordsAndByte_021dcd28((struct FiveWordsAndByte_021dcd28*)(obj + 0x6f08 + *(unsigned char*)(obj + 0x6f00) * 0x1c), src);
    *(unsigned short*)(obj + *(unsigned char*)(obj + 0x6f00) * 0x1c + 0x6f00 + 0x20) = 0;
    *(unsigned short*)(obj + *(unsigned char*)(obj + 0x6f00) * 0x1c + 0x6f00 + 0x22) = 0;
    if (*(unsigned char*)(obj + 0x6f00) != 0) {
        int count = *(unsigned char*)(obj + 0x6f00);
        unsigned short prev = *(unsigned short*)(obj + (count - 1) * 0x1c + 0x6f00 + 0x20);
        *(unsigned short*)(obj + count * 0x1c + 0x6f00 + 0x22) = prev;
    }
    *(unsigned char*)(obj + 0x6f00) = *(unsigned char*)(obj + 0x6f00) + 1;
}
