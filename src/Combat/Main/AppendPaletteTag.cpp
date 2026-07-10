#include <globaldefs.h>

extern char data_020eff74;
int StringLength(const char* s);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);

// USA: func_02041e70
ARM int AppendPaletteTag(char* dst, int palette) {
    char* end = dst + StringLength(dst);
    return (end + func_02003ce8(end, &data_020eff74, palette)) - dst;
}
