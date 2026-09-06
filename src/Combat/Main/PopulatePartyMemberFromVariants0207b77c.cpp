#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" ARM int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" ARM float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct Inner0205111c { unsigned int v[3]; };
struct Foo0205111c { unsigned short a; struct Inner0205111c mid; unsigned char e; };
ARM struct Foo0205111c* CopyStruct0205111c(struct Foo0205111c* dst, struct Foo0205111c* src);

extern int data_02108e60;

#define TBL(off) (*(unsigned short*)(*(char**)&data_02108e60 + (idx << 1) + 0x100 + (off)))

// USA: func_0207b77c
ARM int PopulatePartyMemberFromVariants0207b77c(struct Variant02030b0c* src) {
    int idx = _ZNK6Script9Parameter5ToIntEv(src);

    struct Foo0205111c stage1;
    stage1.e = (unsigned char)(_ZNK6Script9Parameter5ToIntEv(src + 1) != 0);
    *(float*)&stage1.mid.v[0] = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(src + 2));
    *(float*)&stage1.mid.v[1] = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(src + 3));
    *(float*)&stage1.mid.v[2] = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(src + 4));
    stage1.a = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 5);
    CopyStruct0205111c((struct Foo0205111c*)(*(char**)&data_02108e60 + 0x8c) + idx, &stage1);

    struct Foo0205111c stage2;
    stage2.e = (unsigned char)(_ZNK6Script9Parameter5ToIntEv(src + 6) != 0);
    *(float*)&stage2.mid.v[0] = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(src + 7));
    *(float*)&stage2.mid.v[1] = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(src + 8));
    *(float*)&stage2.mid.v[2] = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(src + 9));
    stage2.a = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 10);
    CopyStruct0205111c((struct Foo0205111c*)(*(char**)&data_02108e60) + idx, &stage2);

    unsigned short v58 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 11);
    unsigned short v60 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 12);
    unsigned short v68 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 13);
    unsigned short v70 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 14);
    unsigned short v78 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 15);
    unsigned short v80 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(src + 16);
    int v88 = _ZNK6Script9Parameter5ToIntEv(src + 17);

    TBL(0x26) = v58;
    TBL(0x34) = v60;
    TBL(0x18) = v68;
    TBL(0x42) = v70;
    TBL(0x50) = v78;
    TBL(0x5e) = v80;
    TBL(0x6c) = v88;

    return 1;
}
