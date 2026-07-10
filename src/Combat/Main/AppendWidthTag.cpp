#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020efe91;

// USA: func_02041acc
ARM int AppendWidthTag(char* dst, int w) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020efe91, w)) - dst;
}
