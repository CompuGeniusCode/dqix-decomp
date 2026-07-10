#include <globaldefs.h>

extern char data_020effcb;

extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
ARM int StringLength(const char* s);

// USA: func_02041f70
ARM int AppendFormatted02041f70(char* buf, int a, int b) {
    char* end = buf + StringLength(buf);
    return (end + func_02003ce8(end, &data_020effcb, a, b)) - buf;
}
