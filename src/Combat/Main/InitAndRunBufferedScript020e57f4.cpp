#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_021536c4;
extern int data_020f2e2c;

// USA: func_020e57f4
ARM int InitAndRunBufferedScript020e57f4(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)((char*)&data_021536c4 + 4) = handler0;
    *(int*)&data_021536c4 = handler1;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020f2e2c);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    return 0;
}
