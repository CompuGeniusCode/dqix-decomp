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
extern "C" void* func_02012fe4(void);

struct Data02108fc8Type {
    int field0;
    int field4;
    int field8;
};
extern struct Data02108fc8Type data_02108fc8;
extern int data_020f1248;

// USA: func_0208dc00
ARM int InitStreamAndRun0208dc00(struct StreamHeader* param0, int param1, int param2) {
    data_02108fc8.field8 = param2;
    data_02108fc8.field0 = 0;
    data_02108fc8.field4 = *(int*)((char*)func_02012fe4() + 8);
    struct ResetStruct local;
    _ZN6Script10InitializeEv(&local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f1248);
    _ZN6Script4LoadEPKvj((struct StreamState*)&local, param0, param1);
    _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
    return data_02108fc8.field0;
}
