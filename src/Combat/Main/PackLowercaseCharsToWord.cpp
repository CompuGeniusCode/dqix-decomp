#include <globaldefs.h>

// USA: func_020cbbc0
ARM unsigned int PackLowercaseCharsToWord(unsigned char* str, int count) {
    unsigned int result = 0;
    if (count <= 3) {
        int i = 0;
        if (count > 0) {
            int shift = 0;
            do {
                int c = str[i];
                if (c == 0) break;
                {
                    int t = c - 0x41;
                    if ((unsigned int)t <= 0x19) c = t + 0x61; else c = t + 0x41;
                }
                i++;
                result |= c << shift;
                shift += 8;
            } while (i < count);
        }
    }
    return result;
}
