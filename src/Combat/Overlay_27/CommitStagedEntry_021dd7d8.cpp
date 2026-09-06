#include <globaldefs.h>
#include "System/Memory.h"

struct Ctx021dd7d8 {
    unsigned char pad0[4];
    char* arr;
    unsigned int elemSize;
    int count;
};

extern Ctx021dd7d8 data_ov027_021e3424;

extern "C" int func_ov027_021dd864(int id);

// USA: func_ov027_021dd7d8  (semantic: CommitStagedEntry_021dd7d8)
#pragma optimize_for_size off
extern "C" ARM void* func_ov027_021dd7d8(unsigned char* dst, int id) {
    if (data_ov027_021e3424.arr == 0) return 0;
    unsigned char field1 = dst[2];
    if (field1 > data_ov027_021e3424.count) return 0;
    int idx = id - 1;
    unsigned int elemSize = data_ov027_021e3424.elemSize;
    void* slot = data_ov027_021e3424.arr + idx * 0x20 + field1 * elemSize;
    VectorizedInvertedMemcpy(dst + 3, slot, elemSize);
    int* bits = (int*)(data_ov027_021e3424.arr + 0x1e0);
    bits[idx] |= (1 << field1);
    if (!func_ov027_021dd864(id)) return 0;
    return data_ov027_021e3424.arr + idx * 0x20;
}
