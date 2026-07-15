#include <globaldefs.h>

extern "C" int func_020420e8(const char* str, int flags);
int AppendXTag(char* dst, int x);
int AppendString02042058(char* dst, const char* src);
int AppendWidthTag(char* dst, int w);

struct DstHolder0215b8c8 { char* dst; };

// USA: func_ov002_0215b8c8
ARM void AppendTaggedString_0215b8c8(struct DstHolder0215b8c8* holder, const char* str, int value) {
    int width = func_020420e8(str, value & 0xff);
    int halfWidth = (((width + 0x17) & ~7) - width) >> 1;
    AppendXTag(holder->dst, halfWidth);
    AppendString02042058(holder->dst, str);
    AppendWidthTag(holder->dst, halfWidth - 5);
}
