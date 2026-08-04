#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, void*);

extern char data_020efa48[];
extern char data_020efaa0[];

struct Struct02034980 {
    char unk[0x1c];
    void* buf;
};
void AllocateAndCopyString02034980(struct Struct02034980*, SafeAllocator*, char*);

struct GlobalStringSlot02104b10_461c {
    SafeAllocator* alloc;
    struct Struct02034980* dst;
};
extern struct GlobalStringSlot02104b10_461c data_02104b10;

// USA: func_0203461c  (semantic: SetupAndRunBufferedScript0203461c)
extern "C" ARM void func_0203461c(struct Struct02034980* dst, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    char local[0x430];
    if (length != 0 && buffer != 0) {
        data_02104b10.dst = dst;
        data_02104b10.alloc = alloc;
        ResetFieldsReturnTrue((struct ResetStruct*)local);
        func_0203066c((struct ResetStruct*)local, data_020efa48);
        InitBufferReader((struct StreamState*)local, buffer, length);
        RunLoopIfValid02030774((struct Struct02030774*)local);
        if (data_02104b10.dst->buf == 0) {
            AllocateAndCopyString02034980(data_02104b10.dst, alloc, (char*)data_020efaa0);
        }
        data_02104b10.dst = 0;
        data_02104b10.alloc = 0;
    }
}
