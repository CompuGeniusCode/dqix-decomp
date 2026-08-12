#include <globaldefs.h>
#include "System/Memory.h"

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
void CopyToSlot_021f6e90(char* obj, int idx, const void* src);

struct LocalBuf021882d4 {
    unsigned char count;
    unsigned char pad;
    unsigned short arr[8];
    short field12;
    short field14;
};

// USA: func_ov011_021882d4  (semantic: FillTaggedArrayAndCopy_021882d4)
extern "C" ARM int func_ov011_021882d4(struct TaggedNumber02184c30* tagged, int n) {
    LocalBuf021882d4 buf;
    int i;
    VectorizedMemset(&buf, 0, sizeof(buf));
    buf.field12 = -1;
    buf.field14 = -1;

    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    buf.field12 = (unsigned short)GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    {
        struct TaggedNumber02184c30* p2 = (struct TaggedNumber02184c30*)((char*)tagged + 0x10);
        tagged = (struct TaggedNumber02184c30*)((char*)tagged + 0x18);
        buf.field14 = (unsigned short)GetTaggedValueAsInt_02184c30(p2);
    }

    buf.count = (unsigned char)(n - 3);
    for (i = 0; i < buf.count; i++) {
        int v = GetTaggedValueAsInt_02184c30(tagged);
        tagged = (struct TaggedNumber02184c30*)((char*)tagged + 8);
        if (i < 8) buf.arr[i] = (unsigned short)v;
    }

    CopyToSlot_021f6e90((char*)func_ov011_021849c8(func_ov017_021b2164()), v0, &buf);
    return 1;
}
