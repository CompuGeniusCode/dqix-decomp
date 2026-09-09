#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

// Writes the 0xb0 byte play record block back to the game state root at +0x7540, the exact inverse of
// CopyOutPlayRecords next door. func_020ac4f8 uses the pair: read the block out, add the elapsed
// hours, minutes and seconds onto the HH:MM:SS clocks it holds at +0, +4, +0x68 and +0x6c, write it
// back. Only the clocks at +0 and +0x68 always advance; +4 and +0x6c move only when the caller's
// commit argument is non-zero, and from a second elapsed time. The clocks saturate at 9999:59:59.
extern "C" ARM int CopyInPlayRecords(void* src) {
    int* region = (int*)((char*)GetBattleStruct() + 0x104);
    memcpy((char*)(region + 0x1d00) + 0x3c, src, 0xb0);
    return 1;
}
