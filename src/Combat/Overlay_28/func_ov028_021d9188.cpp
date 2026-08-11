#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
int TransferSubBg1CharData(int arg0, int arg1, unsigned int arg2);

struct Obj9188 {
    char pad0[0x40];
    void* field40;
    char pad44[0x60 - 0x44];
    int f60;
    char pad64[0x6e - 0x64];
    unsigned char f6e;
    char pad6f[0x80 - 0x6f];
    unsigned char f80;
};

// USA: func_ov028_021d9188
extern "C" ARM void func_ov028_021d9188(Obj9188* obj) {
    if (obj->f80 == 0 || obj->field40 == 0) return;
    *(volatile unsigned int*)0x4001014 = (((obj->f60 >> 12) & 0xff) << 16) & 0x1ff0000;
    if (obj->f6e != 0) {
        CleanInvalidateCacheRange(obj->field40, 0x8000);
        TransferSubBg1CharData((int)obj->field40, 0, 0x8000);
        CleanCacheRange(obj->field40, 0x8000);
    }
    obj->f6e = 0;
}
