#include <globaldefs.h>

typedef void (*IterFn020a8f70)(void*, void*);

struct Obj020a8f70 {
    unsigned int count : 12;
    char* base;
};

#pragma optimize_for_size off

// USA: func_020a8f70
ARM int ForEachElement020a8f70(struct Obj020a8f70* obj, IterFn020a8f70 fn) {
    int count;
    char* p;
    int i;
    p = obj->base;
    if (p != 0) {
        count = obj->count;
        if (count != 0 && fn != 0) {
            i = 0;
            while (i < count) {
                fn(obj, p);
                i++;
                p += 64;
            }
            return 1;
        }
    }
    return 0;
}
