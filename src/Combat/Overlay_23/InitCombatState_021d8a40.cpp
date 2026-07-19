#include <globaldefs.h>
#include "std_library_functions.h"

struct SubBgControlBackup02074b64 {
    char pad0[2];
    volatile unsigned short savedBg0Cnt;
    char pad4[2];
    volatile unsigned short savedBg1Cnt;
    char pad8[2];
    volatile unsigned short savedBg2Cnt;
    char padC[2];
    volatile unsigned short savedBg3Cnt;
    char pad10;
    unsigned char initialized;
};
extern "C" void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

struct InitTarget0205cfd4;
extern "C" void InitStruct0205cfd4(struct InitTarget0205cfd4* s);

struct CombatState_021d8a40 {
    int f0;
    int f4;
    char pad8[0x10];
    char f18;
    char f19;
    int f1c;
    char pad20[0xdc - 0x20];
    int arr[4];
    int fec;
    char pad_f0[0x14];
    char pad104[0x14];
    char f118;
    char f119;
    char f11a;
    char f11b;
    char f11c;
    char f11d;
    char f11e;
    char pad11f;
    int f120;
};

// USA: func_ov023_021d8a40  (semantic: InitCombatState_021d8a40)
extern "C" ARM void func_ov023_021d8a40(struct CombatState_021d8a40* obj) {
    obj->f18 = 0;
    obj->f19 = 0;
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + 8));
    obj->f1c = (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
    obj->f0 = 0;
    obj->f4 = 0;
    InitStruct0205cfd4((struct InitTarget0205cfd4*)((char*)obj + 0x20));
    for (int i = 0; i < 4; i++) {
        obj->arr[i] = 0;
    }
    obj->fec = -1;
    memset((char*)obj + 0xf0, 0, 0x14);
    memset((char*)obj + 0x104, 0, 0x14);
    obj->f118 = 0;
    obj->f119 = 0;
    obj->f11a = 0;
    obj->f11b = 0;
    obj->f11c = 0;
    obj->f11d = 0;
    obj->f120 = 0;
    obj->f11e = 0;
}
