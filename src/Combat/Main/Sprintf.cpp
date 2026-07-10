#include <globaldefs.h>

extern "C" int func_020c7198(char* buf, int maxLen, const char* fmt, char* args);

typedef char* va_list;

// USA: func_020c7158
ARM int Vsprintf(char* buf, const char* fmt, char* args) {
    return func_020c7198(buf, 0x7FFFFFFF, fmt, args);
}

// USA: func_020c7130
ARM int Sprintf(char* buf, const char* fmt, ...) {
    va_list args;
    args = (char*)(((int)&fmt & ~3) + 4);
    return Vsprintf(buf, fmt, args);
}
