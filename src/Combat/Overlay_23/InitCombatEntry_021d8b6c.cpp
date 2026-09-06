#include <globaldefs.h>

struct Struct_0205d67c;
int GetFlagB4_0205d67c(Struct_0205d67c*);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);

struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);

struct Cont0205d274;
void CallFunc0204b04cOverList0x98(Cont0205d274*);

struct Obj0205d2bc;
void InitEntries0205d2bc(Obj0205d2bc*);

// USA: func_ov023_021d8b6c
ARM void InitCombatEntry_021d8b6c(void* obj) {
    void* sub = (char*)obj + 0x20;
    if (GetFlagB4_0205d67c((Struct_0205d67c*)sub)) {
        ResetEntryList0205d6a0((Entry_0205d6a0*)sub, 1);
    }
    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)sub);
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)sub);
    CallFunc0204b04cOverList0x98((Cont0205d274*)sub);
    InitEntries0205d2bc((Obj0205d2bc*)sub);
}
