#include <globaldefs.h>

extern "C" int func_02033ce8(void* obj, int val);

struct Bytes02033b88 {
    char pad[0xbe];
    unsigned char cur;
    unsigned char prev;
};

// Sets the actor's motion state at +0xbe, keeping the outgoing one at +0xbf, then passes the object and
// the new value to func_02033ce8; func_02033b68 is the same thing guarded so it only fires when the
// value actually differs. func_02033dd4 rejects states of 9 and above and uses this byte as the row of
// the 9 x 13 table at data_020ef9c4, with +0xc0 (clamped below 12) as the column, so a state picks a
// row and something else picks the animation within it; the values index the names at data_020ef994 --
// stand, run, attack0a, damage, death, appear, takara, hirou. What reads +0xbf back is not established.
extern "C" ARM int SetActorMotionState(struct Bytes02033b88* p, int val) {
    p->prev = p->cur;
    p->cur = (unsigned char)val;
    return func_02033ce8(p, val);
}
