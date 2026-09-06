#include <globaldefs.h>

// USA: func_02001aec  (semantic: CompareByteBuffers)
extern "C" ARM int func_02001aec(unsigned char* a, unsigned char* b, int n) {
    if (n != 0) {
        do {
            if (*a++ != *b++) {
                return (a[-1] < b[-1]) ? -1 : 1;
            }
        } while (--n != 0);
    }
    return 0;
}
