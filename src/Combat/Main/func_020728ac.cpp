#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_020f0cc8;

struct Data02108db0 {
    unsigned char f0;
    char pad1;
    short f2;
    int f4;
    int f8;
    int fc;
    int f10;
};
extern struct Data02108db0 data_02108db0;

// USA: func_020728ac
extern "C" ARM void func_020728ac(int param0, int param1, struct StreamHeader* buffer, int length, int stack5, unsigned short stack6, unsigned char stack7) {
    char local[0x430];
    data_02108db0.f10 = param0;
    data_02108db0.fc = param1;
    data_02108db0.f8 = stack5;
    data_02108db0.f2 = stack6;
    data_02108db0.f4 = 0;
    data_02108db0.f0 = stack7;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020f0cc8);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
}
