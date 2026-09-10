#include <globaldefs.h>

struct SequencePlayerHandle;
extern "C" void func_020bc180(SequencePlayerHandle*, int, int);
extern "C" void func_020bbf34(int, int);

extern float data_020e8ec4[5];

struct BgmPlayer {
    char unknown0[0xc8];
    unsigned char unknownc8Bit0 : 1;
    unsigned char halveVolume : 1;
    unsigned char unknownc8Bits2To7 : 6;
    char unknownc9[3];
    unsigned char volumeStep;
    unsigned char volume;
};

// Volume for the BGM player singleton data_02109bf4. The requested volume is kept at 0xcd and
// scaled by the 1..5 step at 0xcc before it is pushed at the two sequence players at 0xbc and 0xc0,
// whose own volume is 8.8 fixed point, hence the shift: func_020bc180 shifts the value left 8 and
// hands it and fadeLength to the tween retarget at node+0x1c. fadeLength seems to be a fade length
// in frames (func_0209caa0 and func_0209c840 both pass 0x1e), though that is not established.
// data_020e8ec4 is the ladder {0, 48/127, 85/127, 108/127, 1} indexed by that same 1..5 step, and
// the scaled result becomes the group volume of sound groups 5, 6 and 7 at data_0210f824, which
// func_020bbf34 writes one byte at a time on a 0x24 stride; func_0205e944 is the sound-effect
// analogue over groups 0xa to 0x10, without the tween half. Bit 0 of 0xc8 and everything from 0xc9
// are left alone here: func_0209c840 runs 0xc9 as a phase with a countdown at 0xca and sets that
// bit while it has a sequence node playing.
extern "C" ARM void SetBgmVolume(BgmPlayer* bgmPlayer, int volume, int fadeLength) {
    bgmPlayer->volume = (unsigned char)volume;
    int step = bgmPlayer->volumeStep;
    float scale = ((float)step - 1.0f) / 4.0f;
    int tweenVolume = (int)((float)bgmPlayer->volume * scale);
    if (bgmPlayer->halveVolume) {
        tweenVolume = tweenVolume / 2;
    }
    func_020bc180((SequencePlayerHandle*)((char*)bgmPlayer + 0xbc), tweenVolume, fadeLength);
    func_020bc180((SequencePlayerHandle*)((char*)bgmPlayer + 0xc0), tweenVolume, fadeLength);
    int groupVolume = (int)((float)bgmPlayer->volume * data_020e8ec4[bgmPlayer->volumeStep - 1]);
    func_020bbf34(5, groupVolume);
    func_020bbf34(7, groupVolume);
    func_020bbf34(6, groupVolume);
}
