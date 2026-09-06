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
    unsigned char format = obj->format;
    unsigned int c = color;
    int i = 0;
    void* dst = obj->dest;
    unsigned int packed;
    if (format == 4) {
        packed = c | (c << 4);
        packed = packed | (packed << 8);
    } else {
        packed = c | (c << 8);
    }
    int elemBytes = (format << 6) / 8;
    packed = packed | (packed << 0x10);
    int stride = obj->stride;
    int fieldWidth = obj->fieldWidth;
    int count = obj->count;
    int strideBytes = elemBytes * stride;
    int total = elemBytes * fieldWidth;
    if (count > 0) {
        do {
            func_020ca458(packed, dst, total);
            dst = (char*)dst + strideBytes;
            i++;
        } while (i < obj->count);
    }
}
