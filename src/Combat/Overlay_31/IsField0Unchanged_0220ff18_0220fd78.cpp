#include <globaldefs.h>

extern "C" int func_ov031_0220fe44(int arg);
ARM int IsField0Unchanged_0220ff18(void* obj);
ARM void WaitForField2CNonZero_0220fea0(void);
ARM void ClearField28SetField2C_0220fed8(void);
ARM int HandleMsgTypeD6_0220fff8(int* obj);

struct Msg_0220fd78 { int f0; int f4; int f8; int fc; int f10; };

extern void* data_ov031_0224e580;

// USA: func_ov031_0220fd78  (semantic: InitMsgAndRegisterD6_0220fd78)
extern "C" ARM void func_ov031_0220fd78(int val, Msg_0220fd78 *msg) {
    msg->f0 = 0x14;
    msg->f4 = 0x44535359;
    msg->f8 = 0xd5;
    msg->fc = 1;
    msg->f10 = val;

    *(int*)((char*)data_ov031_0224e580 + 0x30) = 0;

    if (func_ov031_0220fe44((int)HandleMsgTypeD6_0220fff8) != 0) {
        if (IsField0Unchanged_0220ff18(msg) != 0) {
            WaitForField2CNonZero_0220fea0();
        }
    }
    ClearField28SetField2C_0220fed8();
}
