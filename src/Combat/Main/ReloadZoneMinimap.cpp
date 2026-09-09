#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_02020720(int);
extern "C" int GetZoneState(void);
extern "C" int sprintf(char* dst, const char* fmt, ...);

struct Obj020e063c;
extern "C" void func_020e063c(Obj020e063c* self, int b, int c);

struct Struct020dc3d4 {
    char pad[0x6d0];
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
extern "C" ARM void ReloadZoneMinimap(void) {
    char buf[0x18];
    int base = func_ov017_0218b5b0();
    int handle = ((Struct020dc3d4*)(base + 0x3000))->field6d0;
    func_02020720(handle);
    sprintf(buf, &strStrPac_020f2948, GetZoneState() + 0x26);
    func_020e063c((Obj020e063c*)handle, (int)&strDataPackLv5MinimaptGp2_020f294f, (int)buf);
}
