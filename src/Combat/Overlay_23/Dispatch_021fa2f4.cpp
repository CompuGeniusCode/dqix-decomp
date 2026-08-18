#include <globaldefs.h>

struct DispatchEntry_021fea0c { unsigned int fn; unsigned int locator; };
struct Table_021fa2f4 { DispatchEntry_021fea0c e[4]; };

extern int data_ov023_021fff28;
extern struct Table_021fa2f4 data_020e6d5c;
extern DispatchEntry_021fea0c data_ov023_021fea0c;

// USA: func_ov023_021fa2f4
extern "C" ARM int Dispatch_021fa2f4(char* obj) {
    int f = data_ov023_021fff28;
    if (!(f & 1)) {
        unsigned int a0 = data_ov023_021fea0c.fn;
        unsigned int b0 = data_ov023_021fea0c.locator;
        data_020e6d5c.e[3].fn = a0;
        data_020e6d5c.e[3].locator = b0;
        data_ov023_021fff28 = f | 1;
    }
    int idx = *(int*)(obj + 0x1c);
    DispatchEntry_021fea0c* entry = &data_ov023_021fea0c + idx;
    void* base = obj + ((int)entry->locator >> 1);
    int (*callback)(void*);
    if (entry->locator & 1) {
        callback = *(int(**)(void*))((char*)*(void**)base + entry->fn);
    } else {
        callback = (int(*)(void*))entry->fn;
    }
    int result = callback(base);
    *(int*)(obj + 0x1c) = result;
    return result;
}
