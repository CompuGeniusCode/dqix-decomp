#include <globaldefs.h>
#include "std_library_functions.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};

struct Struct02030b7c {
    int field0;
    void* field4;
};

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);
void* GetField4IfField0Zero(struct Struct02030b7c* s);
struct TaggedValue02030b44* ConvertTaggedVec3ToFx32(struct TaggedValue02030b44* obj, int* outVec);

struct DestStruct0208daf4 {
    unsigned char byte0;
    char pad1;
    unsigned short short2;
    unsigned char raw[0x10];
    unsigned char byte0x14;
    char pad2[3];
    float floatField;
    int vec[3];
    unsigned short short0x28;
    unsigned short short0x2a;
};

struct Data02108fc8Struct {
    int status;
    unsigned short* refPtr;
    struct DestStruct0208daf4* dest;
};

extern struct Data02108fc8Struct data_02108fc8;

// USA: func_0208daf4
ARM int PopulateElementStructFromTaggedValues0208daf4(struct TaggedValue02030b44* obj) {
    int a, b, c, e;
    void* d;
    unsigned short ref;
    struct TaggedValue02030b44* next;

    if (data_02108fc8.status == 1) {
        return 0;
    }

    a = GetIntFromVariant02030b0c((struct Variant02030b0c*)(obj + 0));
    b = GetIntFromVariant02030b0c((struct Variant02030b0c*)(obj + 1));
    c = GetIntFromVariant02030b0c((struct Variant02030b0c*)(obj + 2));

    ref = *data_02108fc8.refPtr;
    if (b != ref && c != ref) {
        return 0;
    }

    data_02108fc8.dest->byte0 = (unsigned char)a;
    data_02108fc8.dest->short2 = (unsigned short)b;
    data_02108fc8.dest->short0x2a = (unsigned short)c;

    d = GetField4IfField0Zero((struct Struct02030b7c*)(obj + 3));
    memcpy(data_02108fc8.dest->raw, d, 0x10);
    data_02108fc8.dest->raw[0xf] = 0;

    e = GetIntFromVariant02030b0c((struct Variant02030b0c*)(obj + 4));
    data_02108fc8.dest->byte0x14 = (unsigned char)e;

    data_02108fc8.dest->floatField = GetTaggedValueAsFloat((struct TaggedValue02030b44*)(obj + 5));

    next = ConvertTaggedVec3ToFx32(obj + 6, data_02108fc8.dest->vec);
    data_02108fc8.dest->short0x28 = (unsigned short)(int)(4096.0f * GetTaggedValueAsFloat(next));

    data_02108fc8.status = 1;
    return 1;
}
