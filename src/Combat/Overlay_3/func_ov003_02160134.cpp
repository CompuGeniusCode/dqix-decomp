#include <globaldefs.h>

struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
struct Obj0207fd00;
void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
extern "C" void func_ov003_02166fc4(void* obj);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Struct020e2794;
void UpdateEntryIfActive020e2794(struct Struct020e2794* self, void* b);
extern "C" void func_ov003_0216039c(void* obj);
struct Obj02167548;
void ProcessBuffersIfActive_02167548(struct Obj02167548* obj);
struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);
void SetEntryPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void func_0205ae8c(void*);

// USA: func_ov003_02160134  (semantic: RefreshCombatantState_02160134)
extern "C" ARM void func_ov003_02160134(char* obj) {
    if (*(unsigned char*)(obj + 0x4a3) == 0) return;

    void* sub = *(void**)(obj + 0x324);
    if (sub != 0) {
        ClearAllBuffers0207fcb8((struct Obj0207fcb8*)sub);
        CallFunc0204c8f0OverEntries0207fd00((struct Obj0207fd00*)sub);
        func_0207fe80(sub, 1, 2, 1);
        CallFunc0204b04cOverList0x2c((struct Cont0207fd44*)sub);
    }
    func_ov003_02166fc4(obj);

    if (*(void**)(obj + 0x390) != 0 && GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(obj + 0x390)) != 0) {
        UpdateEntryIfActive020e2794((struct Struct020e2794*)*(void**)(obj + 0x390), obj + 0x334);
    }
    func_ov003_0216039c(obj);

    if (*(struct Obj02167548**)(obj + 0x318) != 0) {
        ProcessBuffersIfActive_02167548(*(struct Obj02167548**)(obj + 0x318));
    }

    if (!(*(unsigned int*)(obj + 0x464) & 0x2000000)) return;

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x38c);
    SetEntryFlag2ByKey0205a370(cont, 1);

    cont = *(struct Container0205a3d0**)(obj + 0x38c);
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 0);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }

    cont = *(struct Container0205a3d0**)(obj + 0x38c);
    e = FindEntryByHalfword0205a3d0(cont, 1);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) |= 8;
    }

    cont = *(struct Container0205a3d0**)(obj + 0x38c);
    int arg = *(int*)(obj + 0x460);
    IterateEntries0205a330((struct Container0205a330*)cont, arg);

    cont = *(struct Container0205a3d0**)(obj + 0x38c);
    SetEntryPosition(cont, 1, 0xd7, 0x96);

    func_0205ae8c(obj + 0x334);
}
