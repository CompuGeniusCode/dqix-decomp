#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;


struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

struct DataStruct02109404_95ee0 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short f6;
};
extern struct DataStruct02109404_95ee0 data_02109404;
extern char data_020f13fc[];

struct Ctx02095ee0 {
    char pad0[0xa8];
    int fieldA8;
    char pad_ac[0x4c4 - 0xac];
    int field4c4;
};

// USA: func_02095ee0
ARM int RunOrPollScript02095ee0(struct Ctx02095ee0* ctx) {
    char local[0x430];
    int id = (int)BackgroundLoader::GetInstance();
    int out1, out2;
    int i;

    if (ctx->field4c4 < 0) {
        return -1;
    }

    if (((BackgroundLoader*)(id))->GetTaskStatus((int)(ctx->field4c4)) != 0) {
        ((BackgroundLoader*)((struct List0202fec8*)id))->GetLoadedFileByID((int)(ctx->field4c4), (void**)(&out1), (unsigned int*)(&out2));

        data_02109404.f6 = 0;
        data_02109404.f1 = 0;

        if (ctx->fieldA8 == 0) {
            ((BackgroundLoader*)(id))->RemoveTask((int)(ctx->field4c4));
            ctx->field4c4 = -1;
            return 2;
        }

        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(local, data_020f13fc);
        _ZN6Script4LoadEPKvj((struct StreamState*)local, (struct StreamHeader*)out1, out2);
        _ZN6Script7ExecuteEv((struct Struct02030774*)local);
        ((BackgroundLoader*)(id))->RemoveTask((int)(ctx->field4c4));
        ctx->field4c4 = -1;

        for (i = 0; i < data_02109404.f6; i++) {}
        return 1;
    }

    return (((BackgroundLoader*)(id))->GetTaskStatus((int)(ctx->field4c4)) == -1) ? 2 : 0;
}
