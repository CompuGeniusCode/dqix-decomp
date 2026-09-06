#include <globaldefs.h>

struct BattleStruct;
struct CombatantStruct;
struct FlagWord020466f4;
struct HeadNode02046b24;
struct Obj020397cc;

struct BattleStruct* GetBattleStruct();
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
void* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
extern "C" void func_ov017_02199780(void* obj);

// USA: func_ov017_02199e98
ARM void CancelActionIfHeadIdMatches_02199e98(void* obj) {
    if (*(int*)((char*)obj + 0x4000 + 0x80) == 0) return;
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(GetBattleStruct());
    SetByteField0x253(combatant);
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x400);
    func_ov017_02199780(obj);
    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)((char*)obj + 0x3000 + 0x6fc);
    int id = GetHeadNodeIdOrMinusOne(list);
    if (id != 0xa && id != 4 && id != 3 && id != 0x21 && id != 0x24) return;
    CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
}
