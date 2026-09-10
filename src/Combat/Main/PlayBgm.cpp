#include <globaldefs.h>

struct Actor0209c73c;
extern "C" void func_0209c73c(struct Actor0209c73c* actor);
extern "C" void func_0203aa44(void* obj);
extern "C" int func_0203aaf8(void* obj, void* arg1, int* out);
struct Obj0203aba8;
extern "C" int func_0203aba8(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void SetBgmVolume(void* obj, int a, int b);

struct Flags0209c3b4 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char rest : 4;
};

struct Actor0209c3b4 {
    char pad0[0xb0];
    int state;               // 0xb0
    int field_b4;             // 0xb4
    short field_b8;             // 0xb8
    short field_ba;               // 0xba
    void* fieldBC;                 // 0xbc
    void* fieldC0;                   // 0xc0
    void* fieldC4;                     // 0xc4
    struct Flags0209c3b4 field_c8;       // 0xc8
    unsigned char field_c9;                // 0xc9
    short field_ca;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char field_cd;                      // 0xcd
    short field_ce;                                // 0xce
};

// Starts a track on the global sound player at 0x02109bf4, the object the curated
// OpenBgmStreamSmallRegion, StopCurrentBgm and RunMapBgmScript also act on. It returns early when
// state is already 1 holding the same id, which is why the id is kept at +0xb8; a non-positive id
// still sets state 1 and stores the id, it only skips the two lookups and SetBgmVolume.
// func_0209c480 drives the same object through state 2 with its own id at +0xba, but state is a
// single field, so whether the two are independent voices is not established.
extern "C" ARM void PlayBgm(struct Actor0209c3b4* actor, int val) {
    if (actor->state == 2) return;
    if (actor->state == 1 && val == actor->field_b8) return;
    if (actor->field_c8.bit2) return;
    if (actor->field_ce > -1) {
        func_0209c73c((struct Actor0209c73c*)actor);
    }
    actor->state = 1;
    func_0203aa44(actor);
    if (val > 0) {
        func_0203aaf8(actor, (void*)val, &actor->field_b4);
        func_0203aba8((struct Obj0203aba8*)actor, (void*)val, &actor->fieldBC);
        SetBgmVolume(actor, actor->field_cd, 0);
    }
    actor->field_b8 = (short)val;
    actor->field_ce = -1;
    actor->field_c8.bit2 = actor->field_c8.bit3;
    actor->field_c8.bit3 = 0;
}
