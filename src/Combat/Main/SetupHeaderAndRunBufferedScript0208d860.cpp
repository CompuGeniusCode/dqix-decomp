#include <globaldefs.h>

struct StreamHeader0208d860 {
    unsigned int w0;
    unsigned short h4;
    unsigned short h6;
    unsigned int w8;
    unsigned short hc;
    unsigned short he;
};

struct Data02108fc0Type {
    void* field0;
    struct StreamHeader0208d860* field4;
};
extern struct Data02108fc0Type data_02108fc0;
extern int data_020f121c;

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

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(void* p, void* q);

// USA: func_0208d860
ARM void SetupHeaderAndRunBufferedScript0208d860(struct StreamHeader0208d860* header, void* param1, struct StreamHeader* buffer, int length, int param4, short param5, unsigned short param6) {
    if (param1 != 0 && buffer != 0 && length != 0) {
        data_02108fc0.field4 = header;
        header->w8 = param4;
        data_02108fc0.field4->hc = param5;
        data_02108fc0.field4->he = param6;
        data_02108fc0.field0 = param1;
        struct ResetStruct local;
        ResetFieldsReturnTrue(&local);
        func_0203066c(&local, &data_020f121c);
        InitBufferReader((struct StreamState*)&local, buffer, length);
        RunLoopIfValid02030774((struct Struct02030774*)&local);
    }
}
