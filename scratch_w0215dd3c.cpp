#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" signed char func_ov004_02157128(void* obj);
extern "C" int func_ov004_02157a28(void* obj, int val);
extern "C" void func_02052d7c(void* combatant, int arg1, int arg2);
extern "C" void func_0207c378(void* a, int b, int c, int d);

extern unsigned char data_ov004_0216fb20;
extern int data_ov004_0216fc1c;

struct LocalBuf0215dd3c {
    unsigned char table[2];
    unsigned char types[8];
    unsigned char pad[2];
};

struct Packed0215dd3c { unsigned int low4 : 4; unsigned int rest : 28; };

struct FlagsWord0215dd3c {
    unsigned int lowbits : 27;
    unsigned int flag27 : 1;
    unsigned int flag28 : 1;
    unsigned int flag29 : 1;
    unsigned int rest : 2;
};

// USA: func_ov004_0215dd3c  (semantic: DispatchSubStructEntries_0215dd3c)
extern "C" ARM int DispatchSubStructEntries_0215dd3c(void* obj) {
    signed char combatantId = func_ov004_02157128(obj);
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, combatantId);
    if (!combatant) return 0;

    void* ptr2a04 = GetPtrField0x2a04(battleStruct);

    LocalBuf0215dd3c lb;
    unsigned char* src = &data_ov004_0216fb20;
    int cnt = 8;
    unsigned char* dst = lb.types;
    do {
        unsigned char b = *src++;
        cnt--;
        *dst++ = b;
    } while (cnt != 0);

    for (unsigned char i = 0; i < 8; i++) {
        unsigned char type = lb.types[i];
        if (type == 0xff) break;

        char* sub150 = *(char**)((char*)combatant + 0x150);
        void* entry = sub150 + 0x194 + ((int)type << 5);
        if (!(entry != NULL && *(void**)entry != NULL)) continue;

        void* val = *(void**)entry;
        struct FlagsWord0215dd3c* fs = (struct FlagsWord0215dd3c*)((char*)val + 4);
        if (fs->flag29) continue;

        int f27 = (fs->flag27 != 0);
        int f28 = (fs->flag28 != 0);
        lb.table[1] = f28;
        unsigned char someByte = *(unsigned char*)(sub150 + 0x49c);
        lb.table[0] = f27;
        if (lb.table[(unsigned)(someByte << 31) >> 31]) continue;

        func_02052d7c(combatant, ((int*)&data_ov004_0216fc1c)[i], -1);

        if (entry != NULL) {
            struct Packed0215dd3c* packed = (struct Packed0215dd3c*)((char*)entry + 8);
            short amt = *(short*)((char*)entry + 0x18);
            func_0207c378((char*)ptr2a04 + 0x1d4, amt, 1, packed->low4);
        }
    }

    return func_ov004_02157a28(obj, 1);
}
