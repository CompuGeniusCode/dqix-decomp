#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendFormatted02041fac(char* buf, int a, int b);
int CallFunc020e0434With02153694(int value);

// USA: func_ov002_0216186c  (semantic: AppendCursorAndNameTags_0216186c)
extern "C" ARM void func_ov002_0216186c(char* base, char* dst, int flag) {
    if (dst == NULL) {
        return;
    }

    int cursor = *(short*)(base + 0x1c00 + 0x14);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    int field = GetFieldByKey020e0434((struct Container020e0310*)(base + 0x20), 0x23f0);
    AppendFormatted02041fac(dst, field, 0x10);

    AppendNameTag(dst, 0, (const char*)CallFunc020e0434With02153694(0x1b));

    void* ptr = *(void**)(base + 0x1000 + 0xbdc);
    AppendString02042058(dst, (const char*)ptr);

    AppendNameTag(dst, 1, (const char*)CallFunc020e0434With02153694(0x1c));
}
