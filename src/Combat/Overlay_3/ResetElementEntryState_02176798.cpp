#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct*);
struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02176798  (semantic: ResetElementEntryState_02176798)
extern "C" ARM void func_ov003_02176798(char* obj) {
    void* f2a04 = GetPtrField0x2a04(GetBattleStruct());
    struct Obj2081* o = *(struct Obj2081**)(obj + 0x89c);
    ClearElementFlag0x20(o, 0);
    SetEntryLowNibbleAndElement02080c68(o, 0, 0);
    int f = *(int*)((char*)f2a04 + 0xf6c);
    SetEntryFirstField02080fa8((struct Container02080fa8*)o, 0, f);
    func_020813ec(o, 0);
}
