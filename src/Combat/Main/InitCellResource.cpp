#include <globaldefs.h>
#include "std_library_functions.h"

// Constructor for the 2D cell-graphics object that LoadNitroResourceBySignature fills from an NCER,
// NANR, NCGR or NCLR image -- it clears exactly the 0x51 bytes those handlers touch, and the empty
// destructor sits right after it at 0x0205a494. The byte at +0x50 it leaves set to 1 selects the
// VRAM target the palette and character handlers pass on, 0 giving 1 and anything else 2,
// presumably NITRO's main and sub 2D engine constants. All 50 call sites, in main and fourteen
// overlays, embed it at an offset inside a larger object.
extern "C" ARM void InitCellResource(char* obj) {
    memset(obj, 0, 0x24);
    memset(obj + 0x24, 0, 0x14);
    *(int*)(obj + 0x38) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(short*)(obj + 0x4c) = 0;
    *(short*)(obj + 0x4e) = 0;
    *(int*)(obj + 0x3c) = 0;
    *(char*)(obj + 0x50) = 1;
}
