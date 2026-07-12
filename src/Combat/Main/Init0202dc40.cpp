#include <globaldefs.h>
#include "System/Memory.h"

struct DataStruct0202dc40 {
    char pad0[0x10];
    int val10;
    char pad14[0x2c - 0x14];
    int val2c;
    int val30;
    int val34;
    int val38;
};
extern struct DataStruct0202dc40 data_021015a0;
extern char data_021016e0;

extern "C" int func_0202d224(void);
int SetState3AndInvokeHandler0202d180(void);

// USA: func_0202dc40
ARM int Init0202dc40(int mode, void* src) {
    data_021015a0.val2c = 0x440;
    data_021015a0.val38 = 0x80;
    data_021015a0.val34 = mode;
    data_021015a0.val10 = 3;
    if (mode == 1 || mode == 3 || mode == 5) {
        VectorizedInvertedMemcpy(src, &data_021016e0, 0xc0);
        if (data_021015a0.val30 != 0) {
            return SetState3AndInvokeHandler0202d180();
        }
        return func_0202d224();
    }
    return 0;
}
