#include <globaldefs.h>

extern "C" void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021c9168 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char pad6;
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    unsigned short field8;
    unsigned short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c9168
ARM void EnqueueCombatantFieldsEvent_021c9168(unsigned short a0, unsigned char a1, int a2, unsigned short a3,
        int s0, int s1, int s2, int s3, int s4, int s5, int s6) {
    void* p = GetData02100044();
    unsigned char buf[0x14];
    volatile LocalEvt021c9168* evt = (volatile LocalEvt021c9168*)buf;
    evt->lowNibble = a1;
    evt->tag = 0x84;
    evt->field4 = a0;
    evt->highNibble = (signed char)s6;
    evt->fieldC = s0;
    evt->field10 = s2;
    evt->fieldA = s4;
    evt->field8 = a3;
    func_0205e330(p, buf, 0);
}
