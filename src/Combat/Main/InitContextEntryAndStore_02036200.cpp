#include <globaldefs.h>

extern "C" void* func_020362e4(void* obj, int arg2);
extern "C" int func_0207e090(void* context, void* field8, int arg2, int arg4);

void ResetStreamContext02037138(unsigned char* obj);
int StoreValueIfNonZero(int* dst, int value);
void InitFieldsWithScale0x1000(int* obj);

struct SubStruct_02036200 {
    char pad[0x4];
    char* base;
};

struct Cache_02036200 {
    char pad[0x24];
    SubStruct_02036200* sub;
};

struct Obj_02036200 {
    char pad[0x8];
    void* field8;
    Cache_02036200* cache;
};

// USA: func_02036200  (semantic: InitContextEntryAndStore_02036200)
extern "C" ARM void func_02036200(struct Obj_02036200* obj, int arg1, int arg2, int arg3) {
    Cache_02036200* cache;
    char* context;
    if (obj->field8 == 0 || arg2 == 0 || arg3 == 0) {
        return;
    }
    cache = obj->cache;
    if (cache == 0) {
        obj->cache = (Cache_02036200*)func_020362e4(obj, arg2);
        cache = obj->cache;
        if (cache == 0) {
            return;
        }
    }
    context = cache->sub->base + (arg1 << 4);
    ResetStreamContext02037138((unsigned char*)obj);
    InitFieldsWithScale0x1000((int*)context);
    if (StoreValueIfNonZero((int*)context, arg3) == 0) {
        return;
    }
    if (func_0207e090(context, obj->field8, arg2, 0) == 0) {
        return;
    }
    return;
}
