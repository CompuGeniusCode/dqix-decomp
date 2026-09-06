#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
int CheckField0x20Positive(int* obj);

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4*);

struct StructAllocGroup0208ba54;
void DestroyStructAllocGroup0208ba54(struct StructAllocGroup0208ba54*);

void ClearBitsInWord(unsigned int* obj, unsigned int mask);

extern "C" void func_0203b19c(int, int, int);
void SetCombatModeFromCase020dc2d0(int);

struct Obj0208d340 {
    char pad0[0xb8];
    int fb8;
    char pad2[0xd5 - 0xbc];
    unsigned char fd5;
    char pad3[0xda - 0xd6];
    unsigned short fda;
};

// USA: func_0208d340
ARM void AdvanceState0208d340(struct Obj0208d340* obj) {
    int val = GetWord0x0((int*)GetBattleStruct());

    if (obj->fd5 == 0) {
        if (!(obj->fda & 0x10)) {
            func_0203b19c(val, -16, 8);
        }
        obj->fd5 = obj->fd5 + 1;
        return;
    }
    if (obj->fd5 == 1) {
        if (CheckField0x20Positive((int*)val) == 0) {
            obj->fd5 = obj->fd5 + 1;
        }
        return;
    }
    if (obj->fd5 == 2) {
        obj->fda = obj->fda & ~4;
        ClearFlag0x11IfSet((struct Struct02074bf4*)((char*)obj + 0x2c));
        SetCombatModeFromCase020dc2d0(0);
        obj->fd5 = obj->fd5 + 1;
        return;
    }
    if (obj->fd5 != 3) return;

    int* reg = (int*)0x4001000;
    *reg = (*reg & ~0x1f00) | (obj->fb8 << 8);
    *(short*)((char*)reg + 0x50) = 0;
    obj->fd5 = obj->fd5 + 1;
    DestroyStructAllocGroup0208ba54((struct StructAllocGroup0208ba54*)obj);
    ClearBitsInWord((unsigned int*)GetWord0x0((int*)GetBattleStruct()), 0x6000);
}
