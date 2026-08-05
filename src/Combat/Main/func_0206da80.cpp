#include <globaldefs.h>

struct Data02108cec0206da80 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    short half4;
    short half6;
    short half8;
    short halfa;
    short halfc;
    short pade;
    void* field10;
    void* field14;
};
extern struct Data02108cec0206da80 data_02108cec;

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);
extern "C" void func_0203066c(struct ResetStruct*, int*);
extern int data_020f0994;

// USA: func_0206da80
extern "C" ARM int func_0206da80(int* param0, unsigned char param1, unsigned char param2, unsigned char param3, int arg5, int arg6, struct StreamHeader* arg7, int arg8) {
    char local[0x430];
    if (data_02108cec.field10 != 0) {
        *param0 = 0;
        data_02108cec.halfa = 0;
        data_02108cec.half8 = -1;
        data_02108cec.half4 = -1;
        data_02108cec.half6 = -1;
    }
    *param0 = 0;
    data_02108cec.byte2 = param1;
    data_02108cec.byte1 = param2;
    data_02108cec.byte0 = param3;
    data_02108cec.halfc = arg5;
    data_02108cec.field10 = param0;
    data_02108cec.field14 = (void*)arg6;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020f0994);
    InitBufferReader((struct StreamState*)local, arg7, arg8);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    return 1;
}
