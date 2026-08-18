#include <globaldefs.h>

struct BattleStruct;
struct Container0205a3d0;
struct Container0205a330;

struct Entry0205a3d0 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    char pad8[0xd];
    unsigned char f15;
};

struct Obj0218c178 {
    char pad0[0x4c];
    int flags;
    char pad50[0x40];
    struct Container0205a3d0* container;
};

extern "C" struct BattleStruct* _Z15GetBattleStructv(void);
extern "C" void _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(struct Container0205a3d0*, int);
extern "C" struct Entry0205a3d0* _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(struct Container0205a3d0*, int);
extern "C" int _Z19GetBattleScaleCountP12BattleStruct(struct BattleStruct*);
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(struct Container0205a330*, int);
extern "C" void _Z27SetEntryByte14ByKey0205a42cP17Container0205a3d0ii(struct Container0205a3d0*, int, int);
extern "C" void func_0205ae8c(void*);

// USA: func_ov019_0218c178  (semantic: ApplyBattleEntryState_0218c178)
extern "C" ARM void func_ov019_0218c178(struct Obj0218c178* obj) {
    struct BattleStruct* battle = _Z15GetBattleStructv();
    if (obj->flags & 1) {
        struct Container0205a3d0* c = obj->container;
        if (c != NULL) {
            struct Entry0205a3d0* e;
            _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(c, 1);
            e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(c, 1);
            if (e != NULL) {
                e->f15 = e->f15 | 8;
            }
            _Z22IterateEntries0205a330P17Container0205a330i(
                (struct Container0205a330*)c, _Z19GetBattleScaleCountP12BattleStruct(battle));
            e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(c, 1);
            if (e != NULL) {
                e->f4 = 0xd7;
                e->f6 = 0x96;
            }
            _Z27SetEntryByte14ByKey0205a42cP17Container0205a3d0ii(c, 1, 0x24);
        }
        func_0205ae8c((char*)obj + 0x54);
    } else {
        struct Container0205a3d0* c = obj->container;
        if (c != NULL) {
            struct Entry0205a3d0* e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(c, 1);
            if (e != NULL) {
                e->f15 = e->f15 & ~8;
            }
        }
    }
}
