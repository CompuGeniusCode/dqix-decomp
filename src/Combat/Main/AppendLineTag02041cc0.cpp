#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern "C" const char data_020eff11[];

// USA: func_02041cc0
ARM int AppendLineTag02041cc0(char* dst, int a1) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, data_020eff11, a1)) - dst;
}
