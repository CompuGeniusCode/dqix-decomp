#include <globaldefs.h>

extern "C" int func_0202e09c(int);

// USA: func_020100cc
ARM int GetFieldIfFlag2(char* obj) {
    int p = *(int*)(obj + 0x3b0);
    if (p != 0) {
        if (func_0202e09c(p) & 2) {
            return *(int*)(obj + 0x3b0);
        }
    }
    return 0;
}
