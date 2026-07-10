#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020efe7f;

// USA: func_02041a5c
ARM int AppendYTag(char* dst, int y) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020efe7f, y)) - dst;
}
