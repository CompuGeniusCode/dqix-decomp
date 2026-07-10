#include <globaldefs.h>

extern char data_0210a010;

// USA: func_020b3900
ARM void PackFieldsAt0x94(unsigned int a, unsigned int b, int flag) {
    *(unsigned int*)(&data_0210a010 + 0x94) = a | (b << 16) | ((flag != 0) << 15);
}
