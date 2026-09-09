#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int strDataEffectEv999991500Chr;

struct Handle02046c98 {
    unsigned char pad[0xe8];
    int f_e8;   // 0xe8
    int f_ec;   // 0xec
};

// Starts the background load of data/effect/ev999991500.chr for this object unless the word at +0xe8
// is already non-zero; func_02046e08 zeroes that word and puts -1 in +0xec, where the task id is
// parked, but what +0xe8 holds is not established. The effect directory names files as "ev" plus a
// five-digit event id plus a four-digit index (ev18000nnnn and so on), and 99999 reads as a sentinel,
// so this seems to be a shared effect rather than one belonging to a scene. Which effect index 1500
// is has not been established.
extern "C" ARM void QueueEffectEv999991500Load(struct Handle02046c98* h) {
    if (h->f_e8 != 0) return;
    h->f_ec = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&strDataEffectEv999991500Chr), (SafeAllocator*)(0));
}
