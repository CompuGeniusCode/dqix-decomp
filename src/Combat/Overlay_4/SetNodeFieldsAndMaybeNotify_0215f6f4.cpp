#include <globaldefs.h>

void* CheckNodeState6_0215e4c0(void* a, int key);
struct ObjE2_021f8944;
void SetFieldE2AndMaybeCall_021f8944(struct ObjE2_021f8944* obj, int a1, int a2, int a3);

// USA: func_ov004_0215f6f4
ARM void SetNodeFieldsAndMaybeNotify_0215f6f4(void* a, short v1, short v2, int flag) {
    void* node = CheckNodeState6_0215e4c0(a, 3);
    if (node == NULL) return;
    *(short*)((char*)node + 0x104) = v1;
    *(short*)((char*)node + 0x106) = v2;
    int a2 = 0;
    unsigned char flagByte = 0xf;
    if (flag != 0) {
        flagByte = 3;
        a2 = 1;
    }
    *(unsigned char*)((char*)node + 0x10a) = flagByte;
    SetFieldE2AndMaybeCall_021f8944((struct ObjE2_021f8944*)node, (int)(long)a, a2, 0);
}
