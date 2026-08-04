#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);
void* Zero16Bytes020df828(void* dst);
void ClearFields_021e20c0(void* p);
void InitStruct0205a444(char* obj);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);
void InitFields_021db0d4(void* obj, int flag);
void ClearField784Array3_021dce88(void* obj);

struct DataBlob_021dc134 {
    void* field0;   // 0x0
    int field4;     // 0x4
    void* field8;   // 0x8
    int fieldc;     // 0xc
    int field10;    // 0x10
    void* field14;  // 0x14
    int field18;    // 0x18
    unsigned char pad1c[0x20 - 0x1c];
    void* field20;  // 0x20
    void* field24;  // 0x24
    void* field28;  // 0x28
};
extern struct DataBlob_021dc134 data_ov023_021ff9e0;
extern char data_ov023_021ffa0c;

struct Flags79bByte_021dc134 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
};

// USA: func_ov023_021dc134
extern "C" ARM void func_ov023_021dc134(void* objRaw, short key, int flag) {
    char* obj = (char*)objRaw;

    data_ov023_021ff9e0.field4 = 0;

    ((SafeAllocator*)(obj + 0x0))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x28))->ResetAllocatorPointer();

    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x50) = 0;
    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0x54));

    Zero16Bytes020df828(obj + 0x6c);
    Zero16Bytes020df828(obj + 0x7c);

    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0x8c));
    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0xa4));

    *(int*)(obj + 0xc4) = 0;
    *(int*)(obj + 0xc8) = 0;
    ClearFields_021e20c0(obj + 0xcc);

    *(unsigned char*)(obj + 0x128) = 0;
    *(unsigned char*)(obj + 0x129) = 0;
    InitStruct0205a444(obj + 0x12c);

    for (unsigned char i = 0; i < 30; i++) {
        Init0205a198((struct Struct0205a198*)(obj + 0x180 + i * 0x28));
    }

    memset(obj + 0x630, 0, 0x100);

    *(int*)(obj + 0x730) = 0;
    *(int*)(obj + 0x734) = -1;
    for (int i = 0; i < 7; i++) {
        *(int*)(obj + 0x738 + i * 4) = -1;
    }

    *(int*)(obj + 0x758) = 0;
    *(int*)(obj + 0x75c) = 0;

    *(short*)(obj + 0x770) = key;
    *(short*)(obj + 0x772) = key;
    *(short*)(obj + 0x774) = 0;

    *(unsigned char*)(obj + 0x776) = 0;
    *(unsigned char*)(obj + 0x777) = 0;
    *(unsigned char*)(obj + 0x778) = 0;
    *(signed char*)(obj + 0x779) = -1;
    *(signed char*)(obj + 0x77a) = -1;
    *(signed char*)(obj + 0x79a) = -1;

    ((Flags79bByte_021dc134*)(obj + 0x79b))->bit0 = 0;
    ((Flags79bByte_021dc134*)(obj + 0x79b))->bit1 = 0;

    *(signed char*)(obj + 0x77d) = -1;
    *(unsigned char*)(obj + 0x77e) = 1;
    *(int*)(obj + 0x780) = -1;

    ClearField784Array3_021dce88(obj);

    *(int*)(obj + 0x760) = 0;
    *(int*)(obj + 0x764) = 0;
    *(unsigned char*)(obj + 0x799) = 1;
    *(int*)(obj + 0x768) = 0;
    *(int*)(obj + 0x76c) = 0;

    data_ov023_021ff9e0.field18 = 5;
    data_ov023_021ff9e0.fieldc = 9;
    data_ov023_021ff9e0.field10 = 0;

    *(signed char*)(obj + 0x77b) = (signed char)flag;
    *(unsigned char*)(obj + 0x77c) = 1;

    if (flag == 1) {
        *(unsigned char*)(obj + 0x77c) = 0;
        *(unsigned short*)(obj + 0x774) |= 0x800;
    }

    *(short*)(obj + 0xc2) = 0;
    memset(obj + 0xbc, 0, 6);

    data_ov023_021ff9e0.field14 = obj + 0x54;
    data_ov023_021ff9e0.field24 = obj + 0x6c;
    data_ov023_021ff9e0.field0 = obj + 0x7c;
    data_ov023_021ff9e0.field8 = obj + 0x8c;
    data_ov023_021ff9e0.field28 = obj + 0xa4;
    data_ov023_021ff9e0.field20 = obj;

    *(unsigned short*)(obj + 0x774) |= 8;

    InitFields_021db0d4(&data_ov023_021ffa0c, 0);
}
