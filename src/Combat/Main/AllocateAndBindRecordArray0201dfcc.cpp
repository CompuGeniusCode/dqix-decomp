#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct SetFieldsStruct;
extern "C" void _ZN12ZoneFeatures21SetOpcode7bAllocationEPNS_13Opcode7bEntryEt(struct SetFieldsStruct* p, int value, short id);
typedef void (*SetFields0x84And0x82_U)(struct SetFieldsStruct*, int, unsigned short);

struct GlobalCtx0201dfcc {
    int field0;
    SafeAllocator* alloc;           // 0x4
    struct SetFieldsStruct* fields; // 0x8
};
extern struct GlobalCtx0201dfcc data_020fdc20;

// USA: func_0201dfcc
extern "C" ARM int _Z20WarpScript_Opcode_7bPN6Script9ParameterEi(struct Variant02030b0c* variant) {
    unsigned int count = _ZNK6Script9Parameter5ToIntEv(variant);
    void* p = data_020fdc20.alloc->Allocate(count * 0x2c);
    if (p == NULL) return 0;
    ((SetFields0x84And0x82_U)_ZN12ZoneFeatures21SetOpcode7bAllocationEPNS_13Opcode7bEntryEt)(data_020fdc20.fields, (int)p, count);
    return 1;
}
