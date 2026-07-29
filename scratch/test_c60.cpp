#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

void* GetFieldPtrAt0x5ca4(void* obj);
void ResetBigStruct02013750(void* obj, int flag);
extern "C" void* func_02012fe4(void);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

struct BigObj_02163c60 {
    char pad[0x4c];
    SafeAllocator* alloc;
    struct Foo0207df50* foo;
};

// USA: func_ov001_02163c60
ARM int ResetFieldAndAllocators_02163c60(void) {
    struct BattleStruct* bs = GetBattleStruct();
    BigObj_02163c60* g = (BigObj_02163c60*)func_02012fe4();
    BigObj_02163c60** slot = (BigObj_02163c60**)GetFieldPtrAt0x5ca4(bs);
    BigObj_02163c60* val = *slot;
    if (val != NULL) {
        ResetBigStruct02013750(val, 1);
        if (val->alloc != NULL) {
            val->alloc->Destroy();
        }
    }
    *slot = NULL;
    SafeAllocator* alloc = g->alloc;
    struct Foo0207df50* foo = g->foo;
    alloc->Reset();
    CopyInternalFields0207df50(foo);
    return 1;
}
