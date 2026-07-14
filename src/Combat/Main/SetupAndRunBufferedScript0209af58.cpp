#include <globaldefs.h>

struct LocalStruct0209af58 {
    void* field0;
    int field4;
    int field8;
};
extern struct LocalStruct0209af58* data_02109bac;

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(void* state, void* dataPtr);
extern char data_020f1680[];

// USA: func_0209af58
ARM void SetupAndRunBufferedScript0209af58(void* param0, struct StreamHeader* param1, int param2, int param3, int param4) {
    if (param1 != 0) {
        struct LocalStruct0209af58 local;
        char buf[0x430];

        data_02109bac = &local;
        data_02109bac->field0 = param0;
        data_02109bac->field4 = param4;
        data_02109bac->field8 = 0;

        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, data_020f1680);
        InitBufferReader((struct StreamState*)buf, param1, param2);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
}
