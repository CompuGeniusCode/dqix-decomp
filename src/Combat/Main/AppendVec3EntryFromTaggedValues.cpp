#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02030b7c { int field0; void* field4; };
void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

struct Name020346f8 { unsigned char c[16]; };
struct Entry020346f8 {
    struct Name020346f8 name;
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
};
struct List020346f8 { struct Entry020346f8* entries; unsigned short count; unsigned short capacity; };
void AppendNamedEntry020346f8(struct List020346f8* list, struct Entry020346f8* src);

struct InputStruct020343d0 {
    struct Struct02030b7c hdr;      // offset 0, size 8
    struct TaggedValue02030b44 x;   // offset 8
    struct TaggedValue02030b44 y;   // offset 0x10
    struct TaggedValue02030b44 z;   // offset 0x18
};

struct Global02104b10View8 {
    char pad[4];
    struct List020346f8* list;
};
extern struct Global02104b10View8 data_02104b10;

// USA: func_020343d0
ARM int AppendVec3EntryFromTaggedValues(struct InputStruct020343d0* arg) {
    struct Entry020346f8 entry;
    char* name = (char*)GetField4IfField0Zero(&arg->hdr);
    if (name == NULL) {
        return 0;
    }
    strcpy((char*)&entry, name);
    entry.w0 = (unsigned int)(int)(4096.0f * GetTaggedValueAsFloat(&arg->x));
    entry.w1 = (unsigned int)(int)(4096.0f * GetTaggedValueAsFloat(&arg->y));
    entry.w2 = (unsigned int)(int)(4096.0f * GetTaggedValueAsFloat(&arg->z));
    entry.w3 = 0;
    entry.w4 = 0;
    AppendNamedEntry020346f8(data_02104b10.list, &entry);
    return 1;
}
