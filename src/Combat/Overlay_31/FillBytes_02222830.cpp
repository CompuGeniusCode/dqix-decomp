#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_ov031_02222830  (semantic: FillBytes_02222830)
extern "C" THUMB void func_ov031_02222830(char* dst, int value, unsigned int count) {
    unsigned int i = 0;
    if (i < count) {
        do {
            i++;
            *dst = (char)value;
            dst++;
        } while (i < count);
    }
}
