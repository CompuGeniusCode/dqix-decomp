#include <globaldefs.h>

// USA: func_020ca390
ARM void FillShorts_020ca390(unsigned short value, char* dst, int len) {
    int i = 0;
    if (i < len) {
        do {
            *(unsigned short*)(dst + i) = value;
            i += 2;
        } while (i < len);
    }
}
