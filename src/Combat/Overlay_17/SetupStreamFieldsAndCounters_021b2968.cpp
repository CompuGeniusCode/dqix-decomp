#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Overlay_17/Struct44C8.h"

int GetData02107800Word0(void);
int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
extern "C" void func_0203b110(void* obj, int value, int frames);
void SetBothCounters(void* obj, int value, int frames);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);

struct Obj021b2968 {
    unsigned char pad0;
    unsigned char flag1;
    char pad2[0x36];
    unsigned int flags0x38;
};

// USA: func_ov017_021b2968  (semantic: SetupStreamFieldsAndCounters_021b2968)
extern "C" ARM int func_ov017_021b2968(struct Obj021b2968* self) {
    Struct_ov017_44C8* oddStruct = func_ov017_0218b5b0();

    unsigned int bit3 = (self->flags0x38 << 28) >> 31;
    if (bit3) {
        void* buf = (void*)GetData02107800Word0();
        memset(buf, 0, 0x800);
        EncodeStreamFields020dc0e0(5, (int)buf, 0, 0x800, 1, 0);
        EncodeStreamFields020dc0e0(7, (int)buf, 0, 0x800, 1, 0);
        EncodeStreamFields020dc0e0(9, (int)buf, 0, 0x800, 1, 0);
        EncodeStreamFields020dc0e0(6, (int)buf, 0, 0x20, 1, 0);
        EncodeStreamFields020dc0e0(8, (int)buf, 0, 0x20, 1, 0);
        EncodeStreamFields020dc0e0(0xa, (int)buf, 0, 0x20, 1, 0);

        struct FlagWord02046708* flagWord = (struct FlagWord02046708*)GetDataPtr02114e04_020d6c00();
        if (!TestFlags02046708(flagWord, 1) && !TestFlags02046708(flagWord, 0x40)) {
            func_0203b110(oddStruct, 0, 0x28);
        } else {
            SetBothCounters(oddStruct, 0, 0x28);
        }
    }

    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
    if (combatant) {
        SetByteField0x253(combatant);
    }

    self->flag1 = 1;
    return 8;
}
