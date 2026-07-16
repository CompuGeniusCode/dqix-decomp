#include <globaldefs.h>

extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);

// USA: func_ov004_02157874
ARM void MaskNodesForRange_02157874(void* obj) {
    for (int i = 0; i < 4; i++) {
        func_ov023_021f65d4(obj, i + 0x29, 8);
    }
}
