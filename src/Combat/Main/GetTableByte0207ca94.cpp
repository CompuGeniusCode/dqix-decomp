#include <globaldefs.h>

extern unsigned char data_020e89fc;

// USA: func_0207ca94
ARM unsigned char GetTableByte0207ca94(int index) {
    return (&data_020e89fc)[index];
}
