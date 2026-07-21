#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

int GetData02104304Field4();
extern "C" int func_0202fdd0(int a, int b);
int GetFieldAt0x150(unsigned char* obj);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
void* Clear12Bytes(void* dst);

struct BitField0209a088;
struct Obj0209a088 {
    char pad[0xc];
};
void InitObjFromSource0209a088(struct Obj0209a088* obj, struct BitField0209a088* src);

void* BinarySearchRecord0209a004(void* list, int key);

extern "C" void func_020301c8(int a, int b);
extern "C" void func_02083e28(void* a, int arg2);

extern unsigned char data_ov017_021d6b20;

struct Record_021b3780 {
    unsigned int words[10]; // 0x00
    short id;                // 0x28
    char pad2a[2];
};

struct Ctx_021b3780 {
    char pad0[0x8];
    short combatantId;   // 0x8
    char pad1[6];
    int listKey;         // 0x10
};

// USA: func_ov017_021b3780
extern "C" ARM int func_ov017_021b3780(struct Ctx_021b3780* ctx) {
    struct BattleStruct* battle = GetBattleStruct();
    int loadedList = GetData02104304Field4();
    if (!func_0202fdd0(loadedList, ctx->listKey)) {
        return 0;
    }
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battle, ctx->combatantId);
    if (!combatant) {
        return 0;
    }
    int base150 = GetFieldAt0x150((unsigned char*)combatant);
    if (!base150) {
        return 0;
    }

    int key = ctx->listKey;
    int val1;
    volatile int val2;
    GetListEntryValues0202fec8((struct List0202fec8*)loadedList, key, &val1, (int*)&val2);

    struct Obj0209a088 obj;
    Clear12Bytes(&obj);
    int unused = val2;
    InitObjFromSource0209a088(&obj, (struct BitField0209a088*)val1);

    struct Record_021b3780* rec = (struct Record_021b3780*)(*(char**)((char*)combatant + 0x150) + 0x2f4);
    unsigned char* table = &data_ov017_021d6b20;
    int i;
    for (i = 0; i < 8; i++, table++, rec++) {
        rec->words[0] = 0;
        rec->words[1] = 0;
        rec->words[2] = 0;
        rec->words[3] = 0;
        rec->words[4] = 0;
        rec->words[5] = 0;
        rec->words[6] = 0;
        rec->words[7] = 0;
        rec->words[8] = 0;
        rec->words[9] = 0;
        rec->id = -1;

        unsigned char idx = *table;
        short threshold = *(short*)((char*)base150 + idx * 0x20 + 0x100 + 0xac);
        if (threshold > 0) {
            void* found = BinarySearchRecord0209a004(&obj, threshold);
            if (found) {
                memcpy(rec, found, 0x2c);
            }
        }
    }

    func_020301c8(loadedList, key);
    ctx->listKey = -1;
    func_02083e28((void*)base150, 0);
    return 1;
}
