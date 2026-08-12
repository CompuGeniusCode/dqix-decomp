#include <globaldefs.h>

struct BattleStruct;
ARM struct BattleStruct* GetBattleStruct(void);
ARM unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
void SetEntryPosition(struct Container0205a3d0* c, int key, short a, short b);
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);

struct Struct0200fb08;
int NormalizeField5_0200fb08(struct Struct0200fb08*);

extern "C" void func_0205ae8c(void* obj);

// USA: func_ov003_0216ddfc  (semantic: UpdateEntryOnFlag_0216ddfc)
extern "C" ARM void func_ov003_0216ddfc(char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    if (*(unsigned char*)(obj + 0x1000 + 0x3ec) & 4) {
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + 0x2a8);
        if (cont != 0) {
            SetEntryFlag2ByKey0205a370(cont, 1);
            struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 1);
            if (e != 0) {
                *(unsigned char*)((char*)e + 0x15) |= 8;
            }
            IterateEntries0205a330((struct Container0205a330*)cont, GetBattleScaleCount(battle));
            SetEntryPosition(cont, 1, 0xdf, 0x96);
            SetEntryByte14ByKey0205a42c(cont, 1, 0x10);
            if (NormalizeField5_0200fb08((struct Struct0200fb08*)GetBattleStruct()) == 3) {
                SetEntryPosition(cont, 1, 0xd7, 0x96);
            }
        }
        func_0205ae8c(obj + 0x126c);
        return;
    }

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + 0x2a8);
    if (cont == 0) return;
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 1);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
