#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020efec0;

// USA: func_02041bac
ARM int AppendSourceRectTag(char* dst, int a, int b, int c, int d, int e) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020efec0, a, b, c, d, e)) - dst;
}
