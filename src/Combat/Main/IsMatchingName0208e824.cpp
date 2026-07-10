#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_020f12b8;
extern "C" int func_02001aec(const char*, const void*, int);

// USA: func_0208e824
ARM int IsMatchingName0208e824(void* unused, char* str) {
    if (str[0] == 'F') {
        if (strlen(str) <= 3) return 1;
    }
    if (func_02001aec(str, &data_020f12b8, 6) == 0) return 1;
    return 0;
}
