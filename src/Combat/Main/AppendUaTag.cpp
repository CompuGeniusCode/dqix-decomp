#include <globaldefs.h>

extern char data_020eff93;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041ed8
ARM int AppendUaTag(char* dst, int a, int b, int c) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020eff93, a, b, c)) - dst;
}
