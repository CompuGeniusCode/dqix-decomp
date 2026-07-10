#include <globaldefs.h>

extern "C" int func_0202e09c(int);

// USA: func_020100f8
ARM int GetFieldIfFlag4(char* obj) {
    int p = *(int*)(obj + 0x3b0);
    if (p != 0) {
        if (func_0202e09c(p) & 4) {
            return *(int*)(obj + 0x3b0);
        }
    }
    return 0;
}
