#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"

extern "C" int func_0201b5b0(int id);
extern "C" int IsGrottoBossFloorZoneId(int x);

extern char strStrZ0NumM01Ambl;
extern char strDataMap;
extern char strStrZ0NumM99Ambl;
extern char strStrStrAmbl;

// Queues the .ambl that holds the zone's map geometry; the handle lands in mapAMBLLoadHandle_
// at Zone3D+0x438. Nothing in the tree reads that handle back yet - func_02013fb4 is this
// function's only caller, and the handle it polls is mapListLoadHandle_ at 0x430, not this one.
// A main grotto floor takes data/map/Z0<env>M01.ambl and a grotto boss zone
// data/map/Z0<env>M99.ambl, <env> being the grotto environment: func_0201b5b0 is the same
// zone-id test Zone3D::SwitchZone uses to set isInMainGrottoFloor_, and func_0201b5d8 is the
// one func_0209fd00 answers with GetFloorCount() + 1, the floor past the last. The ROM holds
// Z01 through Z05 of each; only the M01 branch clamps env into 1..5.
// Every other zone takes data/map/<mapShortName>.ambl, which is why the format argument is
// pUnknownStruct_8_ plus five - mapShortName_ sits at offset 5 of Zone3D_StructPtr_8.
extern "C" ARM void Zone3D_LoadMapAMBL(void* zone) {
    char* zoneBytes = (char*)zone;
    int loader = (int)BackgroundLoader::GetInstance();
    char amblPath[0x14];

    if (func_0201b5b0(*(unsigned short*)zoneBytes)) {
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zoneBytes + 0x23ec);
        int env = grotto->GetActiveGrottoEnviron();
        if (env == 0) env = 1;
        if (env > 5) env = 5;
        sprintf(amblPath, &strStrZ0NumM01Ambl, &strDataMap, env);
    } else if (IsGrottoBossFloorZoneId(*(unsigned short*)zoneBytes)) {
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zoneBytes + 0x23ec);
        int env = grotto->GetActiveGrottoEnviron();
        sprintf(amblPath, &strStrZ0NumM99Ambl, &strDataMap, env);
    } else {
        sprintf(amblPath, &strStrStrAmbl, &strDataMap, *(int*)(zoneBytes + 8) + 5);
    }

    *(int*)(zoneBytes + 0x438) = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)amblPath), (SafeAllocator*)(0));
}
