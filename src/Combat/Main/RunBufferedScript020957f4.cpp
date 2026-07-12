#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(void* state, void* dataPtr);

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

    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c(local, data_020f13dc);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);

    return data_02109404.f6;
}
