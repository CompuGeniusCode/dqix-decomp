#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020efeb3;

// USA: func_02041b70
ARM int AppendNameTag(char* dst, int n, const char* name) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020efeb3, n, name)) - dst;
}
