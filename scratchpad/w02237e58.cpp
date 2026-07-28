#include <globaldefs.h>

struct Struct02237e58 { unsigned char pad[0x14]; void* field14; };
extern Struct02237e58* data_ov031_02290d10;

extern "C" void func_ov031_0223e2c0(int idx, void* obj);
ARM void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
ARM void IncrementByteAndMaybeCall_022384bc(int a);

// USA: func_ov031_02237e58
ARM void ReregisterIncrementCallback_02237e58(void) {
    func_ov031_0223e2c0(0, data_ov031_02290d10->field14);
    data_ov031_02290d10->field14 = CallWithZeroExtra_0223e218(
        (void*)1, (void*)IncrementByteAndMaybeCall_022384bc, 0, 0x78);
}
