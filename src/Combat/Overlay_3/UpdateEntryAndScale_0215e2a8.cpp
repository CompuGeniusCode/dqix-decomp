#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementForFieldB0(Struct_0205d81c*);
int CheckField0x9cSetWhenField0xd4Present(unsigned char*);
int GetGlobalField0x1c020421a0(void);

struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);

struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);

unsigned int GetBattleScaleCount(struct BattleStruct*);
void SetEntryByte14ByKey0205a42c(Container0205a3d0*, int, int);
extern "C" void func_0205ae8c(void*);

// USA: func_ov003_0215e2a8
ARM void UpdateEntryAndScale_0215e2a8(char* base) {
    if (*(unsigned char*)(base + 0x3c2) == 0) return;

    Elem_0205d81c* elem = FindElementForFieldB0((Struct_0205d81c*)(base + 0x98));
    if (elem == NULL) return;
    if (*(unsigned char*)((char*)elem + 0xc4) != 1) return;
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) return;
    if (*(unsigned char*)((char*)elem + 0xc5) & 0x20) return;

    short a = *(short*)((char*)elem + 0xac);
    short b = *(short*)((char*)elem + 0xae);
    short d = *(short*)((char*)elem + 0xbc);
    short e = *(short*)((char*)elem + 0xbe);

    short x = (short)(d + (short)((a << 3)));
    short y = (short)(e + (short)((b << 3)));
    x = (short)(x - 8);
    y = (short)(y - 2);

    if (*(unsigned char*)(base + 0x3f2) != 0) {
        int f = GetGlobalField0x1c020421a0();
        int v = *(short*)((char*)f + 0x900 + 0x16);
        x = (short)(x - 2);
        y = (short)(y + (short)(v % 8));
    }

    struct BattleStruct* battleStruct = GetBattleStruct();
    Container0205a3d0* cont = *(Container0205a3d0**)(base + 0x394);
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
        *(short*)((char*)entry + 0x4) = x;
        *(short*)((char*)entry + 0x6) = y;
    }

    SetEntryByte14ByKey0205a42c(cont, 0, 0x3f);
    func_0205ae8c(base + 0x358);
}
