#include <globaldefs.h>

struct Struct02074bd0 {
    char pad[0x10];
    unsigned char flag10;
};

extern "C" void func_02074c18(struct Struct02074bd0*);

// Puts back the main engine's BG0CNT-BG3CNT that SaveMainBGControlRegisters stored, then drops the
// backup by clearing the valid flag at +0x10. func_02074c18 does the writing: it re-reads the live
// register at 0x04000008 and merges the saved fields back over it, keeping the current bits under
// mask 0x43. One object holds both engines interleaved -- main at +0x0/+0x4/+0x8/+0xc with its flag
// at +0x10, sub at +0x2/+0x6/+0xa/+0xe with flag +0x11 -- and func_02074bf4 is the sub-engine twin,
// writing through its own 0x02074e54.
extern "C" ARM void RestoreMainBGControlRegisters(struct Struct02074bd0* obj) {
    if (obj->flag10) {
        func_02074c18(obj);
        obj->flag10 = 0;
    }
}
