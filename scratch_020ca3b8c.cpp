#include <globaldefs.h>

// USA: func_020ca3b8
ARM void CopyHalfwordsLoop020ca3b8(char* src, char* dst, int n) {
    int i = 0;
    unsigned short tmp;
    for (;;) {
        if (i >= n) break;
        tmp = *(unsigned short*)(src + i);
        if (i >= n) break;
        *(unsigned short*)(dst + i) = tmp;
        if (i >= n) break;
        i += 2;
    }
}
