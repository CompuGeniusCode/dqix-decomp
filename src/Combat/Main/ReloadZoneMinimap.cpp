#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_02020720(int);
extern "C" int GetZoneState(void);
extern "C" int sprintf(char* dst, const char* fmt, ...);

struct Obj020e063c;
extern "C" void func_020e063c(Obj020e063c* self, int gp2Path, int innerFileName);

struct Ov017Work {
    char unknown0[0x6d0];
    int field6d0;
};

extern char strStrPac_020f2948;
extern char strDataPackLv5MinimaptGp2_020f294f;

// Requests the minimap image for the zone the party is in: the name comes from the string at
// zoneState + 0x26, is turned into "<name>.pac" and asked for out of data/pack_lv5/minimapt.gp2 by
// func_020e063c, which drops the previous handle before queueing. Only ov004 calls it.
// func_02020b98 formats "%s.bmmp" from the same field and strcpy's it, so +0x26 is a
// NUL-terminated name; minimapt.gp2's members are mapt_NNN.pac, so it is a map asset name of that
// shape, which is also what the "t" in minimapt tracks.
// The object the path is handed to is the pointer at +0x36d0 of the overlay-17 object
// func_ov017_0218b5b0 returns -- Struct44C8.h calls it unknown_ptr_36d0 -- reached here as +0x6d0
// of a view that starts at +0x3000, the same way RefreshSubScreenMode reaches +0x36fc next door.
// What that object is is not established: func_020e063c is a generic restart of the load task it
// keeps at +0xa0c, and func_02021578 resets the same object through func_02020720 while queueing
// other map files, so it is not a minimap loader.
extern "C" ARM void ReloadZoneMinimap(void) {
    char minimapFileName[0x18];
    int base = func_ov017_0218b5b0();
    int handle = ((Ov017Work*)(base + 0x3000))->field6d0;
    func_02020720(handle);
    sprintf(minimapFileName, &strStrPac_020f2948, GetZoneState() + 0x26);
    func_020e063c((Obj020e063c*)handle, (int)&strDataPackLv5MinimaptGp2_020f294f, (int)minimapFileName);
}
