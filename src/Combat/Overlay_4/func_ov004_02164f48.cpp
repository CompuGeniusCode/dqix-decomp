#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "System/Memory.h"
#include "System/Timing.h"
#include "std_library_functions.h"

struct Info02011930 {
    unsigned char b0;
    unsigned char b1;
    unsigned short s0;
};
unsigned char GetAndConsumeNameEntries02011930(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern char* data_ov004_02171010;
extern "C" void* func_02012fe4(void);
struct Elem020985ec {
    unsigned char pad0[0x10];
    unsigned int key;
    unsigned char pad1[0xd4];
};
struct Elem020985ec* FindElementByShiftedField0x10(struct Elem020985ec* arr, int val);

// USA: func_ov004_02164f48  (semantic: GenerateTreasureMapEntry_02164f48)
extern "C" ARM int func_ov004_02164f48(void* a1) {
    char* battle = (char*)GetBattleStruct();
    struct Info02011930 info;
    char name1buf[0xa];
    char name2buf[0xa];
    name1buf[0] = 0;
    name2buf[0] = 0;

    if (GetAndConsumeNameEntries02011930(battle, &info, name1buf, name2buf) != 0) {
        func_ov011_021848a0(a1, 0x69);

        srand(GetMain16BitTimerCounter());

        char* arr = data_ov004_02171010;
        unsigned char cnt = *(unsigned char*)(arr + 0x1000 + 0x8f4);
        TreasureMapMetadata* meta = (TreasureMapMetadata*)(arr + cnt * 0x1c);

        if (info.b0 == 1) {
            meta->InitialiseAsNonLegacyMap(info.b1, info.s0);
        } else if (info.b0 == 2) {
            meta->InitialiseAsLegacyBossMap(info.b1, info.s0 & 0xff);
            unsigned short seedOverride = *(unsigned short*)(battle + 0x6400 + 0x7e);
            if (seedOverride != 0) meta->SeedOrMinTurns = seedOverride;
        } else {
            meta->InitialiseAsNonLegacyMap(0, 0);
        }

        if (name1buf[0] != 0) {
            VectorizedInvertedMemcpy(name1buf, (char*)meta + 1, 0xa);
        } else {
            *((char*)meta + 1) = 0;
        }
        if (name2buf[0] != 0) {
            VectorizedInvertedMemcpy(name2buf, (char*)meta + 0xb, 0xa);
        } else {
            *((char*)meta + 0xb) = 0;
        }

        int locVal = *(int*)(battle + 0x6000 + 0x478);
        if (locVal != -1) meta->Location = (unsigned char)locVal;
        unsigned char flagsVal = *(unsigned char*)(battle + 0x6000 + 0x47c);
        if (flagsVal != 0) meta->TreasureDiscoveryFlags = flagsVal;

        unsigned char* arr2 = (unsigned char*)data_ov004_02171010;
        *(arr2 + 0x1000 + 0x8f4) = *(arr2 + 0x1000 + 0x8f4) + 1;

        int questIdx = *(int*)(battle + 0x6000 + 0x474);
        if (questIdx >= 0) {
            struct Elem020985ec* base = (struct Elem020985ec*)((char*)func_02012fe4() + 0x840);
            struct Elem020985ec* elem = FindElementByShiftedField0x10(base, questIdx);
            if (elem) {
                ((unsigned char*)elem)[0xb] &= ~0x80;
            }
        }
        *(int*)(battle + 0x6000 + 0x474) = -1;
    } else {
        func_ov011_021848a0(a1, 0x69);
    }
    return 0;
}
