#include <globaldefs.h>
#include "std_library_functions.h"

struct BufferField8_02097418;
ARM void* GetBufferField8(struct BufferField8_02097418* obj);

struct Field4Low12_02097420;
ARM int GetField4Low12(struct Field4Low12_02097420* obj);

struct KeyedEntry_02188a8c {
    char pad0[0xc];
    short f0c;
    char pad_e[5];
    unsigned char bit0_13:1;
    unsigned char active13:1;
    unsigned char restBits13:6;
    char pad_14[6];
    short f1a;
    char pad_1c[4];
};

// USA: func_ov014_02188a8c  (semantic: FindAndSetByKey_02188a8c)
extern "C" ARM void func_ov014_02188a8c(void* self, short key) {
    KeyedEntry_02188a8c* arr = (KeyedEntry_02188a8c*)GetBufferField8((struct BufferField8_02097418*)((char*)self + 0xa4));
    if (!arr) {
        return;
    }
    int count = GetField4Low12((struct Field4Low12_02097420*)((char*)self + 0xa4));
    if (!count) {
        return;
    }
    memset((char*)self + 0x182, 0, 0x10);
    int i = 0;
    while (i < count) {
        if (arr) {
            if (arr->active13) {
                if (arr->f1a == key) {
                    *(short*)((char*)self + 0x182) = arr->f0c;
                    return;
                }
            }
        }
        i++;
        arr = (KeyedEntry_02188a8c*)((char*)arr + 0x20);
    }
}
