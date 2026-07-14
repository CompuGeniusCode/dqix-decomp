#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efec0;

// USA: func_02041bac
ARM int AppendSourceRectTag(char* dst, int a, int b, int c, int d, int e) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efec0, a, b, c, d, e)) - dst;
}
