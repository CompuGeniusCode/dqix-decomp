#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"

extern "C" void func_020145a8(void* obj);

extern char strZ0NumM0100;
extern char strZ0NumM0101;
extern char strZ0NumM0102;
extern char strZ0NumM0103;
extern char strStrAtsChrAmbl;
extern char strDataMap;

// Queues data/map/ats_<c>.ambl, the archive of per-zone .bats records grouped by the first
// letter of the map short name; Zone3D::UnpackATS_AMBL then pulls "<name>.bats" out of it and
// Zone3D::ProcessBATSFile hands the decompressed file to LightingInfo::LoadFromScript, so a
// .bats is the zone's lighting record. Whether "ats" is short for atmosphere is not
// established. The ROM holds fourteen of these archives: ats_B, C, D, E, F, H, K, M, O, R, S,
// T, X and Z.
// A main grotto floor has no map short name of its own, so one is synthesised into
// substruct_c_.buffer1 first: "Z0<env>M01<band>", band 00..03 for floors up to 4, 8, 12 and 16;
// ats_Z.ambl does hold Z01M0100.bats through Z05M0103.bats. With no name at all the AMDJ load
// runs instead.
extern "C" ARM void Zone3D_QueueLoadATS_AMBL(void* obj) {
    char* zoneBytes = (char*)obj;

    if (*(unsigned char*)(zoneBytes + 0x23b8) != 0) {
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zoneBytes + 0x23ec);
        int grottoEnviron = grotto->GetActiveGrottoEnviron();
        if (grottoEnviron == 0) grottoEnviron = 1;

        signed char grottoFloor = *(signed char*)(zoneBytes + 0x23ba);
        if (grottoFloor <= 0x4) {
            sprintf(zoneBytes + 0xc, &strZ0NumM0100, grottoEnviron);
        } else if (grottoFloor <= 0x8) {
            sprintf(zoneBytes + 0xc, &strZ0NumM0101, grottoEnviron);
        } else if (grottoFloor <= 0xc) {
            sprintf(zoneBytes + 0xc, &strZ0NumM0102, grottoEnviron);
        } else if (grottoFloor <= 0x10) {
            sprintf(zoneBytes + 0xc, &strZ0NumM0103, grottoEnviron);
        }
    }

    if (strlen(zoneBytes + 0xc) == 0) {
        func_020145a8(obj);
        return;
    }

    int loader = (int)BackgroundLoader::GetInstance();
    signed char mapNameInitial = *(signed char*)(zoneBytes + 0xc);
    char atsPath[0x28];
    sprintf(atsPath, &strStrAtsChrAmbl, &strDataMap, mapNameInitial);
    *(int*)(zoneBytes + 0x440) = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)atsPath), (SafeAllocator*)(0));
}
