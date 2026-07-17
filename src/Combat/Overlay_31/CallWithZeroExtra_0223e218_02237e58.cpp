#include <globaldefs.h>

void TailCallField4_0223e2c0(int, int);
ARM void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
void IncrementByteAndMaybeCall_022384bc(void);

struct Struct02237e58 { unsigned char pad[0x14]; int field14; };
extern Struct02237e58* data_ov031_02290d10;

// USA: func_ov031_02237e58
ARM void SetupField14_02237e58(void) {
    TailCallField4_0223e2c0(0, data_ov031_02290d10->field14);
    data_ov031_02290d10->field14 = (int)CallWithZeroExtra_0223e218((void*)1, (void*)IncrementByteAndMaybeCall_022384bc, (void*)0, 0x78);
}
