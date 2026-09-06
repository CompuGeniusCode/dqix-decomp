#include <globaldefs.h>

struct Obj020b1938 {
    void* dest;
    int fieldWidth;
    int count;
    unsigned char format;
    char pad[3];
    int stride;
};

extern "C" void func_020ca458(unsigned int pattern, void* dest, int size);

// USA: func_020b1938
ARM void FillRows020b1938(Obj020b1938* obj, unsigned int color) {
    unsigned int c = color;
    unsigned int packed;
    if (obj->format == 4) {
        packed = c | (c << 4);
        packed = packed | (packed << 8);
    } else {
        packed = c | (c << 8);
    }
    packed = packed | (packed << 0x10);

    int elemBytes = (obj->format << 6) / 8;
    int total = elemBytes * obj->fieldWidth;
    int strideBytes = elemBytes * obj->stride;

    void* dst = obj->dest;
    int i = 0;
    int count = obj->count;
    if (count > 0) {
        do {
            func_020ca458(packed, dst, total);
            dst = (char*)dst + strideBytes;
            i++;
        } while (i < obj->count);
    }
}
