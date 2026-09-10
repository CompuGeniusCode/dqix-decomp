#include <globaldefs.h>

// The top-level mode the game is in, a byte at +0x4 of the state root. main() writes it eight times
// and dispatches on it twice, an eight-way jump table at 0x02001078 and a ten-way one at
// 0x0200111c, whose handlers pick the overlay to run -- 0x11 gamemain, 0x15 charamake. The title
// screen takes the next value out of data_ov020_0218d990 or data_ov020_0218d974 by which entry the
// player chose, selecting between them on a save-file query returning 4, presumably meaning a save
// exists. ov004 writes 0, 2, 6, 7, 8 and 9 through SetGameModeRequest; the numbers are only partly known.
extern "C" ARM unsigned char GetGameMode(char* obj) {
    return obj[4];
}
