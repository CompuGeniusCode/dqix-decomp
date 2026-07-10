#include <globaldefs.h>

extern char data_020effd7;

extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
ARM int StringLength(const char* s);

// USA: func_02041fac
ARM int AppendFormatted02041fac(char* buf, int a, int b) {
    char* end = buf + StringLength(buf);
    return (end + func_02003ce8(end, &data_020effd7, b, a)) - buf;
}
