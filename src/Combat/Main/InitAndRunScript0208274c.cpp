#include <globaldefs.h>
#include "std_library_functions.h"

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct Data02108ee8 {
    int field0;
    int field4;
    int field8;
    void* fieldC;
    int field10;
};
extern struct Data02108ee8 data_02108ee8;
extern int data_020f0ff8;

// USA: func_0208274c
ARM int InitAndRunScript0208274c(void* param0, struct StreamHeader* param1, int param2, int param3) {
    char local[0x430];
    memset(param0, 0, 0x54);
    data_02108ee8.field10 = 0;
    data_02108ee8.field4 = 0;
    data_02108ee8.field8 = param3;
    data_02108ee8.fieldC = param0;
    data_02108ee8.field0 = 0;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020f0ff8);
    InitBufferReader((struct StreamState*)local, param1, param2);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    return 0;
}
