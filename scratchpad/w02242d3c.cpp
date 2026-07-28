#include <globaldefs.h>

// USA: func_ov031_02242d3c
extern "C" ARM int ParseUnsignedFromString_02242d3c(const char* str, int len) {
    if (len > 10) return -1;
    int i = 0;
    int started = 0;
    int acc = 0;
    if (i < len) {
        do {
            signed char ch = str[i];
            if (started != 0) {
                if (ch == 0x20 || ch == 0) return acc;
            } else if (ch == 0x20) {
                goto next;
            }
            if (ch < 0x30) return -1;
            if (ch > 0x39) return -1;
            {
                int old = acc;
                acc = old * 10 + ch - 0x30;
                started = 1;
                if (old > acc) return -1;
            }
next:
            i++;
        } while (i < len);
    }
    return acc;
}
