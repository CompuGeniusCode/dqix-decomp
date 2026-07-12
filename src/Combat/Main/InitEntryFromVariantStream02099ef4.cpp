#include <globaldefs.h>

struct Variant02099ef4 { int tag; union { int i; float f; } value; };

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct TaggedValue02030b44;
struct TaggedValue02030b44* ConvertTaggedVec3ToFx16(struct TaggedValue02030b44* obj, short* outVec);

struct Entry02099ef4 {
    unsigned char field0;
    unsigned char field1;
    short vec0[3];
    short vec1[3];
    unsigned char field0e;
    char pad;
    short vec2[3];
    short vec3[3];
};

extern struct Entry02099ef4 data_02109a54[];

// USA: func_02099ef4
ARM int InitEntryFromVariantStream02099ef4(struct Variant02099ef4* p) {
    int id;
    struct Entry02099ef4* entry;
    struct Variant02099ef4* cursor;

    id = GetIntFromVariant02030b0c((struct Variant02030b0c*)p);
    entry = &data_02109a54[id];
    entry->field0 = (unsigned char)id;

    entry->field1 = (unsigned char)GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 1));

    cursor = (struct Variant02099ef4*)ConvertTaggedVec3ToFx16((struct TaggedValue02030b44*)(p + 2), entry->vec0);
    cursor = (struct Variant02099ef4*)ConvertTaggedVec3ToFx16((struct TaggedValue02030b44*)cursor, entry->vec1);

    entry->field0e = (unsigned char)GetIntFromVariant02030b0c((struct Variant02030b0c*)cursor);

    cursor = (struct Variant02099ef4*)ConvertTaggedVec3ToFx16((struct TaggedValue02030b44*)(cursor + 1), entry->vec2);
    ConvertTaggedVec3ToFx16((struct TaggedValue02030b44*)cursor, entry->vec3);

    return 1;
}
