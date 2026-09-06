#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct CallbackCache02108d04 {
    short field0;
    short pad2;
    void* field4;
    void* field8;
    void* fieldC;
};
extern struct CallbackCache02108d04 data_02108d04;
extern int data_020f0a3c;

// USA: func_0206ee80
ARM void RegisterCallbackWithArgsAndRunScript(void* p0, void* p1, struct StreamHeader* buffer, int length, void* p4, short p5) {
    char local[0x430];
    data_02108d04.fieldC = p0;
    data_02108d04.field8 = p4;
    data_02108d04.field0 = p5;
    data_02108d04.field4 = p1;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f0a3c);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
}
