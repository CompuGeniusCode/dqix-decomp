#include <globaldefs.h>

extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* src);

// Appends src at the end of dst, with sprintf standing in for strcat, and returns dst's new total
// length, which lets callers chain appends without re-measuring. Nothing extra rides through: at the
// sprintf call r2 still holds the length StringLength left there, and every call site passes two
// arguments. Sibling func_02042084 uses the same idiom.
extern "C" ARM int AppendString(char* dst, const char* src) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, src)) - dst;
}
