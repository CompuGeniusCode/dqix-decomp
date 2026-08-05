#include <globaldefs.h>
#include "std_library_functions.h"

void* GetBoundedEntry020425b4(int idx, int tableIdx);
extern unsigned char data_020e7a50;

// USA: func_02042764
extern "C" ARM void func_02042764(unsigned char* src, char* dst, int n) {
    if (!dst) return;
    if (!src) {
        if (dst) *dst = 0;
        return;
    }
    unsigned char b9;
    unsigned char b8 = *((unsigned char*)&data_020e7a50 + 8);
    b9 = *((unsigned char*)&data_020e7a50 + 9);
    unsigned char local[2];
    for (;;) {
        unsigned char ch = *src;
        if (ch == 0) {
            *dst = 0;
            return;
        }
        local[0] = b8;
        local[1] = b9;
        void* copySrc = local;
        int size = 1;
        void* entry = GetBoundedEntry020425b4(ch, n);
        if (entry != NULL) {
            copySrc = *(void**)entry;
            signed char raw = *((signed char*)entry + 5);
            size = (raw << 26) >> 26;
        }
        memcpy(dst, copySrc, size);
        src++;
        dst += size;
    }
}
