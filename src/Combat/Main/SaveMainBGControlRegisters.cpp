#include <globaldefs.h>

struct BgControlBackup {
    volatile unsigned short savedMainBg0Cnt;
    char savedSubBg0Cnt[2];
    volatile unsigned short savedMainBg1Cnt;
    char savedSubBg1Cnt[2];
    volatile unsigned short savedMainBg2Cnt;
    char savedSubBg2Cnt[2];
    volatile unsigned short savedMainBg3Cnt;
    char savedSubBg3Cnt[2];
    unsigned char mainSaved;
};

// Copies the main 2D engine's four BG control registers into the caller's struct and sets the byte
// at +0x10 to say the copy is there, doing nothing if it already is. The pool literal 0x04000008
// makes the halfwords BG0CNT through BG3CNT; they land at +0, +4, +8 and +0xc. func_02074b64 is the
// same routine for the sub engine at 0x04001008, and it writes its four halfwords into the same
// struct at +2, +6, +0xa and +0xe behind its own flag at +0x11, so the two engines' copies
// interleave. RestoreMainBGControlRegisters and func_02074bf4 put the main and sub sets back and
// clear the two flags.
extern "C" ARM void SaveMainBGControlRegisters(struct BgControlBackup* backup) {
    if (backup->mainSaved != 0) return;
    unsigned short* const reg = (unsigned short*)0x4000008;
    volatile short bg0CntScratch, bg1CntScratch, bg2CntScratch, bg3CntScratch;
    {
        unsigned short raw = *(volatile unsigned short*)&reg[0];
        bg0CntScratch = raw;
        bg0CntScratch;
        backup->savedMainBg0Cnt = raw;
        bg0CntScratch;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[1];
        backup->savedMainBg1Cnt = raw;
        bg1CntScratch = raw;
        bg1CntScratch;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[2];
        bg2CntScratch = raw;
        bg2CntScratch;
        backup->savedMainBg2Cnt = raw;
        bg2CntScratch;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[3];
        backup->savedMainBg3Cnt = raw;
        bg3CntScratch = raw;
        bg3CntScratch;
    }
    backup->mainSaved = 1;
}
