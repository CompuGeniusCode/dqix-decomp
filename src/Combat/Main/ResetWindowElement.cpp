#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0204f0ec(char* obj);
struct Record0204acb0;
extern "C" void func_0204acb0(struct Record0204acb0* rec);

struct BitsD8_0204c684 {
    unsigned char flagA : 1;
    unsigned char flagB : 1;
    unsigned char flagC : 1;
    unsigned char valD  : 5;
};

// Puts one window element back into its unused state. Byte 0xc4 is the window id and 0xff is the
// "bound to nothing" value func_02081de0 hunts for on behalf of OpenWindowById when it needs a free
// slot. The shorts it seeds at 0xb0..0xb6 are presumably drawing defaults, but no reader of them is
// established; func_02080d54 hit-tests only the width and height at 0xa8/0xaa and the position at
// 0xac/0xae. Same 0xe0-byte struct func_0204c87c reads back when redrawing.
extern "C" ARM void ResetWindowElement(char* obj) {
    *(int*)(obj + 0x0) = 0;
    *(int*)(obj + 0x4) = 0;
    *(int*)(obj + 0x8) = 0;
    func_0204f0ec(obj);

    *(int*)(obj + 0x9c) = 0;
    *(int*)(obj + 0xa0) = 0;
    *(int*)(obj + 0xa4) = 0;
    *(short*)(obj + 0xac) = 0;
    *(short*)(obj + 0xae) = 0;
    *(short*)(obj + 0xa8) = 0;
    *(short*)(obj + 0xaa) = 0;
    *(short*)(obj + 0xb0) = 4;
    *(short*)(obj + 0xb2) = 4;
    *(short*)(obj + 0xb4) = 0xa;
    *(short*)(obj + 0xb6) = 0xb;
    *(short*)(obj + 0xb8) = 0;
    *(short*)(obj + 0xba) = 0;
    *(short*)(obj + 0xbc) = 0;
    *(short*)(obj + 0xbe) = 0;
    *(short*)(obj + 0xc0) = 0;
    *(short*)(obj + 0xc2) = 0;
    *(unsigned char*)(obj + 0xc5) = 0;
    *(unsigned char*)(obj + 0xc4) = 0xff;
    *(unsigned char*)(obj + 0xc6) = 2;
    *(unsigned char*)(obj + 0xc7) = 0xa;

    func_0204acb0((struct Record0204acb0*)(obj + 0xc8));

    BitsD8_0204c684* bits = (BitsD8_0204c684*)(obj + 0xd8);
    bits->flagA = 0;
    bits->valD = 0;
    *(unsigned char*)(obj + 0xd9) = 0;
    *(unsigned char*)(obj + 0xda) = 0;

    bits->flagB = 1;
    bits->flagC = 0;

    memset(obj + 0xdb, 0, 4);
}
