#include <globaldefs.h>

struct FiveWordsAndByte_021dcd28;
extern void CopyFiveWordsAndByte_021dcd28(FiveWordsAndByte_021dcd28* dst, FiveWordsAndByte_021dcd28* src);

// USA: func_ov025_021dcc70
ARM void AppendRow_021dcc70(char* obj, char* src) {
    unsigned char count = *(unsigned char*)(obj + 0x6e4d);
    if (count >= 5) return;

    char* dst = obj + 0x6e50 + (count << 5);
    CopyFiveWordsAndByte_021dcd28((FiveWordsAndByte_021dcd28*)dst, (FiveWordsAndByte_021dcd28*)src);

    unsigned char idx = *(unsigned char*)(obj + 0x6e4d);
    short v0 = *(short*)(src + 0x18);
    *(short*)(obj + 0x6e00 + (idx << 5) + 0x68) = v0;

    idx = *(unsigned char*)(obj + 0x6e4d);
    short v1 = *(short*)(src + 0x1a);
    *(short*)(obj + 0x6e00 + (idx << 5) + 0x6a) = v1;

    idx = *(unsigned char*)(obj + 0x6e4d);
    *(short*)(obj + 0x6e00 + (idx << 5) + 0x6c) = 0;

    idx = *(unsigned char*)(obj + 0x6e4d);
    *(short*)(obj + 0x6e00 + (idx << 5) + 0x6e) = 0;

    idx = *(unsigned char*)(obj + 0x6e4d);
    if (idx != 0) {
        unsigned short prev = *(unsigned short*)(obj + 0x6e00 + ((idx - 1) << 5) + 0x6c);
        *(unsigned short*)(obj + 0x6e00 + (idx << 5) + 0x6e) = prev;
    }

    unsigned char c = *(unsigned char*)(obj + 0x6e4d);
    *(unsigned char*)(obj + 0x6e4d) = c + 1;
}
