#include <globaldefs.h>

extern "C" int func_020b3184(void* a, void* b);
extern "C" int func_020b33f0(void* a, void* b);

struct Obj020b357c {
    unsigned char pad0[9];
    volatile unsigned char count;
    unsigned char pada[4];
    unsigned short off;
};

// USA: func_020b357c  (semantic: DispatchIndexedEntries020b357c)
extern "C" ARM int func_020b357c(struct Obj020b357c* obj, void* ctx) {
    unsigned char cnt = obj->count;
    char* base;
    unsigned int i;
    int flags;
    flags = 1;
    i = 0;
    if (i < cnt) {
        base = (char*)obj + 8;
        do {
            void* ptr;
            void* p8;
            if (obj == 0) goto zero8;
            if (base == 0) goto zeroptr;
            if (i >= obj->count) goto zeroptr;
            {
                unsigned short off = obj->off;
                unsigned short elemSize = *(unsigned short*)(base + off);
                ptr = base + off + 4 + elemSize * i;
            }
            goto have_ptr;
        zeroptr:
            ptr = 0;
        have_ptr:
            if (ptr != 0) {
                p8 = (char*)obj + *(int*)ptr;
            } else {
            zero8:
                p8 = 0;
            }
            flags &= func_020b3184(p8, ctx);
            flags &= func_020b33f0(p8, ctx);
            i++;
        } while (i < obj->count);
    }
    return flags;
}
