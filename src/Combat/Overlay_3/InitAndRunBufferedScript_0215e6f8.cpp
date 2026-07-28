#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_ov003_02180cb8;
extern int data_ov003_0217ff40;

// USA: func_ov003_0215e6f8  (semantic: InitAndRunBufferedScript_0215e6f8)
extern "C" ARM void func_ov003_0215e6f8(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)((char*)&data_ov003_02180cb8 + 4) = handler0;
    *(int*)&data_ov003_02180cb8 = handler1;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_ov003_0217ff40);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
}
