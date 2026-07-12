#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct CallbackCache0214e33c {
    short field0;
    short pad2;
    void* field4;
    void* field8;
    void* fieldC;
};
extern struct CallbackCache0214e33c data_0214e33c;
extern int data_020f2308;

// USA: func_020d7870
ARM void RegisterCallbackObjectAndRunScript(void* p0, void* p1, struct StreamHeader* p2, int p3, unsigned char flag) {
    char local[0x430];
    data_0214e33c.fieldC = p0;
    data_0214e33c.field8 = p1;
    if (flag == 0) {
        data_0214e33c.field4 = (char*)p0 + 4;
        data_0214e33c.field0 = *(short*)((char*)p0 + 0x14);
    }
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020f2308);
    InitBufferReader((struct StreamState*)local, p2, p3);
    RunLoopIfValid02030774((struct Struct02030774*)local);
}
