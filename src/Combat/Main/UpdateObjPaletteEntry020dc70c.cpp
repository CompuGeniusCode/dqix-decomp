#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "System/Cache.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern int GetFieldAt0x150(unsigned char* obj);
extern void* GetData02109dcc(void);

int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2);
void CopyToPaletteA(int src, int dstOffset, unsigned int size);
int TransferSubObjPalette(int arg0, int arg1, unsigned int arg2);
void CopyToPaletteB(int src, int dstOffset, unsigned int size);

// USA: func_020dc70c
ARM void UpdateObjPaletteEntry020dc70c(int id, int p1, int p2, int p3, unsigned short p4, unsigned short p5, unsigned int count) {
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, id);
    if (c == NULL)
        return;
    int monster = GetFieldAt0x150((unsigned char*)c);
    if (monster == 0)
        return;
    unsigned char idx = *(unsigned char*)(monster + 0x56a);
    unsigned int off = (p4 << 4) + p5;
    unsigned int end = count + (off << 1);
    if (end > 0x200)
        return;
    unsigned int size = off << 1;
    int base = (int)GetData02109dcc();
    int src = base + (idx << 5) + (p1 << 1);
    CleanInvalidateCacheRange((void*)src, count);
    if (p2 == 0) {
        if (p3 != 0)
            TransferMainObjPalette(src, size, count);
        else
            CopyToPaletteA(src, size, count);
    } else {
        if (p3 != 0)
            TransferSubObjPalette(src, size, count);
        else
            CopyToPaletteB(src, size, count);
    }
    *(int*)((unsigned char*)GetBattleStruct() + 0x5000 + 0xccc) &= ~2;
}
