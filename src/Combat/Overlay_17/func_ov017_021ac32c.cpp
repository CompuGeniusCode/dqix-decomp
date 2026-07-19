#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Combat/Main/BattleList.h"

extern "C" void func_02094ab0(void);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(void* self);
int GetGlobal02109400(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void ClearFlagBits(unsigned char* obj, int mask);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c(void);

extern int data_02114e20;

struct Obj021ac32c {
    char pad0[0xc];
    int field0xc;
    SafeAllocator allocator;
};

// USA: func_ov017_021ac32c
extern "C" ARM void func_ov017_021ac32c(struct Obj021ac32c* self) {
    void* ctrl = (void*)GetGlobalField0x1c020421a0();
    ReinitController02043204((char*)ctrl);
    func_02043124(ctrl);
    GetGlobal02109400();
    func_02094ab0();
    struct BattleStruct* battle = GetBattleStruct();
    SetByteField0x253(GetCombatantAtField0x397c(battle));

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
        func_020a0c0c();
    }
    self->field0xc = 0;
    int flag = GetFieldIfFlag4((char*)battle);
    if (flag == 0) return;
    ClearFlagBits((unsigned char*)flag, 3);
}
