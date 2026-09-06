#include <globaldefs.h>

struct Word3_020c6914 { unsigned int a, b, c; };

// USA: func_020c6914
ARM void func_020c6914(const Word3_020c6914* src, volatile Word3_020c6914* dst) {
    *dst = *src++;
    *dst = *src++;
    *dst = *src++;
    *dst = *src++;
}
