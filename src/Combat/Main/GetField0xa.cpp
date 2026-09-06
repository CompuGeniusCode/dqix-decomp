#include <globaldefs.h>

extern char data_021015a0;

// USA: func_0202d698
ARM unsigned short GetField0xa(void) {
    return *(unsigned short*)(&data_021015a0 + 0xa);
}
