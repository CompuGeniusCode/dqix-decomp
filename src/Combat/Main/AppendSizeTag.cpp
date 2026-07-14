#include <globaldefs.h>

extern char data_020eff43;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041d9c
ARM int AppendSizeTag(char* dst, int size) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020eff43, size)) - dst;
}
