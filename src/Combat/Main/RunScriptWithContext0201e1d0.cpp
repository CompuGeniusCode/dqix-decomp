#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct Ctx020fdc20 { int field0; int field4; int field8; };
extern struct Ctx020fdc20 data_020fdc20;
extern int data_020ef388;

// USA: func_0201e1d0
ARM void RunScriptWithContext0201e1d0(struct StreamHeader* buffer, int length, int c, int d) {
    char local[0x430];
    if (length == 0) return;
    data_020fdc20.field8 = c;
    data_020fdc20.field4 = d;
    data_020fdc20.field0 = 0;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020ef388);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    data_020fdc20.field8 = 0;
    data_020fdc20.field4 = 0;
    data_020fdc20.field0 = 0;
}
