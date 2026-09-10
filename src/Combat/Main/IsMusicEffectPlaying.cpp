#include <globaldefs.h>

extern "C" int func_020bc0a4(int);

// True while the music effect queued at +0xce of the BGM player is still pending or still sounding.
// func_0209c830 writes the id there and raises the phase byte at +0xc9; func_0209c840 fades the
// current BGM down, starts the queued id, waits for it to stop and then restores the old track.
// Every constant id passed in is in 0x32..0x44, which the SYMB block of data/sound/bgm.sdat names
// ME_001..ME_019, the whole ME bank. The last test counts live entries carrying that id in the
// sound pool at data_0210f3d8; callers use it to wait.
extern "C" ARM int IsMusicEffectPlaying(void* obj) {
    short handle = *(short*)((char*)obj + 0xce);
    if (handle < 0) return 0;
    if (*(unsigned char*)((char*)obj + 0xc9) != 0) return 1;
    return func_020bc0a4(handle) > 0;
}
