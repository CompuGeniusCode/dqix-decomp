#include <globaldefs.h>
ARM int Div8d(unsigned char* self) {
    short b = self[0x590];
    return (b * (short)14 + 31) / 8;
}
