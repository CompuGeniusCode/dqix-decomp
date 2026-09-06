#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_020fdd30;
extern int data_020ef6f4;

// USA: func_02028048
ARM void RunBufferedScript(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)&data_020fdd30 = handler0;
    *(int*)((char*)&data_020fdd30 + 4) = handler1;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020ef6f4);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    *(int*)((char*)&data_020fdd30 + 4) = 0;
    *(int*)&data_020fdd30 = 0;
}
