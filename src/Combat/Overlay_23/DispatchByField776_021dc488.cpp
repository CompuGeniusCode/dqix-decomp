#include <globaldefs.h>

extern "C" void func_ov023_021db110(void* obj);

struct Pair021dc488 { volatile unsigned int a; volatile unsigned int b; };
extern struct Pair021dc488 data_020e6d5c;

struct FlagStruct021dc488 { unsigned char pad[0x1c]; unsigned int flags; };
extern struct FlagStruct021dc488 data_ov023_021ff9e0;

struct TargetStruct021dc488 { unsigned char pad[0x40]; unsigned int a; unsigned int b; };
extern struct TargetStruct021dc488 data_ov023_021fda60;

extern unsigned char data_ov023_021ffa0c;

struct DispatchEntry021dc488 { unsigned int fn; unsigned int locator; };
extern struct DispatchEntry021dc488 data_ov023_021fda88[];

// USA: func_ov023_021dc488  (semantic: DispatchByField776_021dc488)
extern "C" ARM int func_ov023_021dc488(void* obj) {
    func_ov023_021db110(&data_ov023_021ffa0c);
    unsigned int flags = data_ov023_021ff9e0.flags;
    if (!(flags & 1)) {
        unsigned int va = data_020e6d5c.a;
        unsigned int vb = data_020e6d5c.b;
        data_ov023_021fda60.a = va;
        data_ov023_021fda60.b = vb;
        data_ov023_021ff9e0.flags = flags | 1;
    }
    unsigned char idx = *((unsigned char*)obj + 0x776);
    if (data_ov023_021fda88[idx].fn == 0) return 1;
    struct DispatchEntry021dc488* d = &data_ov023_021fda88[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    ((void(*)(void*))callback)(base);
    return 0;
}
