#include <globaldefs.h>

void CleanInvalidateDataCacheRange(int addr, int size);
void CleanDataCacheRange(int addr, int size);
extern "C" int func_020e12c0(void*);

typedef void (*CacheHookFn020e1384)(int, int, int);
extern CacheHookFn020e1384 data_020f2bb0[];

struct Struct020e1384 {
    int field0;
    int field4;
    char pad8[4];
    int field0xc;
    char pad10[4];
    unsigned char field0x14;
};

// USA: func_020e1384
ARM void RunCacheHookForField0x14(struct Struct020e1384* obj) {
    int result = func_020e12c0(obj);
    if (result == 0) {
        return;
    }
    unsigned char idx = obj->field0x14;
    int base = obj->field0;
    CacheHookFn020e1384 fn = data_020f2bb0[idx];
    if (fn == NULL) {
        return;
    }
    int addr = result + base;
    CleanInvalidateDataCacheRange(addr, obj->field4);
    fn(addr, obj->field0xc, obj->field4);
    CleanDataCacheRange(addr, obj->field4);
}
