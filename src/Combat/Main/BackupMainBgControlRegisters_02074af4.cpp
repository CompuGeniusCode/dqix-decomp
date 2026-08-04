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

// USA: func_02074af4  (semantic: BackupMainBgControlRegisters_02074af4)
extern "C" ARM void func_02074af4(struct MainBgControlBackup02074af4* obj) {
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
