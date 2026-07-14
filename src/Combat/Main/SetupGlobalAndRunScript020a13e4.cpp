#include <globaldefs.h>

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

extern "C" void func_0203066c(void* p, void* q);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

void ShiftInBitOnGlobalObject();
void HalveGlobalObjectCounter(void);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

struct Global02109d94_020a13e4 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldC;
};
extern struct Global02109d94_020a13e4 data_02109d94;

extern int data_020f1917;
extern int data_020f192c;
extern int data_020f18ec;

// USA: func_020a13e4
ARM void SetupGlobalAndRunScript020a13e4(void* param0, void* param1, int param2, unsigned short param3, unsigned char param4) {
    if (param1 != 0) {
        int localVar;
        void* result;
        data_02109d94.field4 = param0;
        data_02109d94.field8 = param1;
        data_02109d94.fieldC = param2;
        data_02109d94.field2 = param3;
        data_02109d94.field0 = param4;
        ShiftInBitOnGlobalObject();
        localVar = 0;
        result = ExtractFileFromGP2((const char*)&data_020f1917, (const char*)&data_020f192c, (unsigned int*)&localVar);
        if (result != 0) {
            struct ResetStruct local;
            ResetFieldsReturnTrue(&local);
            func_0203066c(&local, &data_020f18ec);
            InitBufferReader((struct StreamState*)&local, (struct StreamHeader*)result, localVar);
            RunLoopIfValid02030774((struct Struct02030774*)&local);
        }
        HalveGlobalObjectCounter();
    }
}
