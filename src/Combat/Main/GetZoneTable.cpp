#include <globaldefs.h>

// Hands back the list at +0x468 of the global state GetBattleStruct returns: {data, count} and a
// third word nothing here reads, over 0x10-byte records whose first halfword is a zone id and whose
// +5 is a seven-byte map code such as "B01M01". Zone3D::SwitchZone looks a record up by that id and
// Zone3D::LoadMapAMBL formats "%s/%s.ambl" from record+5, so that field is the map-file basename;
// ZoneFeatures::func_0201cb60 resolves a script-named warp destination through
// func_0209998c on the same list. The JPN build maps this function to func_020112f4.
extern "C" ARM void* GetZoneTable(void* obj) {
    return (char*)obj + 0x468;
}
