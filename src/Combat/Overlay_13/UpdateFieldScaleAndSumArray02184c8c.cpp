#include <globaldefs.h>

int GetFieldAt0x150(unsigned char* obj);

// USA: func_ov013_02184c8c  (semantic: UpdateFieldScaleAndSumArray02184c8c)
extern "C" ARM void func_ov013_02184c8c(unsigned char* obj, unsigned char* other) {
    if (other == 0 || *(unsigned char*)(obj + 0x664) == 0) return;

    unsigned char* fieldPtr = (unsigned char*)GetFieldAt0x150(other);
    *(unsigned short*)(fieldPtr + 0x564) = *(int*)(obj + 0x66c);

    for (int i = 0; i < 5; i++) {
        unsigned char* bytePtr = obj + i;
        unsigned char idx = bytePtr[0x6a9];
        int sum = *(int*)(obj + 0x674 + i * 4) + *(int*)(obj + 0x688 + i * 4);
        *(unsigned char*)(fieldPtr + idx + 0x464) = (unsigned char)sum;
    }
}
