#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct0x10;
void ZeroStruct0x10(Struct0x10* obj);
void InitStruct020a8128(unsigned char* obj);

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);

struct Struct02030b7c { int field0; void* field4; };
extern "C" void* _ZNK6Script9Parameter8ToStringEv(Struct02030b7c* s);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" float _ZNK6Script9Parameter7ToFloatEv(TaggedValue02030b44* v);

int StringLength(const char* s);

struct Block020a825c { unsigned int v[4]; };
struct Elem020a825c {
    unsigned char b0, b1, b2, b3;
    unsigned int w4;
    Block020a825c block;
    unsigned short h18, h1a, h1c, gap1e;
    unsigned int w20, w24, w28;
};
struct List020a825c { Elem020a825c* base; unsigned short cap; unsigned short count; };
void AppendElement020a825c(List020a825c* list, Elem020a825c* src);

struct BssHolder020a7f88 { SafeAllocator* allocator; List020a825c* list; };
extern BssHolder020a7f88 data_02109fe0;
extern const char data_020f1b94;

// USA: func_020a7f88
ARM int PopulateElementFromVariantsAndAppend(unsigned char* src) {
    Elem020a825c elem;
    ZeroStruct0x10((Struct0x10*)&elem.block);
    InitStruct020a8128((unsigned char*)&elem);
    InitStruct020a8128((unsigned char*)&elem);

    elem.b0 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)src);
    elem.b2 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(src + 0x8));
    char* name = (char*)_ZNK6Script9Parameter8ToStringEv((Struct02030b7c*)(src + 0x10));
    elem.h18 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(src + 0x18));

    char* blk = (char*)&elem.block;
    *(short*)(blk + 0) = (short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(src + 0x20));
    *(short*)(blk + 2) = (short)(int)(_ZNK6Script9Parameter7ToFloatEv((TaggedValue02030b44*)(src + 0x28)) * 4096.0f);
    *(int*)(blk + 4) = (int)(_ZNK6Script9Parameter7ToFloatEv((TaggedValue02030b44*)(src + 0x30)) * 4096.0f);
    *(int*)(blk + 8) = (int)(_ZNK6Script9Parameter7ToFloatEv((TaggedValue02030b44*)(src + 0x38)) * 4096.0f);
    *(int*)(blk + 0xc) = (int)(_ZNK6Script9Parameter7ToFloatEv((TaggedValue02030b44*)(src + 0x40)) * 4096.0f);

    elem.h1a = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(src + 0x48));
    elem.h1c = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(src + 0x50));

    elem.w20 = (unsigned int)(int)(_ZNK6Script9Parameter7ToFloatEv((TaggedValue02030b44*)(src + 0x58)) * 4096.0f);
    elem.w24 = (unsigned int)(int)(_ZNK6Script9Parameter7ToFloatEv((TaggedValue02030b44*)(src + 0x60)) * 4096.0f);

    int len = StringLength(name);
    elem.w4 = (unsigned int)data_02109fe0.allocator->Allocate(len + 1);
    sprintf((char*)elem.w4, &data_020f1b94, name);
    ((char*)elem.w4)[len] = 0;

    AppendElement020a825c(data_02109fe0.list, &elem);
    return 1;
}
