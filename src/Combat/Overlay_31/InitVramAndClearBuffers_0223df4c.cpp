#include <globaldefs.h>

extern "C" void MapVRAMBanksToLCDC(unsigned short mask);
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" int DisableLCDCMappedVRAMBanks(void);

// USA: func_ov031_0223df4c  (semantic: InitVramAndClearBuffers_0223df4c)
extern "C" ARM void func_ov031_0223df4c() {
    MapVRAMBanksToLCDC(0x1f3);
    func_020ca458(0, (void*)0x6800000, 0x40000);
    func_020ca458(0, (void*)0x6880000, 0x24000);
    DisableLCDCMappedVRAMBanks();
    func_020ca458(0x200, (void*)0x7000000, 0x400);
    func_020ca458(0, (void*)0x5000000, 0x400);
    func_020ca458(0x200, (void*)0x7000400, 0x400);
    func_020ca458(0, (void*)0x5000400, 0x400);
}
