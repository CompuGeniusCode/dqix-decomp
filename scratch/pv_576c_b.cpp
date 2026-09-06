#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct Struct02109404 {
    unsigned char field0;
    char pad1;
    unsigned char field2;
    char pad3[0xc - 3];
    void* fieldC;
};
extern struct Struct02109404 data_02109404;
extern short data_020f13d8;
extern int data_020f1444;

// USA: func_0209576c
ARM void InitAndRunScript0209576c(void* obj, void* param1, struct StreamHeader* header, int length, unsigned char flag) {
    char local[0x430];
    if (param1 != 0 && header != 0 && length != 0) {
        struct Struct02109404* d = &data_02109404;
        d->fieldC = param1;
        *(int*)((char*)obj + 0xa4) = 0;
        d->field0 = flag;
        d->field2 = 0;
        struct ResetStruct* rs = (struct ResetStruct*)local;
        data_020f13d8 = -1;
        ResetFieldsReturnTrue(rs);
        func_0203066c((struct ResetStruct*)local, &data_020f1444);
        InitBufferReader((struct StreamState*)local, header, length);
        RunLoopIfValid02030774((struct Struct02030774*)local);
    }
}
