#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe86;

// USA: func_02041a90
ARM int AppendXYTag(char* dst, int x, int y) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efe86, x, y)) - dst;
}
