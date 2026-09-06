#include <globaldefs.h>

extern "C" void CleanInvalidateCacheRange(const void* p, unsigned int size);
typedef void (*CacheFn0204bc08)(void*, int, unsigned int);
extern CacheFn0204bc08 data_020f01b0[];

struct Obj0204bc08 {
    char pad0[0xc];
    unsigned char field0c;
    char pad_d[0x1c - 0xc - 1];
    unsigned char field1c;
};

// USA: func_0204bc08
ARM void DispatchCacheOp0204bc08(Obj0204bc08* obj, int idxParam, int modeParam, void* addr, unsigned int size) {
    unsigned char field1c = obj->field1c;
    unsigned char field0c = obj->field0c;
    int shift = 5;
    if (field0c != 0) {
        modeParam = 0xff;
        shift = 9;
    }
    unsigned int sz = size & ~1;
    int val = ((modeParam & 0xf) << 1) + ((idxParam & 0xf) << shift);
    CacheFn0204bc08 fn = data_020f01b0[field1c & 0xf];
    CleanInvalidateCacheRange(addr, sz);
    fn(addr, val, sz);
}
