#include <globaldefs.h>

int TestBitInByteArray(int, unsigned char*, int);

// USA: func_0206e384
ARM unsigned short BuildBitmask0206e384(unsigned char* obj) {
    unsigned short result = 0;
    int i;
    for (i = 0; i < 16; i++) {
        if (TestBitInByteArray((int)obj, obj + 0x8c, i + 0xc02)) {
            result |= (1 << i);
        }
    }
    return result;
}
