#include <globaldefs.h>

struct Struct020444bc {
    char pad0[0x78];
    int field78;
    char pad7c[0x9a0 - 0x7c];
    int field9a0;
};

// USA: func_020444bc
ARM void SetField9a0AndIncrementField78(struct Struct020444bc* s) {
    s->field9a0 = 5;
    s->field78 = s->field78 + 1;
}
