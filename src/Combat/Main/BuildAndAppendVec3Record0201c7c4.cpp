#include <globaldefs.h>
#include "std_library_functions.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" extern struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);

struct Struct02030b7c;
extern "C" extern void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern "C" extern void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct WordTriple0201e304 { unsigned int v[3]; };
struct ByteBlock0201e304 { char v[16]; };
struct WordSix0201e304 { unsigned int v[6]; };
struct Entry0201e304 {
    unsigned int f0;
    struct WordTriple0201e304 g4;
    struct ByteBlock0201e304 a;
    struct ByteBlock0201e304 b;
    struct ByteBlock0201e304 c;
    struct WordSix0201e304 g40;
};
struct Container0201e304;
extern "C" extern void _ZN12ZoneFeatures19CreateOpcode64EntryERKNS_13Opcode64EntryE(struct Container0201e304* c, struct Entry0201e304* src);

struct GlobalCtx0201c7c4 {
    int pad0;
    void* pad4;
    struct Container0201e304* c;
};
extern struct GlobalCtx0201c7c4 data_020fdc20;

// USA: func_0201c7c4
extern "C" ARM int _Z20WarpScript_Opcode_65PN6Script9ParameterEi(unsigned char* arg0, int count) {
    char* extra1;
    char* extra2;
    int id;
    int vec3[3];
    unsigned char* ret;
    char* name;

    id = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)arg0);
    ret = (unsigned char*)_ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)(arg0 + 8), vec3);
    arg0 = ret + 8;
    name = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)ret);
    extra1 = NULL;
    extra2 = NULL;
    if (count >= 6) {
        extra1 = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)arg0);
        arg0 += 8;
    }
    if (count >= 7) {
        extra2 = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)arg0);
    }
    if (name == NULL) return 0;

    {
        struct Entry0201e304 entry;
        entry.f0 = id;
        _ZN8Vector3iaSERKS_((int*)&entry.g4, vec3);
        strcpy(entry.a.v, name);
        if (extra1 == NULL) entry.b.v[0] = 0; else strcpy(entry.b.v, extra1);
        if (extra2 == NULL) entry.c.v[0] = 0; else strcpy(entry.c.v, extra2);
        _ZN12ZoneFeatures19CreateOpcode64EntryERKNS_13Opcode64EntryE(data_020fdc20.c, &entry);
    }
    return 1;
}
