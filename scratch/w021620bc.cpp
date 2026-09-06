#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv(void);
extern "C" void* _Z20GetField0x3f8AddressP12BattleStruct(void* battle);
extern "C" void* func_02012fe4(void);
extern "C" void _Z8CopyVec3PiS_(int* dst, int* src);
extern "C" void _Z18InitStruct02070378Pc(void* obj);
extern "C" void _Z28CallFunc0200fbb4AtField0x3f8Pv(void* battle, void* obj);

struct S02012fe4 {
    char pad[0x23bb];
    signed char byteAt23bb;
    char pad2[4];
    int vec[3];
    short shortAt23cc;
};

struct S3f8 {
    short field0;
    char field2;
    char pad1[4];
    char field7;
    char pad2[8];
    int vec10[3];
    short field1c;
    char pad3[0x68 - 0x1e];
    char field68;
};

// USA: func_ov001_021620bc
ARM int func_ov001_021620bc(void) {
    int tmpVec[3];
    void* battle = _Z15GetBattleStructv();
    struct S3f8* obj = (struct S3f8*)_Z20GetField0x3f8AddressP12BattleStruct(battle);
    struct S02012fe4* data = (struct S02012fe4*)func_02012fe4();
    _Z8CopyVec3PiS_(tmpVec, data->vec);
    short shortCc = data->shortAt23cc;
    _Z18InitStruct02070378Pc(obj);
    obj->field2 = 1;
    obj->field7 = 1;
    obj->field0 = (short)(data->byteAt23bb + 0x1c40 + 0x8000);
    _Z8CopyVec3PiS_(obj->vec10, tmpVec);
    obj->field1c = shortCc;
    obj->field68 = 1;
    _Z28CallFunc0200fbb4AtField0x3f8Pv(battle, obj);
    return 1;
}
