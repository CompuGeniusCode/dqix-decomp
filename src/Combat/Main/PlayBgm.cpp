#include <globaldefs.h>

struct BgmPlayer;
extern "C" void func_0209c73c(struct BgmPlayer* actor);
extern "C" void func_0203aa44(void* player);
extern "C" int func_0203aaf8(void* player, void* trackId, int* out);
struct BgmPlayer;
extern "C" int func_0203aba8(struct BgmPlayer* player, void* key, void* target);
extern "C" void SetBgmVolume(void* player, int volume, int fadeFrames);

struct BgmPlayerFlags {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char suppressed : 1;
    unsigned char suppressNext : 1;
    unsigned char rest : 4;
};

struct BgmPlayer {
    char unknown0[0xb0];
    int state;               // 0xb0
    int field_b4;             // 0xb4
    short field_b8;             // 0xb8
    short field_ba;               // 0xba
    void* primarySequence;                 // 0xbc
    void* secondarySequence;                   // 0xc0
    void* pendingSequence;                     // 0xc4
    struct BgmPlayerFlags field_c8;       // 0xc8
    unsigned char field_c9;                // 0xc9
    short field_ca;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char field_cd;                      // 0xcd
    short field_ce;                                // 0xce
};

// Starts one track on the global sound player at 0x02109bf4, the object the curated
// OpenBgmStreamSmallRegion, StopCurrentBgm and RunMapBgmScript also act on. It returns early when
// state is already 1 holding the same id, which is why the id is kept at +0xb8; an id of zero or
// less still sets state 1 and stores the id, it only skips the two lookups and SetBgmVolume. The
// sequence player it starts is the slot at +0xbc, the same slot StopCurrentBgm fades out in state 1
// and SetBgmVolume retargets; DispatchActorState0209c73c stops the slot at +0xc4 with no fade
// whenever the pending id at +0xce is set, which is what makes that third slot the pending one.
// func_0209c480 drives the same object through state 2 with its own id at +0xba and the slot at
// +0xc0, but state is one field, so whether the two are independent voices is not established.
// Bit 2 of the flags at +0xc8 suppresses the whole call, and on the way out it is reloaded from
// bit 3 and bit 3 cleared, so bit 3 arms the suppression for the next call only.
extern "C" ARM void PlayBgm(struct BgmPlayer* actor, int trackId) {
    if (actor->state == 2) return;
    if (actor->state == 1 && trackId == actor->field_b8) return;
    if (actor->field_c8.suppressed) return;
    if (actor->field_ce > -1) {
        func_0209c73c((struct BgmPlayer*)actor);
    }
    actor->state = 1;
    func_0203aa44(actor);
    if (trackId > 0) {
        func_0203aaf8(actor, (void*)trackId, &actor->field_b4);
        func_0203aba8((struct BgmPlayer*)actor, (void*)trackId, &actor->primarySequence);
        SetBgmVolume(actor, actor->field_cd, 0);
    }
    actor->field_b8 = (short)trackId;
    actor->field_ce = -1;
    actor->field_c8.suppressed = actor->field_c8.suppressNext;
    actor->field_c8.suppressNext = 0;
}
