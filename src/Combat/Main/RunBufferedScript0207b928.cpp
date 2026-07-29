#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_02108e60;
extern int data_020f0ed8;

// USA: func_0207b928
extern "C" ARM void func_0207b928(struct StreamHeader* param0, int param1, int param2) {
    if (param1 != 0) {
        char local[0x430];
        data_02108e60 = param2;
        ResetFieldsReturnTrue((struct ResetStruct*)local);
        func_0203066c((struct ResetStruct*)local, &data_020f0ed8);
        InitBufferReader((struct StreamState*)local, param0, param1);
        RunLoopIfValid02030774((struct Struct02030774*)local);
        data_02108e60 = 0;
    }
}
