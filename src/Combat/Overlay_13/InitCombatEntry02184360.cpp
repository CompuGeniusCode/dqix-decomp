#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct SubBgControlBackup02074b64;
ARM void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);
struct MainBgControlBackup02074af4;
extern "C" ARM void func_02074af4(struct MainBgControlBackup02074af4* obj);
struct InitTarget0205cfd4;
ARM void InitStruct0205cfd4(struct InitTarget0205cfd4* s);
ARM void InitBigStruct0205c790(char* obj);
struct List0204af64;
ARM void ResetList0204af64(struct List0204af64* obj);
extern "C" void func_0204c684(void* obj);
struct Struct020dfc40;
ARM void ResetStruct020dfc40(Struct020dfc40* p);

struct Block20W02184360 { unsigned int w[20]; };
struct Block16W02184360 { unsigned int w[16]; };

// USA: func_ov013_02184360  (semantic: InitCombatEntry02184360)
extern "C" ARM void func_ov013_02184360(void* entry, void* param) {
    unsigned char* obj = (unsigned char*)entry;
    obj[0x30] = 0;
    obj[0x31] = 0;
    obj[0x640] = (param != 0);

    void* bgObj = obj + 0x20;
    if (*(volatile unsigned char*)(obj + 0x640) != 0) {
        BackupSubBgControlRegisters((SubBgControlBackup02074b64*)bgObj);
        unsigned int v = *(volatile unsigned int*)0x4001000;
        *(int*)(obj + 0x34) = (v & 0x1f00u) >> 8;
    } else {
        func_02074af4((MainBgControlBackup02074af4*)bgObj);
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        unsigned int v = *reg;
        *(int*)(obj + 0x34) = (v & 0x1f00u) >> 8;
        v = *reg;
        *reg = (v & ~0x1f00u) | 0x100u;
    }

    InitStruct0205cfd4((InitTarget0205cfd4*)(obj + 0x38));
    InitBigStruct0205c790((char*)(obj + 0x3d4));

    if (obj[0x640] != 0) {
        unsigned char* src = (unsigned char*)param + 0x188;
        *(Block20W02184360*)(obj + 0x3c) = *(Block20W02184360*)(src + 0x4);
        *(Block16W02184360*)(obj + 0x8c) = *(Block16W02184360*)(src + 0x54);

        obj[0xcc] = src[0x94];
        obj[0xcd] = src[0x95];
        obj[0xce] = src[0x96];
        obj[0xcf] = src[0x97];
        *(unsigned int*)(obj + 0xd0) = *(unsigned int*)(src + 0x98);
        *(unsigned int*)(obj + 0xd4) = *(unsigned int*)(src + 0x9c);
        *(short*)(obj + 0xd8) = *(short*)(src + 0xa0);
        *(short*)(obj + 0xda) = *(short*)(src + 0xa2);
        *(short*)(obj + 0xdc) = *(short*)(src + 0xa4);
        *(short*)(obj + 0xde) = *(short*)(src + 0xa6);
        *(short*)(obj + 0xe0) = *(short*)(src + 0xa8);
        *(short*)(obj + 0xe2) = *(short*)(src + 0xaa);
        *(short*)(obj + 0xe4) = *(short*)(src + 0xac);
        *(short*)(obj + 0xe6) = *(short*)(src + 0xae);
        obj[0xe8] = src[0xb0];
        obj[0xe9] = src[0xb1];
        obj[0xea] = src[0xb2];
        obj[0xeb] = src[0xb3];
        obj[0xec] = src[0xb4];
        obj[0xed] = src[0xb5];
        obj[0xee] = src[0xb6];
        obj[0xef] = src[0xb7];
        obj[0xf0] = src[0xb8];
        obj[0xf1] = src[0xb9];
        obj[0xf2] = src[0xba];
        obj[0xf3] = src[0xbb];
    }

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((List0204af64*)(obj + 0xf4 + i * 0x20));
    }
    for (int i = 0; i < 3; i++) {
        func_0204c684((void*)(obj + 0x134 + i * 0xe0));
    }

    ((SafeAllocator*)(obj + 0x60c))->ResetAllocatorPointer();
    ResetStruct020dfc40((Struct020dfc40*)(obj + 0x620));
    ((SafeAllocator*)obj)->ResetAllocatorPointer();

    for (int i = 0; i < 3; i++) {
        unsigned char* p = obj + i;
        p[0x638] = 0;
    }

    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    *(short*)(obj + 0x1c) = 0xff;
    *(short*)(obj + 0x1e) = 0;
    obj[0x63c] = 0;
    obj[0x63d] = 0;
    obj[0x63e] = 0;
    obj[0x63f] = 0;
    *(int*)(obj + 0x644) = 0;
    *(int*)(obj + 0x648) = 0;
    *(int*)(obj + 0x64c) = 0;
    *(int*)(obj + 0x65c) = 0;
    *(int*)(obj + 0x660) = 0;
    obj[0x664] = 0;
    obj[0x665] = 0;
    *(int*)(obj + 0x668) = 0;
    *(int*)(obj + 0x66c) = 0;
    *(int*)(obj + 0x670) = 0;
    *(int*)(obj + 0x6b0) = 0;
    obj[0x6b4] = 0;
    *(int*)(obj + 0x658) = 0;
    *(int*)(obj + 0x6a4) = 0;
    obj[0x6a8] = 0;
    obj[0x6bc] = 0;
    *(int*)(obj + 0x6b8) = 0;

    unsigned char* base600 = obj + 0x600;
    *(short*)(base600 + 0xbe) = 0;
    *(short*)(base600 + 0xc0) = 0;
    *(short*)(base600 + 0xc2) = 0;
    *(short*)(base600 + 0xc4) = 0;
    *(short*)(base600 + 0xc6) = 0;
    *(short*)(base600 + 0xc8) = 0;
    *(short*)(base600 + 0xca) = 0;

    for (int i = 0; i < 5; i++) {
        *(int*)(obj + 0x674 + i * 4) = 0;
    }
    for (int i = 0; i < 5; i++) {
        *(int*)(obj + 0x688 + i * 4) = 0;
    }
    for (int i = 0; i < 5; i++) {
        unsigned char* p = obj + i;
        p[0x69c] = 1;
    }

    *(int*)(obj + 0x654) = (obj[0x640] != 0) ? *(int*)((unsigned char*)param + 0x178) : 0;

    for (int i = 0; i < 5; i++) {
        unsigned char* p = obj + i;
        p[0x6a9] = 0;
    }
}
