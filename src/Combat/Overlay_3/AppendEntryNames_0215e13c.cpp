#include <globaldefs.h>

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

extern char data_ov003_0217ff3e;

// USA: func_ov003_0215e13c
ARM void AppendEntryNames_0215e13c(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + 0x3c1);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + 0x64);
    int i = 0;
    while (i < *(unsigned char*)(base + 0x3c0)) {
        unsigned char key = *(unsigned char*)(base + i + 0x3bd);
        int name = GetFieldByKey020e0434(c, key);
        AppendNameTag(dst, i, (const char*)name);
        if (i != *(unsigned char*)(base + 0x3c0) - 1) {
            AppendString02042058(dst, &data_ov003_0217ff3e);
        }
        i++;
    }
}
