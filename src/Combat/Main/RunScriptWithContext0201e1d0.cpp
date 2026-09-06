#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Ctx020fdc20 { int field0; int field4; int field8; };
extern struct Ctx020fdc20 data_020fdc20;
extern int data_020ef388;

// USA: func_0201e1d0
extern "C" ARM void _Z21ExecuteZoneWarpScriptPKvjP12ZoneFeaturesP13SafeAllocator(struct StreamHeader* buffer, int length, int c, int d) {
    char local[0x430];
    if (length == 0) return;
    data_020fdc20.field8 = c;
    data_020fdc20.field4 = d;
    data_020fdc20.field0 = 0;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020ef388);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    data_020fdc20.field8 = 0;
    data_020fdc20.field4 = 0;
    data_020fdc20.field0 = 0;
}
