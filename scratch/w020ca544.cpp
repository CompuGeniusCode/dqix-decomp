#include <globaldefs.h>

struct Word3_020ca544 { unsigned int a, b, c; };

// USA: func_020ca544
ARM void CopyWords12_020ca544(const Word3_020ca544* src, Word3_020ca544* dst) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}
