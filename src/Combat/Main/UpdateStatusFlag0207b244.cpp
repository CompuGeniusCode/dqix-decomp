#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckBits5To9Equal2(unsigned short* obj);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void* GetPtrField0x114(void* obj);

struct Obj0207b108;
int ScaleByteToPercent0207b108(struct Obj0207b108* obj);
struct Obj0207b154;
int UpdateScaledCounter0207b154(struct Obj0207b154* obj);

struct Obj0207b244 {
    char pad0[0x12];
    unsigned char field0x12;
    unsigned char pad1[1];
    union {
        struct {
            unsigned char pad_0_1 : 2;
            unsigned char bit2 : 1;
            unsigned char pad_3_6 : 4;
            unsigned char bit7 : 1;
        };
        unsigned char raw14;
    };
};

// USA: func_0207b244
ARM void UpdateStatusFlag0207b244(struct Obj0207b244* self) {
    int cond = CheckBits5To9Equal2((unsigned short*)GetPtrField0x114(GetCombatantAtField0x397c(GetBattleStruct())));
    if (cond != self->bit2 || self->bit7) {
        if (cond)
            ScaleByteToPercent0207b108((struct Obj0207b108*)self);
        else
            UpdateScaledCounter0207b154((struct Obj0207b154*)self);
        if (self->bit7) {
            self->field0x12 = 1;
            self->bit7 = 0;
        }
    }
    self->raw14 = (self->raw14 & ~4) | ((unsigned int)cond << 31 >> 29);
}
