#include <globaldefs.h>

struct Obj02079e60;
typedef int (*CmpFn02079e60)(void*);
extern "C" void* func_02079e60(struct Obj02079e60* obj, int key, CmpFn02079e60 cmp);

struct S020797e8;
extern "C" int func_020797e8(struct S020797e8* p);

// Looks a record up by id in the two act tables the game keeps side by side: func_02079900 fills
// the descriptor at +0x0 from actdt_a_<LG>.nat in data/prm/actdt_a.gp2 and LoadBattleActdtTables fills the
// one at +0xc from actdt_b_<LG>.nat in data/prm/actdt_b.gp2, and the _a table is searched first.
// Records are 0x3c bytes keyed by the 12-bit field at +0x4 and the arrays are sorted, hence the
// binary search. The same pair of loaders puts the actdamage tables at +0x18 and +0x24, which
// func_02079ee0 searches the same way with an 8-bit key.
extern "C" ARM void* FindActdtEntryById(char* p, int key) {
    void* r = func_02079e60((struct Obj02079e60*)p, key, (CmpFn02079e60)func_020797e8);
    if (r != 0) return r;
    return func_02079e60((struct Obj02079e60*)(p + 0xc), key, (CmpFn02079e60)func_020797e8);
}
