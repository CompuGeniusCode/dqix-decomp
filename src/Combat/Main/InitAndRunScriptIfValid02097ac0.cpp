#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct Data021098e0 {
    void* field0;
    void* field4;
};
extern struct Data021098e0 data_021098e0;
extern int data_020f14dc;

// USA: func_02097ac0
ARM void InitAndRunScriptIfValid02097ac0(void* param0, void* param1, struct StreamHeader* param2, int param3) {
    char local[0x430];
    if (param2 != 0 && param3 != 0) {
        data_021098e0.field4 = param0;
        data_021098e0.field0 = &param1;
        ResetFieldsReturnTrue((struct ResetStruct*)local);
        func_0203066c((struct ResetStruct*)local, &data_020f14dc);
        InitBufferReader((struct StreamState*)local, param2, param3);
        RunLoopIfValid02030774((struct Struct02030774*)local);
    }
}
