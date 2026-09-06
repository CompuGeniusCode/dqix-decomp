#include <globaldefs.h>

extern char data_020effec;

extern "C" int sprintf(char* dst, const char* fmt, ...);
ARM int StringLength(const char* s);

// USA: func_02041fe8
ARM int AppendFormatted02041fe8(char* buf, int a) {
    char* end = buf + StringLength(buf);
    return (end + sprintf(end, &data_020effec, a)) - buf;
}
