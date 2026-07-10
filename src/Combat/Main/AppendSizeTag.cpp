#include <globaldefs.h>

extern char data_020eff43;
int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);

// USA: func_02041d9c
ARM int AppendSizeTag(char* dst, int size) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020eff43, size)) - dst;
}
