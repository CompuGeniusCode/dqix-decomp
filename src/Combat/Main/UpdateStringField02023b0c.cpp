#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02023b0c
ARM void UpdateStringField02023b0c(char* a, char* b) {
    if (b == NULL) return;
    if (strcmp(b, a + 2) == 0) {
        ((unsigned char*)a)[0x12] = 0;
    } else {
        ((unsigned char*)a)[0x12] = 1;
    }
    if (((unsigned char*)a)[0x12] != 0) {
        a[0x779] = 0;
        a[0x9ba] = 0;
    }
    strcpy(a + 2, b);
}
