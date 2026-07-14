#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct SetFieldsStruct;
void SetFields0x84And0x82(struct SetFieldsStruct* p, int value, short id);
typedef void (*SetFields0x84And0x82_U)(struct SetFieldsStruct*, int, unsigned short);

struct GlobalCtx0201dfcc {
    int field0;
    SafeAllocator* alloc;           // 0x4
    struct SetFieldsStruct* fields; // 0x8
};
extern struct GlobalCtx0201dfcc data_020fdc20;

// USA: func_0201dfcc
ARM int AllocateAndBindRecordArray0201dfcc(struct Variant02030b0c* variant) {
    unsigned int count = GetIntFromVariant02030b0c(variant);
    void* p = data_020fdc20.alloc->Allocate(count * 0x2c);
    if (p == NULL) return 0;
    ((SetFields0x84And0x82_U)SetFields0x84And0x82)(data_020fdc20.fields, (int)p, count);
    return 1;
}
