#include <globaldefs.h>

struct SearchStruct;
struct Obj_021bd3a4 { unsigned char pad0[2]; unsigned char f2; unsigned char f3; unsigned char pad1[0x96]; unsigned char f9a; };

struct F8Bits_021925e0 {
    unsigned int low27 : 27;
    unsigned int high5 : 5;
};

extern "C" char* func_ov017_0218b5b0(void);
extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" int func_0202c540(struct SearchStruct* obj);
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);

// USA: func_ov017_021925e0
extern "C" ARM int func_ov017_021925e0(void) {
    char* base = func_ov017_0218b5b0();
    unsigned char* obj = *(unsigned char**)(base + 0x3000 + 0x734);
    if (!func_0202c540(func_0202ae18())) {
        goto ret0;
    }
    if (HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)obj)) {
        if (*(unsigned char*)(obj + 0x101) == 0) {
            goto ret0;
        }
    } else {
        goto ret0;
    }
    if (*(unsigned char*)(obj + 0x101) == 0) {
        goto skip;
    }
    if (((struct F8Bits_021925e0*)(obj + 0xf8))->low27 & 4) {
        goto ret0;
    }
skip:
    if (obj[0xff] != 0) {
        goto ret0;
    }
    if (obj[0xcf] != 2) {
        return 1;
    }
ret0:
    return 0;
}
