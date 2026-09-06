#include <globaldefs.h>

struct ObjStruct_021d98e0 {
    char pad0[4];
    int field4;
    unsigned short field8;
};

struct GlobalCtx_021d98e0 {
    void* objPtr;
    void* p1;
};

struct ResetStruct_021d98e0 {
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

struct StreamHeader_021d98e0 {
    int field0;
    int size;
};

struct StreamState_021d98e0 {
    char pad[0xC];
    struct StreamHeader_021d98e0* buffer;
    int length;
    struct StreamHeader_021d98e0* cursor;
    void* dataStart;
    void* dataEnd;
    int field20;
};

extern GlobalCtx_021d98e0 data_ov028_021d9bc4;
extern int data_ov028_021d9ac0;

extern "C" int ResetFieldsReturnTrue(struct ResetStruct_021d98e0*);
extern "C" int InitBufferReader(struct StreamState_021d98e0*, struct StreamHeader_021d98e0*, int);
extern "C" void func_0203066c(void*, void*);
extern "C" void func_02030774(void*);

// USA: func_ov028_021d98e0
ARM void InitStreamStructAndReader_021d98e0(ObjStruct_021d98e0* obj, void* p1, struct StreamHeader_021d98e0* p3, int p4) {
    GlobalCtx_021d98e0* g = &data_ov028_021d9bc4;
    obj->field4 = 0;
    obj->field8 = 0;
    g->objPtr = obj;
    g->p1 = p1;

    struct {
        union {
            struct ResetStruct_021d98e0 reset;
            struct StreamState_021d98e0 state;
        };
    } local;

    ResetFieldsReturnTrue(&local.reset);
    func_0203066c(&local, &data_ov028_021d9ac0);
    InitBufferReader(&local.state, p3, p4);
    func_02030774(&local);
}
