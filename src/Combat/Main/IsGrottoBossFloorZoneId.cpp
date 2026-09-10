#include <globaldefs.h>

// True for the 25 grotto boss-floor zones: ids 41101-41105 through 41501-41505, five per
// environment, exactly the last 25 records of the treasure-map group in data/map/maplist9.bin,
// which lists them as Z01M95..Z05M99, "<Natural|Man-Made|Icy|Watery|Fiery> Level Boss Floor", map
// file Z0<env>M99. Zone3D::LoadMapAMBL loads "%s/Z0%dM99.ambl" for this range; the neighbouring
// "%s/Z0%dM01.ambl" branch is guarded by the sibling func_0201b5b0 (40001-40096), not by this
// test. func_0209da48 and func_0209fd00 report GetFloorCount() + 1 when it holds.
extern "C" ARM int IsGrottoBossFloorZoneId(int x) {
    if (x >= 0xa08d) {
        if (x <= 0xa221) return 1;
    }
    return 0;
}
