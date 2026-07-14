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

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(void* p, void* q);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);

extern int data_020f05bc;

struct Obj02064574 {
    char pad[0x480];
    int f480;
    int f484;
    int f488;
    int f48c;
};

struct LocalC02064574 {
    char pad0[0xc];
    int fieldC;
    char pad2[0x24];
};

// USA: func_02064574
ARM void SomeInit02064574(struct Obj02064574* obj, int p1, struct StreamHeader* p2, int p3, int p4, int p5, int p6) {
    if (p1 != 0 && p2 != 0 && p3 != 0) {
        obj->f480 = p1;
        obj->f484 = p4;
        obj->f488 = p5;
        obj->f48c = p6;
        struct ResetStruct local;
        ResetFieldsReturnTrue(&local);
        func_0203066c(&local, &data_020f05bc);
        InitBufferReader((struct StreamState*)&local, p2, p3);
        RunLoopIfValid02030774((struct Struct02030774*)&local);
        struct LocalC02064574 c;
        c.fieldC = p4;
        if (LookupAndForEachNode020649b0(obj, 0x14, &c)) {
            func_0206f81c(&c);
        }
    }
}
