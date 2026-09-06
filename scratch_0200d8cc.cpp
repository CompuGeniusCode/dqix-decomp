#include <globaldefs.h>

extern "C" int func_0200d8a8(void);

// USA: func_0200d8cc
ARM int ReadLineUntilNewline_0200d8cc(int unused, unsigned char* buffer, unsigned int* countPtr) {
    unsigned int i = 0;
    unsigned int max = *countPtr;
    if (i >= max) goto end;
    do {
        int ch = func_0200d8a8();
        int lowByte = ch & 0xff;
        buffer[i] = (unsigned char)ch;
        if (lowByte == 0xd || lowByte == 0xa) {
            *countPtr = i + 1;
            goto end;
        }
        i++;
    } while (i < max);
end:
    return 0;
}
