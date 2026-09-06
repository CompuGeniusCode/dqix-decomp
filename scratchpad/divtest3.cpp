#include <globaldefs.h>
ARM int Div8c(unsigned char b) {
    return ((short)b * 14 + 31) / 8;
}
