#include <globaldefs.h>

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);
struct List0207f6ac;
void ResolveEntryRefs0207f72c(struct List0207f6ac* p);

struct Data02108ee0 { void* field0; void* field4; };
extern struct Data02108ee0 data_02108ee0;
extern int data_020f0fb0;

// USA: func_0207f524
ARM void InitStreamAndRun0207f524(void* param0, void* param1, struct StreamHeader* param2, int param3) {
    if (param1 != 0 && param2 != 0 && param3 != 0) {
        struct ResetStruct local;
        data_02108ee0.field0 = param1;
        data_02108ee0.field4 = param0;
        _ZN6Script10InitializeEv(&local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f0fb0);
        _ZN6Script4LoadEPKvj((struct StreamState*)&local, param2, param3);
        _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
        ResolveEntryRefs0207f72c((struct List0207f6ac*)param0);
    }
}
