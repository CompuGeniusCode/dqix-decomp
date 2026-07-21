#include <globaldefs.h>

void* AcquireData022918a4_02240310(void);
int ForwardGlobal022918bcZeroZero_022403f4(void);
void ReleaseAllocatorRef_02240324(void);
extern "C" ARM int func_ov031_02240104(void* obj);

struct Session02240ee8 {
    int field0;
    char pad4[0x34];
    int field38;
    char pad3c[4];
    int field40;
};

extern int data_ov031_02290fc0;

#pragma optimize_for_size off
// USA: func_ov031_02240ee8
extern "C" ARM int func_ov031_02240ee8(Session02240ee8* obj) {
    int err;
    if (obj->field0 != 0) {
        err = 0xb;
        data_ov031_02290fc0 = err;
        return err - 0xc;
    }
    if (obj->field40 == 1 && obj->field38 == 0) {
        err = 0xb;
        data_ov031_02290fc0 = err;
        return err - 0xc;
    }
    AcquireData022918a4_02240310();
    int result = func_ov031_02240104(obj);
    if (result >= 0) {
        obj->field0 = 1;
        ForwardGlobal022918bcZeroZero_022403f4();
    } else {
        data_ov031_02290fc0 = 1;
    }
    ReleaseAllocatorRef_02240324();
    return result;
}
