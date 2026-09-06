#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

struct DataStruct02109404 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short f6;
};
extern struct DataStruct02109404 data_02109404;
extern short data_020f13d8;
extern char data_020f13dc[];

// USA: func_020957f4
ARM int RunBufferedScript020957f4(void* unused, struct StreamHeader* buffer, int length) {
    char local[0x430];

    data_02109404.f6 = 0;
    data_02109404.f1 = 1;
    data_02109404.f2 = 0;
    data_020f13d8 = -1;

    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(local, data_020f13dc);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);

    return data_02109404.f6;
}
