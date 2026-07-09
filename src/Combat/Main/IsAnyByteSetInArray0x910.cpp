#include <globaldefs.h>

// USA: func_02083be8
ARM int IsAnyByteSetInArray0x910(unsigned char* obj) {
    int i;
    for (i = 0; i < 9; i++) {
        if ((obj + i)[0x910] != 0) {
            return 1;
        }
    }
    return 0;
}
