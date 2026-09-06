#include <globaldefs.h>

struct SubBgControlBackup02074b64 {
    char pad0[2];
    volatile unsigned short savedBg0Cnt;
    char pad4[2];
    volatile unsigned short savedBg1Cnt;
    char pad8[2];
    volatile unsigned short savedBg2Cnt;
    char padC[2];
    volatile unsigned short savedBg3Cnt;
    char pad10;
    unsigned char initialized;
};

// USA: func_02074b64
ARM void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj) {
    if (obj->initialized != 0) return;
    unsigned short* const reg = (unsigned short*)0x4001008;
    volatile short v0, v1, v2, v3;
    {
        unsigned short raw = *(volatile unsigned short*)&reg[0];
        v0 = raw;
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
