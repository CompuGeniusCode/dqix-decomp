#include <globaldefs.h>

ARM void ReleaseContextPair_022166b4(void);
extern "C" int func_ov031_02216360(void);
ARM void CallWith5Args_02211d54(int, int, int, int, int);
extern "C" int func_ov031_02212ee8(void);
int GetField260_0220d540(void);

struct Entry02211e08 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned char pad1[4];
    unsigned char fieldc;
    unsigned char pad2[3];
    int field10;
};
struct Glob0224e5b4_02211e08 { void* pad0; Entry02211e08* pField; };
extern Glob0224e5b4_02211e08 data_ov031_0224e5b4;

// USA: func_ov031_02211e08  (semantic: BattleQueueDispatch_02211e08)
extern "C" ARM void func_ov031_02211e08(void) {
    if (data_ov031_0224e5b4.pField == 0) return;
    switch (data_ov031_0224e5b4.pField->field10) {
    case 1:
        data_ov031_0224e5b4.pField->field0 = 0;
        data_ov031_0224e5b4.pField->field10 = func_ov031_02216360();
        return;
    case 2: {
        ReleaseContextPair_022166b4();
        char* c = (char*)data_ov031_0224e5b4.pField;
        CallWith5Args_02211d54((int)(c + 0x14), (int)(c + 0x34), *(int*)(c + 0x54), (int)(c + 0x58), 8);
        data_ov031_0224e5b4.pField->field10 = 0;
        return;
    }
    case 3:
        ReleaseContextPair_022166b4();
        data_ov031_0224e5b4.pField->field0 = -1;
        data_ov031_0224e5b4.pField->fieldc = 1;
        return;
    case 4:
    case 5:
        return;
    default:
        break;
    }
    unsigned short f4 = data_ov031_0224e5b4.pField->field4;
    if (f4 == 2) {
        data_ov031_0224e5b4.pField->field0 = func_ov031_02212ee8();
        return;
    }
    if (f4 != 4) return;
    if (data_ov031_0224e5b4.pField->field6 == 0) return;
    if (GetField260_0220d540() == 9) return;
    data_ov031_0224e5b4.pField->field6 = 0;
    data_ov031_0224e5b4.pField->field4 = 6;
}
