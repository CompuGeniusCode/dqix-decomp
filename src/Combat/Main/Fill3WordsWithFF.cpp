#include <globaldefs.h>

// USA: func_020b0318
ARM void Fill3WordsWithFF(int* p) {
    int i = 0;
    do {
        p[i] = -1;
        i++;
    } while (i < 3);
}
