#include <globaldefs.h>

typedef char* va_list;

extern "C" int func_02003c80(char* buf, int size, const char* fmt, va_list ap);
extern "C" void func_0202ad4c(int a, int b, int c, char* buf);

// USA: func_0202ad98
ARM void FormatAndDispatch0202ad98(int a, int b, int c, const char* fmt, ...) {
    char buf[0x21];
    va_list ap = (va_list)(((unsigned int)&fmt & ~3u) + 4);
    func_02003c80(buf, 0x21, fmt, ap);
    func_0202ad4c(a, b, c, buf);
}
