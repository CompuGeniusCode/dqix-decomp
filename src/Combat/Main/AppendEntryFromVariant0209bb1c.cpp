#include <globaldefs.h>

struct Variant02030b0c { int tag; int val; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
// AppendZeroedEntry0209bd40's 2nd arg is int-width at this call site (mov r1,r4, no
// narrowing); its own body truncates via strh, so the existing "short" decl is a
// naming inaccuracy. Declared int here so the bytes match.
void AppendZeroedEntry0209bd40(char* obj, int value);

struct Recorder0209bb0b {
    char* buffer;                // 0x0
    unsigned char pad[0x10];     // 0x4
    int active;                  // 0x14
    int lastValue;               // 0x18
};
extern struct Recorder0209bb0b* data_02109bb0;

// USA: func_0209bb1c
ARM int AppendEntryFromVariant0209bb1c(struct Variant02030b0c* variant) {
    if (data_02109bb0->active == 0) return 1;
    int value = GetIntFromVariant02030b0c(variant);
    AppendZeroedEntry0209bd40(data_02109bb0->buffer, value);
    data_02109bb0->lastValue = value;
    return 1;
}
