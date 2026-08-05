#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double func_020055d4(char* str);
int GetGlobalField0x1c020421a0(void);

// USA: func_02069c1c
extern "C" ARM int func_02069c1c(char** obj, char* str) {
    float localArr[1];
    for (int i = 0; i < 1; i++) {
        signed char c = *str;
        if (c != 0 && c >= '0' && c <= '9') {
            float f = (float)func_020055d4(str);
            localArr[i] = f;
            while (1) {
                c = *str;
                if (c == 0) break;
                if (c == ',' || c == '>') {
                    str++;
                    break;
                }
                str++;
            }
        }
    }
    char* g = (char*)GetGlobalField0x1c020421a0();
    *(int*)(g + 0x1000 + 0x840) = (int)(localArr[0] * 4096.0f);
    void* dst = *obj;
    unsigned short marker = 0xff2a;
    memcpy(dst, &marker, 2);
    return 2;
}
