#include <globaldefs.h>

extern int data_02109030;

// The single navi instance, which raises the multiplayer guest banner: str_navi.gp2 holds
// "<Cap><str_1> has arrived!", "... disappeared" and "Communication error.", and func_02094030
// calls GetMultiplayerState. func_02093b90 queues data/ani/obj_navi.pac, str_navi.gp2 and
// str_navi_<LG>.nat through the BackgroundLoader (func_020941f8, func_020943dc), keeping the handle
// at +0x340. func_02094030 fills one of eight 0x34-byte entries (count at 0x3cb, flags at 0x3cd)
// and insertion sorts by func_0209372c, which buckets the message id by ten thousands, so that id
// seems to be a priority band.
extern "C" ARM int* GetNaviManager(void) {
    return &data_02109030;
}
