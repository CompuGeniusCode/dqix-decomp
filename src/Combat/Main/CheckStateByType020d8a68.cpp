#include <globaldefs.h>

// USA: func_020d8a68
ARM int CheckStateByType020d8a68(unsigned char* obj) {
    switch (*(unsigned short*)obj) {
    case 1: {
        int b;
        if (((int*)obj)[4] & 0x10) {
            b = 1;
        } else {
            b = 0;
        }
        return b != 0;
    }
    case 2:
        return 1;
    default:
        return 0;
    }
}
