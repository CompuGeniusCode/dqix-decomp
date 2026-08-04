#include <globaldefs.h>
#pragma optimize_for_size off

// USA: func_ov031_0221d8e8  (semantic: ComputeChecksumReversed_0221d8e8)
extern "C" THUMB unsigned int func_ov031_0221d8e8(unsigned char *buf, int len) {
    unsigned int result = 0;
    unsigned char *p = buf + (len - 1);
    int i = 0;
    if (len > 0) {
        do {
            result = (result << 8) + *p--;
            i++;
        } while (i < len);
    }
    return result;
}
