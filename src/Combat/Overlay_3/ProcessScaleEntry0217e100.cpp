#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementForFieldB0(Struct_0205d81c*);

int CheckField0x9cSetWhenField0xd4Present(unsigned char*);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(Struct_0205c570*);

struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);

struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);

unsigned int GetBattleScaleCount(struct BattleStruct*);

extern "C" void func_0205ae8c(void*);

// USA: func_ov003_0217e100
ARM void ProcessScaleEntry0217e100(void* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* sub = *(void**)((char*)obj + 0x90);
    Elem_0205d81c* elem = FindElementForFieldB0((Struct_0205d81c*)sub);
    if (elem == NULL) return;
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) return;

    sub = *(void**)((char*)obj + 0x90);
    short a = *(short*)((char*)elem + 0xae);
    short c = *(short*)((char*)elem + 0xac);
    int field68 = *(int*)((char*)sub + 0x68);
    short d = a << 3;

    int e = GetActiveScaledSum0205d794((Struct_0205c570*)sub);
    short g = (short)e - field68 * 6;
    short comp = (short)((int)g * 13 + d);

    Container0205a3d0* cont = *(Container0205a3d0**)((char*)obj + 0x78);
    if (cont == NULL) return;

    SetEntryFlag2ByKey0205a370(cont, 0);
    Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(cont, 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= 8;
    }

    int scaleCount = (int)GetBattleScaleCount(battleStruct);
    IterateEntries0205a330((Container0205a330*)cont, scaleCount);

    entry = FindEntryByHalfword0205a3d0(cont, 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = (short)((int)c << 3) - 4;
        *(short*)((char*)entry + 0x6) = comp + 2;
    }

    func_0205ae8c((char*)obj + 0x3c);
}
