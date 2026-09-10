#include <globaldefs.h>

// Selects the screen size of a background tilemap buffer: the size code goes to +0x18 and the table
// row at +0x1f is reset to 0. The pair indexes data_020e7b98[+0x1f][+0x18], read as the buffer's byte
// size by the allocator at 0x0204b12c, the memset at 0x0204b010 and the cache flush at 0x0204b04c.
// Row 0 is 0x800/0x1000/0x1000/0x2000, the four NDS text-BG map sizes at two bytes an entry; row 1 is
// 0x200/0x800/0x2000/0x8000, the extended rotation/scaling sizes, so clearing +0x1f presumably means
// plain text BG -- unproven: 51 of 67 callers pass 0, and +0x1f is only ever written with 0.
extern "C" ARM void SetTextBgScreenSize(unsigned char* obj, int value) {
    *(int*)(obj + 0x18) = value;
    obj[0x1f] = 0;
}
