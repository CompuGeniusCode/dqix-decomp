#include <globaldefs.h>

struct SearchStruct;
struct ByteSearchStruct;
extern "C" signed char func_0202bcbc(struct SearchStruct* obj, int value);
extern "C" signed char func_0202bcf8(struct ByteSearchStruct* obj, int value);

// Tests one player's bit in a per-player flag byte of the multiplayer state block; obj+0x100c,
// 0x100e, 0x100f and 0x1010 are four such bytes, each one bit per player. The lookup falls back to
// the second id table at obj+0x1048 when the first at obj+0x1038 misses. What 0x100e records is not
// established, but every call site treats a set bit the way it treats a player who is not there --
// func_020e35a0 drops that player's pending work on either condition, and ov017 checks player 0 to
// abandon what the local player was doing -- so it reads as a player having dropped out.
extern "C" ARM int IsMultiplayerPlayerFlag0x100eSet(struct SearchStruct* obj, int value) {
    int idx = func_0202bcbc(obj, value);
    if (idx < 0) {
        idx = func_0202bcf8((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return 0;
    }
    return *((unsigned char*)obj + 0x100e) & (1 << idx);
}
