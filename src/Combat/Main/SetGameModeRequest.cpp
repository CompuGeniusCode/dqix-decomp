#include <globaldefs.h>

// Writes the byte at +0x4 of the global game state, which is read back as the mode the game runs
// next - func_ov017_0218d274 branches on it being 6 to pick between two VRAM configurations. The
// title screen picks the value out of one of two tables once the player commits to an entry, the
// eight-entry data_ov020_0218d990 when func_020ab9c0 reports 4 and the seven-entry
// data_ov020_0218d974 otherwise, and bails early if the byte already reads 6. ov004's menu callbacks
// write it as menus close, and all eight arm9 call sites are inside main itself. Values are unnamed.
extern "C" ARM void SetGameModeRequest(char* obj, unsigned char value) {
    obj[4] = value;
}
