#include <globaldefs.h>

extern int EncodeStreamValue020dc0b0(int value);

struct Node0x20_021a5ad0 {
    unsigned char pad[0x14];
    int field14;
    unsigned char pad2[8];
};

// USA: func_ov017_021a5ad0
ARM void FillFieldWithEncoded_021a5ad0(Node0x20_021a5ad0* arr, int count, int val) {
    for (int i = 0; i < count; i++) {
        arr[i].field14 = EncodeStreamValue020dc0b0(val);
    }
}
