#include <globaldefs.h>

extern int TestBitInByteArray(int unused, unsigned char* arr, int index);

// USA: func_0206eb98
ARM int TestBitWithBias0206eb98(unsigned char* obj, int index) {
    int i = index;
    if (i >= 0x400) {
        return TestBitInByteArray((int)obj, obj + 0x8c, i + 0x6fa);
    }
    return TestBitInByteArray((int)obj, obj + 0x8c, i);
}
