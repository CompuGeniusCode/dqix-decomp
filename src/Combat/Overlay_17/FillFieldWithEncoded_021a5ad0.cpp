#include <globaldefs.h>

extern "C" extern int _Z25AllocateVRAMStagingMemoryj(int value);

struct Node0x20_021a5ad0 {
    unsigned char pad[0x14];
    int field14;
    unsigned char pad2[8];
};

// USA: func_ov017_021a5ad0
ARM void FillFieldWithEncoded_021a5ad0(Node0x20_021a5ad0* arr, int count, int val) {
    for (int i = 0; i < count; i++) {
        arr[i].field14 = _Z25AllocateVRAMStagingMemoryj(val);
    }
}
