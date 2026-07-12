#include <globaldefs.h>
#include "std_library_functions.h"

int EncodeStreamValue020dc0b0(int value);
int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
int EncodeStreamValue020dc0c8(int value);

struct Struct0204394c {
    unsigned char pad[0x50];
    unsigned int count : 16;
    unsigned int unused50 : 16;
};

// USA: func_0204394c
ARM int PrepareEncodeStreamBuffer0204394c(struct Struct0204394c* obj) {
    void* buf = (void*)EncodeStreamValue020dc0b0(0x3000);
    if (buf == NULL) {
        return (int)buf;
    }
    int count8 = obj->count * 8;
    memset(buf, 0, 0x3000);
    EncodeStreamFields020dc0e0(1, (int)buf, count8, 0x3000, 1, 0);
    return EncodeStreamValue020dc0c8((int)buf);
}
