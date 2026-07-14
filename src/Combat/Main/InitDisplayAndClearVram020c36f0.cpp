#include <globaldefs.h>
#include "System/DMA.h"
#include "System/GamecardBusOwnership.h"

extern "C" void func_020c9be0(void);
extern "C" void func_020ca3ec(int value, void* dst, int size);
void ResetVramAndClearState(void);

extern unsigned short data_02111220;
extern int data_020f226c;

#define data_02111222_field (*(unsigned short*)((char*)&data_02111220 + 2))

// USA: func_020c36f0
ARM void InitDisplayAndClearVram020c36f0(void) {
    *(volatile unsigned short*)0x4000304 |= 0x8000;
    *(volatile unsigned short*)0x4000304 = (*(volatile unsigned short*)0x4000304 & 0xfffffdf1) | 0xe | 0x200;
    *(volatile unsigned short*)0x4000304 |= 1;

    ResetVramAndClearState();

    if (data_02111222_field == 0) {
        int id;
        do {
            id = (int)GenerateLockOwnerID();
            if (id == -3) {
                func_020c9be0();
            }
            data_02111222_field = (unsigned short)id;
        } while (data_02111222_field == 0);
    }

    *(volatile unsigned short*)0x4000004 = 0;
    *(volatile unsigned int*)0x4000000 = 0;

    int channel = *(int*)((char*)&data_020f226c + 4);
    if (channel != -1) {
        DMAMemsetSynchronous(channel, 0x4000008, 0, 0x60);
        *(volatile unsigned short*)0x400006c = 0;
        channel = *(int*)((char*)&data_020f226c + 4);
        DMAMemsetSynchronous(channel, 0x4001000, 0, 0x70);
    } else {
        func_020ca3ec(0, (void*)0x4000008, 0x60);
        *(volatile unsigned short*)0x400006c = 0;
        func_020ca3ec(0, (void*)0x4001000, 0x70);
    }

    *(volatile unsigned short*)0x4000020 = 0x100;
    *(volatile unsigned short*)0x4000026 = 0x100;
    *(volatile unsigned short*)0x4000030 = 0x100;
    *(volatile unsigned short*)0x4000036 = 0x100;
    *(volatile unsigned short*)0x4001020 = 0x100;
    *(volatile unsigned short*)0x4001026 = 0x100;
    *(volatile unsigned short*)0x4001030 = 0x100;
    *(volatile unsigned short*)0x4001036 = 0x100;
}
