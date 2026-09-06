#include <globaldefs.h>

extern char data_020effbd;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041f24
ARM int AppendDbTag(char* dst, int a, int b, int c) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020effbd, a, b, c)) - dst;
}
