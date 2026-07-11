#include <globaldefs.h>

void CleanInvalidateDataCacheRange(int addr, int size);
void CleanDataCacheRange(int addr, int size);
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
            CleanInvalidateDataCacheRange(base + addend, obj->field_4);
            cb(base + addend, obj->field_0, obj->field_10);
            CleanDataCacheRange(base + addend, obj->field_4);
        }
    }
}
