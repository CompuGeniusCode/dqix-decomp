#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_020ef2bc;
extern int data_020ef2c0;

struct Data020fdc14 {
    int field0;
    void* field4;
    int field8;
};
extern struct Data020fdc14 data_020fdc14;

// USA: func_0201c724  (semantic: InitAndRunScript0201c724)
extern "C" ARM void func_0201c724(int param0, void* param1, struct StreamHeader* param2, int param3) {
    char local[0x430];
    data_020fdc14.field4 = param1;
    data_020ef2bc = param0;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020ef2c0);
    InitBufferReader((struct StreamState*)local, param2, param3);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    data_020fdc14.field4 = 0;
    data_020ef2bc = -1;
}
