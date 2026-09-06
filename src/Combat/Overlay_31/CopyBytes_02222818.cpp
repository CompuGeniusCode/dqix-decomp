#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_ov031_02222818  (semantic: CopyBytes_02222818)
extern "C" THUMB void func_ov031_02222818(unsigned char* dst, const unsigned char* src, unsigned int count) {
    unsigned int i = 0;
    if (i < count) {
        do {
            dst[i] = src[i];
            i++;
        } while (i < count);
    }
}
