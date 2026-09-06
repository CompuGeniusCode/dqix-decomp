#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_ov003_02180cb8;
extern int data_ov003_0217ff40;

// USA: func_ov003_0215e6f8  (semantic: InitAndRunBufferedScript_0215e6f8)
extern "C" ARM void func_ov003_0215e6f8(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)((char*)&data_ov003_02180cb8 + 4) = handler0;
    *(int*)&data_ov003_02180cb8 = handler1;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov003_0217ff40);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
}
