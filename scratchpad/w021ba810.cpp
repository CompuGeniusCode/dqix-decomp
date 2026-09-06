#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct Data_ov017_021d8438 {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    unsigned char pad3;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
};
extern struct Data_ov017_021d8438 data_ov017_021d8438;
extern signed char data_ov017_021d7c54[2];
extern int data_ov017_021d7c58;

// USA: func_ov017_021ba810
ARM int SomeFunc_021ba810(struct StreamHeader* a, int b, int c, int d, int e, int f, int g) {
    char local[0x430];
    if (c < 0 || c > 0x3e7) return 0;

    struct Data_ov017_021d8438* s = &data_ov017_021d8438;
    s->field4 = d;
    s->field1c = c;
    s->field8 = e;
    s->field10 = 0;
    s->field14 = 0;
    s->field18 = f;
    s->field20 = g;
    s->field2 = 0;
    data_ov017_021d7c54[0] = -1;
    s->field0 = 0;
    s->field1 = 0;
    s->fieldC = 0;
    data_ov017_021d7c54[1] = -1;

    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_ov017_021d7c58);
    InitBufferReader((struct StreamState*)local, a, b);
    RunLoopIfValid02030774((struct Struct02030774*)local);

    return data_ov017_021d8438.field10 ? data_ov017_021d8438.field10 : data_ov017_021d8438.field14;
}
