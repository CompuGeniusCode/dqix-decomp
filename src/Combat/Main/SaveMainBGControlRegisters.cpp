#include <globaldefs.h>

struct MainBgControlBackup02074af4 {
    volatile unsigned short savedBg0Cnt;
    char pad2[2];
    volatile unsigned short savedBg1Cnt;
    char pad6[2];
    volatile unsigned short savedBg2Cnt;
    char padA[2];
    volatile unsigned short savedBg3Cnt;
    char padE[2];
    unsigned char initialized;
};

// Copies the main 2D engine's four BG control registers into the caller's struct and sets the byte
// at +0x10 to say the copy is there, doing nothing if it already is. The pool literal 0x04000008
// makes the halfwords BG0CNT through BG3CNT; they land at +0, +4, +8 and +0xc. func_02074b64 is the
// same routine for the sub engine at 0x04001008, writing the odd halfwords behind +0x11, and
// RestoreMainBGControlRegisters and func_02074bf4 put the main and sub sets back and clear the two flags.
extern "C" ARM void SaveMainBGControlRegisters(struct MainBgControlBackup02074af4* obj) {
    if (obj->initialized != 0) return;
    unsigned short* const reg = (unsigned short*)0x4000008;
    volatile short v0, v1, v2, v3;
    {
        unsigned short raw = *(volatile unsigned short*)&reg[0];
        v0 = raw;
        v0;
        obj->savedBg0Cnt = raw;
        v0;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[1];
        obj->savedBg1Cnt = raw;
        v1 = raw;
        v1;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[2];
        v2 = raw;
        v2;
        obj->savedBg2Cnt = raw;
        v2;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[3];
        obj->savedBg3Cnt = raw;
        v3 = raw;
        v3;
    }
    obj->initialized = 1;
}
