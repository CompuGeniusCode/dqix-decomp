#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "System/Memory.h"
#include "System/Timing.h"
#include "std_library_functions.h"

extern "C" void func_020a3720();
extern "C" void func_020a395c();
extern char data_ov017_021d781c;

// USA: func_ov017_021a9a9c  (semantic: InitializeTreasureMapEntry_021a9a9c)
extern "C" ARM void func_ov017_021a9a9c(void* obj, unsigned char type, unsigned int quality, int seed, unsigned char locationOverride) {
    unsigned char* base = (unsigned char*)obj;
    TreasureMapMetadata* metadata = (TreasureMapMetadata*)(base + 0xa);
    DetailedTreasureMapData* detailed = (DetailedTreasureMapData*)(base + 0x28);

    base[0x26d] = type;
    VectorizedMemset(metadata, 0, 0x1c);
    detailed->Clear();
    srand(GetMain16BitTimerCounter());

    if (base[0x26d] == 1) {
        metadata->InitialiseAsNonLegacyMap(quality, seed);
        base[0x26e] = metadata->QualityOrLegacyBossID;
        *(unsigned short*)(base + 0x270) = metadata->SeedOrMinTurns;
    } else if (base[0x26d] == 2) {
        metadata->InitialiseAsLegacyBossMap(quality, (unsigned char)seed);
        base[0x26e] = metadata->QualityOrLegacyBossID;
        *(unsigned short*)(base + 0x270) = metadata->LegacyBossLevel;
    } else {
        metadata->InitialiseAsNonLegacyMap(quality, seed);
        base[0x26e] = metadata->QualityOrLegacyBossID;
        *(unsigned short*)(base + 0x270) = metadata->SeedOrMinTurns;
    }

    if (locationOverride != 0) {
        metadata->Location = locationOverride;
    }

    func_020a3720();
    ExportDetailedTreasureMapData(metadata, detailed, false, NULL);
    func_020a395c();

    if (base[0x26d] == 1) {
        strcpy((char*)(base + 0x1ec), (char*)(base + 0xd7));
    } else if (base[0x26d] == 2) {
        strcpy((char*)(base + 0x1ec), (char*)(base + 0x16c));
    }

    sprintf((char*)(base + 0x22c), &data_ov017_021d781c, (char*)(base + 0x1ec));
}
