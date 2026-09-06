#include <globaldefs.h>
#pragma optimize_for_size off

// USA: func_020ca3b8
ARM void CopyShorts_020ca3b8(char* src, char* dst, int n) {
    int ip = 0;
    unsigned short r3;
    do {
        if (ip < n) {
            r3 = *(unsigned short*)(src + ip);
        }
        if (ip < n) {
            *(unsigned short*)(dst + ip) = r3;
        }
        if (ip < n) {
            ip += 2;
        }
    } while (ip < n);
}
