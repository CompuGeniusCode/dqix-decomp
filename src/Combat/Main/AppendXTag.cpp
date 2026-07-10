#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020efe78;

// USA: func_02041a28
ARM int AppendXTag(char* dst, int x) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020efe78, x)) - dst;
}
