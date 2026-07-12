#include <globaldefs.h>

struct Struct02030b7c;
extern void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct Table02034768;
extern int FindEntryByName02034768(struct Table02034768* table, const char* name);

struct TaggedValue02030b44;
extern float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

struct Variant02030b0c;
extern int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern "C" void func_020348ec(struct Table02034768* table, void* payload);

struct GlobalTableSlot02104b10_34548 {
    void* alloc;
    struct Table02034768* table;
};
extern struct GlobalTableSlot02104b10_34548 data_02104b10;

struct Payload02034548 {
    short variantValue;
    short nameIndex;
    short scaledValue;
    int unused;
};

// USA: func_02034548
ARM int LookupAndDispatchEntryB(struct Struct02030b7c* param) {
    struct Payload02034548 payload;
    const char* name;
    int index;
    float floatVal;
    int scaled;
    int variantValue;

    name = (const char*)GetField4IfField0Zero(param);
    index = FindEntryByName02034768(data_02104b10.table, name);
    payload.nameIndex = (short)index;

    floatVal = GetTaggedValueAsFloat((struct TaggedValue02030b44*)((char*)param + 8));
    scaled = (int)(4096.0f * floatVal);
    payload.scaledValue = (short)scaled;

    variantValue = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x10));
    payload.variantValue = (short)variantValue;

    func_020348ec(data_02104b10.table, &payload);
    return 1;
}
