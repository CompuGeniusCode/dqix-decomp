#include <globaldefs.h>

int DispatchNodeIfType7_02156e2c(void* a, int key);
void ClearNodeMaskById_021f6600(void* obj, int id, int mask);

// USA: func_ov004_0215b710  (semantic: ClearNodeMaskIfType7_0215b710)
extern "C" ARM int func_ov004_0215b710(void* obj) {
    int id = DispatchNodeIfType7_02156e2c(obj, 0x65);
    if (id >= 0) {
        ClearNodeMaskById_021f6600(obj, id + 0x38c, 8);
    }
    return 0;
}
