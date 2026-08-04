#include <globaldefs.h>
#include "std_library_functions.h"

struct Coords020de7a4;
int ComputeOffsetFromFields(Coords020de7a4* obj);

struct Container020de7d0;
struct Element020de7d0;
typedef void (*Callback020de7d0)(Container020de7d0*, Element020de7d0*);
int IterateEntries020de7d0(Container020de7d0* c, Callback020de7d0 cb);

struct List020de714 {
    char pad0[8];
    unsigned int field8;
    void* field_c;
    void* field_10;
};

// USA: func_020de714  (semantic: InitContainerFromSource_020de714)
extern "C" ARM int func_020de714(struct List020de714* self, struct List020de714* src, unsigned char* outFlag, Callback020de7d0 callback) {
    *outFlag = 0;
    if (src == 0) return 0;
    memcpy(self, src, 0xc);
    self->field_c = (char*)src + 0xc;
    self->field_10 = (char*)src + (ComputeOffsetFromFields((Coords020de7a4*)self) + 0xc);
    if ((unsigned int)self->field8 >> 31) {
        *outFlag = 1;
        return 1;
    }
    IterateEntries020de7d0((Container020de7d0*)self, callback);
    self->field8 = (self->field8 & ~0x80000000) | 0x80000000;
    src->field8 = (src->field8 & ~0x80000000) | 0x80000000;
    return 1;
}
