#include <globaldefs.h>

extern "C" void func_0203ac10(void*, void*, int);

struct BgmPlayer {
    unsigned char unknown0[0xb0];
    int state;               // 0xb0
    unsigned char unknownb4[0x8]; // 0xb4
    void* sequencePlayer0;           // 0xbc
    void* sequencePlayer1;           // 0xc0
    unsigned char unknownc4[0x4]; // 0xc4
    unsigned char unknownc8Bit0 : 1;    // 0xc8 bit0
    unsigned char halfVolume : 1;    // bit1
    unsigned char stopSuppressed : 1;    // bit2
};

// Stops whichever BGM track the player currently has running; the argument is the fade-out
// length, and 0 stops it outright. State 1 means the sequence player at +0xbc is playing and state
// 2 the one at +0xc0, and func_020bc548 turns a non-zero fade into a volume ramp down to 0 on that
// handle. The object is the BGM player: OpenBgmStreamSmallRegion opens "data/sound/bgm.sdat" into
// it through OpenFileStreamInRegion, and SetBgmVolume scales +0xcd against the five-step volume
// setting at +0xcc and tweens both +0xbc and +0xc0, which is what makes those two the sequence
// players rather than plain handles. Bit 2 of +0xc8 suppresses the stop entirely and bit 1 is the
// halve-the-volume flag SetBgmVolume reads; bit 0 is not established.
extern "C" ARM void StopCurrentBgm(struct BgmPlayer* player, int fadeOutLength) {
    if (player->stopSuppressed) return;
    if (player->state == 1) {
        func_0203ac10(player, &player->sequencePlayer0, fadeOutLength);
    } else if (player->state == 2) {
        func_0203ac10(player, &player->sequencePlayer1, fadeOutLength);
    }
}
