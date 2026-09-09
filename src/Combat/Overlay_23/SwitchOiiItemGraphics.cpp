#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int strDataAniOiijGp2;
extern int strOiijLgPac;
extern int strDataAniOiirGp2;
extern int strOiirLgPac;

// Swaps which oii archive is loaded: mode 2 takes oiij_<LG>.pac out of data/ani/oiij.gp2, anything
// else oiir_<LG>.pac out of data/ani/oiir.gp2. A request still in flight is cancelled first, the new
// request id is kept at +0x780 and the mode now loaded at +0x77e; asking for the mode already recorded
// at +0x77d loads nothing and copies +0x77d into +0x77e. Both archives carry a member named obj_item,
// hence the item reading, but what oii itself abbreviates is not established. The alchemy overlay
// passes 1 and 2.
extern "C" ARM void SwitchOiiItemGraphics(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int dataResult = (int)BackgroundLoader::GetInstance();
    signed char scratchVal = *(signed char*)(obj + 0x77d);
    if (mode == scratchVal) {
        if (*(int*)(obj + 0x780) < 0) return;
        ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + 0x780)));
        *(int*)(obj + 0x780) = -1;
        obj[0x77e] = *(signed char*)(obj + 0x700 + 0x7d);
        return;
    }
    signed char other = *(signed char*)(obj + 0x77e);
    if (mode == other) return;
    if (*(int*)(obj + 0x780) >= 0) {
        ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + 0x780)));
        *(int*)(obj + 0x780) = -1;
        obj[0x77e] = -1;
    }
    int result;
    if (mode == 2) {
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&strDataAniOiijGp2), (const char*)((int)&strOiijLgPac), (SafeAllocator*)(0));
    } else {
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&strDataAniOiirGp2), (const char*)((int)&strOiirLgPac), (SafeAllocator*)(0));
    }
    *(int*)(obj + 0x780) = result;
    *(unsigned short*)(obj + 0x774) |= 8;
    obj[0x77e] = (char)mode;
}
