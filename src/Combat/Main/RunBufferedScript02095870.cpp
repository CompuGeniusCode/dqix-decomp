#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(void* state, void* dataPtr);

struct DataStruct02109404_95870 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short f6;
};
extern struct DataStruct02109404_95870 data_02109404;
extern short data_020f13d8;
extern char data_020f13fc[];

// USA: func_02095870
ARM int RunBufferedScript02095870(void* unused, struct StreamHeader* buffer, int length, int flag, unsigned char* outByte) {
    char local[0x430];

    data_02109404.f6 = 0;
    data_02109404.f1 = 0;
    data_02109404.f2 = 0;
    data_020f13d8 = (short)flag;

    if (flag <= 0) {
        return 1;
    }

    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c(local, data_020f13fc);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);

    *outByte = data_02109404.f2;
    return 0;
}
