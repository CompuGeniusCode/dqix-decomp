#include <globaldefs.h>

extern int data_02100044;

// Returns the single global gamemain event queue. __sinit_020e5b28 builds it as 192 records of
// 0x1c bytes and three 0xc-byte list heads -- +0x1500 free, +0x150c posted, +0x1518 ready.
// EnqueueGamemainEvent links a record in with interrupts disabled, but only while
// GetMultiplayerState's field 0 is nonzero; func_ov017_021d48f0 drains it through
// data_ov017_021d7f98[tag], 0xbc handlers gated by the enable bits at +0x1524. All 169 posts are
// in ov017; other modules only drain or query. What the tags stand for is not established.
extern "C" ARM void* GetGamemainEventQueue(void) {
    return &data_02100044;
}
