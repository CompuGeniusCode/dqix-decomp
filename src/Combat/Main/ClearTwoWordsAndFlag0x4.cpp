#include <globaldefs.h>

struct FlagsAndWords0202ea20 {
    char pad0[0x168];
    unsigned int field168;
    char pad1[0x78];
    int field1e4;
    int field1e8;
};

// USA: func_0202ea20
ARM void ClearTwoWordsAndFlag0x4(struct FlagsAndWords0202ea20* p) {
    p->field1e4 = 0;
    p->field1e8 = 0;
    p->field168 &= ~0x4;
}
