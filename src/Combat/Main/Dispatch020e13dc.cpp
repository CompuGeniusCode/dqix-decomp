#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" int func_020e12c0(void* p);

typedef void (*Callback020e13dc)(int, int, int);
extern Callback020e13dc data_020f2bb0[];

struct Desc020e13dc {
    int field_0;
    int field_4;
    unsigned char field_8;
    int field_c;
    int field_10;
    unsigned char field_14;
};

// USA: func_020e13dc
ARM void Dispatch020e13dc(Desc020e13dc* obj) {
    int base = func_020e12c0(&obj->field_c);
    if (base) {
        Callback020e13dc cb = data_020f2bb0[obj->field_8];
        int addend = obj->field_c;
        if (cb) {
            CleanInvalidateCacheRange((const void*)(base + addend), obj->field_4);
            cb(base + addend, obj->field_0, obj->field_10);
            CleanCacheRange((const void*)(base + addend), obj->field_4);
        }
    }
}
