#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
void ResetFieldWithLog_0218d5c8(unsigned char* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void SetField0x238True(void* obj);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

extern int data_02114e20;

struct Obj_021ae760 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad1[9];
    unsigned char fieldB;
    unsigned char pad2[0x20];
    SafeAllocator allocator;
};

// USA: func_ov017_021ae760
extern "C" ARM void func_ov017_021ae760(struct Obj_021ae760* self) {
    void* h = func_ov017_0218b5b0();
    self->field1 = 1;
    unsigned char flag = self->fieldB;
    if (flag != 0 && h != NULL) {
        ResetFieldWithLog_0218d5c8((unsigned char*)h);
        void* p = self->allocator.GetSignedAllocator();
        if (p != NULL) {
            self->allocator.Destroy();
            TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
        }
        self->fieldB = 0;
    }

    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantAtField0x397c(bs);
    if (c != NULL) {
        SetByteField0x253(c);
    }
    int flagResult = GetFieldIfFlag4((char*)bs);
    if (flagResult != 0) {
        SetField0x238True((void*)flagResult);
    }

    if (h == NULL) return;
    ClearBitsInField4((unsigned int*)h, 0x80);
}
