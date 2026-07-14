#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* src);

// USA: func_02042058
ARM int AppendString02042058(char* dst, const char* src) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, src)) - dst;
}
