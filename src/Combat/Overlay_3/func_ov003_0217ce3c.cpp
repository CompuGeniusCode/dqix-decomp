#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct6_0217dc94;
extern "C" void func_ov003_0217dc94(Struct6_0217dc94* obj);
extern unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
extern "C" int func_0205d0e0(void* p, int val);

struct Block10Words0217ce3c { unsigned int w[10]; };
extern struct Block10Words0217ce3c data_ov003_0217fbc8;
struct Pair0217ce3c { unsigned int a; unsigned int b; };
extern struct Pair0217ce3c data_020e6d5c;
struct DispatchEntry0217ce3c { unsigned int fn; unsigned int locator; };

struct Obj0217ce3c {
    char pad0[4];
    signed char field4;
    char pad1[8 - 5];
    unsigned short field8;
    char pad2[0x14 - 0xa];
    int field14;
    char pad3[0x90 - 0x18];
    void* field90;
};

// USA: func_ov003_0217ce3c
extern "C" ARM int func_ov003_0217ce3c(struct Obj0217ce3c* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    func_ov003_0217dc94((struct Struct6_0217dc94*)obj);
    if (obj->field8 & 1) return 1;

    unsigned int scaleCount = GetBattleScaleCount(bs);
    if (obj->field90 != 0) {
        obj->field14 = func_0205d0e0(obj->field90, scaleCount);
    }

    struct Block10Words0217ce3c buf;
    buf = data_ov003_0217fbc8;
    struct Pair0217ce3c* pr = &data_020e6d5c;
    unsigned int tmp1 = pr->b;
    unsigned int tmp0 = pr->a;
    ((struct DispatchEntry0217ce3c*)&buf)[4].locator = tmp1;
    ((struct DispatchEntry0217ce3c*)&buf)[4].fn = tmp0;

    signed char idx = obj->field4;
    struct DispatchEntry0217ce3c* entries = (struct DispatchEntry0217ce3c*)&buf;
    if (entries[idx].fn == 0) return 0;
    struct DispatchEntry0217ce3c* d = &entries[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void (*callback)(void*);
    if (d->locator & 1) {
        callback = (void(*)(void*))(*(void**)((char*)*(void**)base + d->fn));
    } else {
        callback = (void(*)(void*))d->fn;
    }
    callback(base);
    return 1;
}
