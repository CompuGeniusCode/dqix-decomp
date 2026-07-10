#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* src);

// USA: func_02042058
ARM int AppendString02042058(char* dst, const char* src) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, src)) - dst;
}
