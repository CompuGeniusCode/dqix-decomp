#include <globaldefs.h>

struct Substruct020416cc {
    int value;
};

struct Holder020416cc {
    char unk[0x18];
    struct Substruct020416cc* substruct;
};

// USA: func_020416cc
ARM int GetField0OfSubstructAt0x18(struct Holder020416cc* holder) {
    struct Substruct020416cc* substruct = holder->substruct;
    return substruct != 0 ? substruct->value : 0;
}
