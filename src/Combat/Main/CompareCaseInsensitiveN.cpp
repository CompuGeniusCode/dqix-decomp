#include <globaldefs.h>

// USA: func_020cb220
ARM int CompareCaseInsensitiveN(unsigned char* a, unsigned char* b, unsigned int n) {
    unsigned int i = 0;
    if (i < n) {
        do {
            int ca = a[i] - 0x41;
            int cb = b[i] - 0x41;
            if ((unsigned int)ca <= 0x19) ca += 0x20;
            if ((unsigned int)cb <= 0x19) cb += 0x20;
            if (ca != cb) {
                return ca - cb;
            }
            i++;
        } while (i < n);
    }
    return 0;
}
