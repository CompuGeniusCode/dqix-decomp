#include <globaldefs.h>

extern void* data_02105244;

ARM unsigned char GetEntryByteField0203c284(char* obj);
extern "C" void func_0203c4d0(void*, short, int, int, int, int);

struct Struct0203c1c8 {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    short field14;
};

// USA: func_0203c1c8
ARM void AdjustAndDispatchEntry0203c1c8(Struct0203c1c8* obj) {
    if (data_02105244 == NULL) return;

    unsigned char entryByte = GetEntryByteField0203c284((char*)obj);
    int halved = entryByte >> 1;
    int f0 = obj->field0;
    int f4 = obj->field4;
    int tag = obj->fieldc;

    switch (tag) {
        case 1: f0 -= entryByte; break;
        case 2: f0 -= halved; break;
        case 3: f0 = 0x80 - halved; break;
    }

    func_0203c4d0(data_02105244, (short)obj->field14, obj->field10, f0, f4, obj->field8);
}
