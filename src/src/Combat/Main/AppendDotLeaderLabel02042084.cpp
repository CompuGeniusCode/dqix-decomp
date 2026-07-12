#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_020420e8(char* label, int extra);
extern "C" int func_02003ce8(char* dst, const char* fmt, ...);
extern char data_020efe91;

// USA: func_02042084
ARM int AppendDotLeaderLabel02042084(char* buffer, char* label, int width, int extra) {
    int measured = func_020420e8(label, extra);
    int count = ((width - measured) >> 1) + 1;
    func_02003ce8(buffer + StringLength(buffer), &data_020efe91, count);
    func_02003ce8(buffer + StringLength(buffer), label);
    return StringLength(buffer);
}
