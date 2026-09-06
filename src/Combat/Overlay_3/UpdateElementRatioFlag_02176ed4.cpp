#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct*);

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);

struct Container020dedd0;
struct Element020de650 {
    char pad[8];
    unsigned int nibble : 4;
};
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);

struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);

extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02176ed4  (semantic: UpdateElementRatioFlag_02176ed4)
extern "C" ARM void func_ov003_02176ed4(char* self) {
    struct Obj2081* elemObj = *(struct Obj2081**)(self + 0x89c);
    struct Obj02086aec* battleSum = (struct Obj02086aec*)GetPtrField0x2a04(GetBattleStruct());
    ClearElementFlag0x20(elemObj, 8);
    SetEntryLowNibbleAndElement02080c68(elemObj, 8, 0);
    int flag = 0;
    struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(self + 0x874), *(short*)(self + 0x103a));
    if (elem != NULL) {
        int t = (elem->nibble <= 7) ? 1 : flag;
        flag = (t != 0);
    }
    if (flag != 0) {
        short key = *(short*)(self + 0x103a);
        int sum = SumCombatantKeyMatches02086aec(battleSum, key);
        SetEntryFirstField02080fa8((struct Container02080fa8*)elemObj, 0x54, sum);
    } else {
        SetElementFlag0x20(elemObj, 8);
    }
    func_020813ec(elemObj, 8);
}
