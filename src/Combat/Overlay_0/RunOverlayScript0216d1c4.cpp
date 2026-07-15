#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_ov000_02184264;
extern int data_ov000_02183b5c;

// USA: func_ov000_0216d1c4
ARM void RunOverlayScript0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out) {
    char local[0x430];
    *(int*)((char*)&data_ov000_02184264 + 0x8) = arg0;
    *(int*)((char*)&data_ov000_02184264 + 0x4) = 0;
    *(int*)((char*)&data_ov000_02184264 + 0x0) = 0;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_ov000_02183b5c);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    *out = *(int*)&data_ov000_02184264;
}
