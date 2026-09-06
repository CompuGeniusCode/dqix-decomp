#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020eff2f[];

// USA: func_02041d48
ARM int AppendLineYTag02041d48(char* dst, int a1, int a2, int a3, int a4) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, data_020eff2f, a1, a2, a3, a4)) - dst;
}
