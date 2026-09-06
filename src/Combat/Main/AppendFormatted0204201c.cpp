#include <globaldefs.h>

extern char data_020efffc;

extern "C" int sprintf(char* dst, const char* fmt, ...);
ARM int StringLength(const char* s);

// USA: func_0204201c
ARM int AppendFormatted0204201c(char* buf, int a, int b) {
    char* end = buf + StringLength(buf);
    return (end + sprintf(end, &data_020efffc, b, a)) - buf;
}
