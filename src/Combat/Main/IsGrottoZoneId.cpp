#include <globaldefs.h>

// True when the zone id belongs to the "Z - Treasure Maps" group of data/map/maplist9.bin, whose
// records carry the literal group string "Grotto". The bounds 40001 and 41505 are exactly the first
// and last of the 165 ids in that group -- 80 Z00Mnn "Treasure Map - Lv n", 60 Z01-Z05 M01..M12
// Natural, Man-Made, Icy, Watery and Fiery Level, and 25 boss floors -- and nothing else in the file
// is in the 40000 band. ActiveGrottoClass::GetFloorCount returns 0 when this is false, and
// func_0201bfd4 clears grotto state only when it is false.
extern "C" ARM int IsGrottoZoneId(int id) {
    if (id >= 0x9c41) {
        if (id <= 0xa221) return 1;
    }
    return 0;
}
