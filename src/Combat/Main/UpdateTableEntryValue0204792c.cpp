#include <globaldefs.h>
#include "std_library_functions.h"

struct Table020480b8;
int FindEntryIndexByName020480b8(struct Table020480b8* table, char* key);
extern "C" unsigned long long _u32_div_f(unsigned int a, unsigned int b);
extern int data_02114e50;

struct RowEntry0204792c { int f0; int value; int f8; };
struct TableEntry0204792c { int f0; struct RowEntry0204792c* rows; };

struct SelfObj792c {
    char pad0[0xc];
    struct TableEntry0204792c* entries;
    char pad10[0x70 - 0x10];
    int row;
    int index;
    int value78;
    int range;
    char pad80[0x84 - 0x80];
    unsigned char flags84 : 1;
};

// USA: func_0204792c  (semantic: UpdateTableEntryValue0204792c)
extern "C" ARM void func_0204792c(struct SelfObj792c* self, char* name) {
    if (!self->flags84) {
        return;
    }
    int idx = FindEntryIndexByName020480b8((struct Table020480b8*)((char*)self + 0x14), name);
    if (self->index == idx || idx == 0) {
        return;
    }
    self->index = idx;
    self->row = 0;
    self->value78 = data_02114e50;
    self->range = self->entries[self->index].rows[self->row].value;
    unsigned long long dm = _u32_div_f((unsigned int)rand(), (unsigned int)self->range);
    self->value78 = self->value78 - (unsigned int)(dm >> 32);
}
