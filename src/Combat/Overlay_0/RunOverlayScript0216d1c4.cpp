#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_ov000_02184264;
extern int data_ov000_02183b5c;

// USA: func_ov000_0216d1c4
ARM void RunOverlayScript0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out) {
    char local[0x430];
    *(int*)((char*)&data_ov000_02184264 + 0x8) = arg0;
    *(int*)((char*)&data_ov000_02184264 + 0x4) = 0;
    *(int*)((char*)&data_ov000_02184264 + 0x0) = 0;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov000_02183b5c);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    *out = *(int*)&data_ov000_02184264;
}
