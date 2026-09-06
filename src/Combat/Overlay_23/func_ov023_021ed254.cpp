#include <globaldefs.h>

extern "C" int func_020420e8(void* p, int flag);
int AppendXYTag(char* dst, int x, int y);
int AppendString02042058(char* dst, const char* src);
int AppendSourceRectTag(char* dst, int a, int b, int c, int d, int e);

// USA: func_ov023_021ed254
extern "C" ARM void func_ov023_021ed254(char* obj, char* buf) {
    if (buf == 0) return;

    unsigned char idx = *(unsigned char*)(obj + 0x28);
    char* base = *(char**)(obj + 0x20);
    char* entry = base + idx * 0x244 + 0xc;
    int val = func_020420e8(entry, 1);
    int diff = 0xa0 - val;
    int half = diff / 2;
    if (half < 0) half = 0;
    AppendXYTag(buf, half, 6);

    if (entry != 0) {
        AppendString02042058(buf, entry);
    }

    if (!(*(unsigned short*)(obj + 0x438) & 0x2)) {
        short score = *(short*)(obj + 0x448);
        short a = score - 0xc;
        short b = 0xa0 - a;
        if (a > 0 && b > 0) {
            AppendSourceRectTag(buf, 1, a, 1, b, 0x16);
        } else if (a <= 0) {
            AppendSourceRectTag(buf, 1, 1, 1, 0x9e, 0x16);
        }
    }
    *(unsigned short*)(obj + 0x438) &= ~0x2;
}
