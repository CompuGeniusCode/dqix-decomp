#include <globaldefs.h>

extern "C" int func_02023a9c(char* obj, int i);

// USA: func_02026a78
ARM int CountMatchingEntries02026a78(char* obj) {
    unsigned char count = 0;
    int i;
    for (i = 0; i < *(unsigned char*)(obj + 0x780); i++) {
        if (func_02023a9c(obj, i)) {
            count++;
        }
    }
    return count;
}
