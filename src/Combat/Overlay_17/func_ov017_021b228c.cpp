#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
struct CombatantStruct;
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

struct Pair021b228c { unsigned int a; unsigned int b; };
extern struct Pair021b228c data_020e6d5c;

struct DispatchEntry021b228c { unsigned int fn; unsigned int locator; };
extern struct DispatchEntry021b228c data_ov017_021d79e0[];

extern int data_ov017_021d83f0;

// USA: func_ov017_021b228c
extern "C" ARM void func_ov017_021b228c(unsigned char* self) {
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(GetBattleStruct());
    if (combatant != NULL) {
        CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    }
    if (!(data_ov017_021d83f0 & 1)) {
        volatile struct Pair021b228c* src = &data_020e6d5c;
        unsigned int a = src->a;
        unsigned int b = src->b;
        unsigned int newFlags = data_ov017_021d83f0 | 1;
        data_ov017_021d79e0[8].fn = a;
        data_ov017_021d79e0[8].locator = b;
        data_ov017_021d83f0 = newFlags;
    }
    int idx = *(int*)(self + 8);
    if (data_ov017_021d79e0[idx].fn == 0) return;
    struct DispatchEntry021b228c* d = &data_ov017_021d79e0[idx];
    volatile unsigned int* fnPtr = &d->fn;
    void* base = self + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + *fnPtr);
    } else {
        callback = (void*)*fnPtr;
    }
    int result = ((int(*)(void*))callback)(base);
    *(int*)(self + 8) = result;
}
