#include <globaldefs.h>

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" void* func_0200f374(void* dst, int count);
int AppendSizeTag(char* dst, int size);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
int AppendNameTag(char* dst, int n, const char* name);

// USA: func_ov013_02185be0  (semantic: AppendCursorAndFieldNameTags02185be0)
extern "C" ARM void func_ov013_02185be0(void* base, char* dst) {
    unsigned char* b = (unsigned char*)base;
    char buf[0x20];
    int i;

    if (*(int*)(b + 0x648) == 2) {
        AppendFrameTag02041c08(dst, *(int*)(b + 0x660), 9, 3, 6, 2);
    }
    AppendCursorTag(dst, *(int*)(b + 0x660));

    for (i = 0; i < 2; i++) {
        func_0200f374(buf, 0x20);
        AppendSizeTag(buf, 0xc);
        AppendString02042058(buf, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(b + 0x620), (short)(i + 0xa)));
        AppendNameTag(dst, i, buf);
        if (i < 1) {
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(b + 0x620), 0));
        }
    }
}
