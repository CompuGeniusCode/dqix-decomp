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
    unsigned char field0c = obj->field0c;
    unsigned int sz = size & ~1;
    int val;
    if (field0c != 0) {
        val = ((0xff & 0xf) << 1) + ((idxParam & 0xf) << 9);
    } else {
        val = ((modeParam & 0xf) << 1) + ((idxParam & 0xf) << 5);
    }
    CacheFn0204bc08 fn = data_020f01b0[obj->field1c & 0xf];
    CleanInvalidateCacheRange(addr, sz);
    fn(addr, val, sz);
}
