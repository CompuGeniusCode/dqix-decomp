#include <globaldefs.h>
#include "std_library_functions.h"

// Clears the global message-assembly object reached through GetMessageWork, which
// returns data_02107800+0x1c, the same text-system global the font descriptors at data_0210782c
// hang off. The 0x400 block at +0x4ac is the sixteen 0x40-byte substitution name slots
// SetMessageNameSlot writes, and the 0x40 block at +0x8b0 the sixteen argument words
// func_020465c0 writes; callers reset, fill slots, then call FormatMessageText, which seems to
// expand the text. What the smaller fields at +0x2ec, +0x1880 and +0x19d5 hold is not established.
extern "C" ARM void ResetMessageBuilder(void* obj) {
    *(signed char*)((char*)obj + 0x30) = -1;
    *(signed char*)((char*)obj + 0x31) = -1;
    *(signed char*)((char*)obj + 0x1880) = -1;
    memset((char*)obj + 0x2ec, 0, 0xc0);
    memset((char*)obj + 0x3ac, 0, 0x40);
    memset((char*)obj + 0x3ec, 0, 0x40);
    memset((char*)obj + 0x42c, 0, 0x40);
    memset((char*)obj + 0x46c, 0, 0x40);
    memset((char*)obj + 0x4ac, 0, 0x400);
    memset((char*)obj + 0x8b0, 0, 0x40);
    memset((char*)obj + 0x8f1, 0, 0x10);
    memset((char*)obj + 0x902, 0, 0x10);

    *(int*)((char*)obj + 0x8ac) = 0;
    *(unsigned char*)((char*)obj + 0x901) = 0;
    *(unsigned char*)((char*)obj + 0x8f0) = 0;
    *(int*)((char*)obj + 0x2e8) = 0;

    int (*matrix)[2] = (int(*)[2])obj;
    for (int i = 0; i < 2; i++) {
        matrix[0][i] = 0;
        matrix[1][i] = 0;
        matrix[2][i] = 0;
        matrix[3][i] = 0;
        matrix[4][i] = 0;
    }

    *(int*)((char*)obj + 0x28) = 0;
    *(int*)((char*)obj + 0x2c) = 0;
    *(unsigned char*)((char*)obj + 0x19d5) = 0;
    *(unsigned char*)((char*)obj + 0x19d6) = 0;
    *(unsigned char*)((char*)obj + 0x19d7) = 0;
    *(unsigned char*)((char*)obj + 0x19d8) = 0;
}
