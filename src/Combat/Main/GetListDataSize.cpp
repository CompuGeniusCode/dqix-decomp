#include <globaldefs.h>

struct Struct02070af4 {
    unsigned int count : 12;
};

// USA: func_02070af4
ARM int GetListDataSize(struct Struct02070af4* p) {
    return p->count * 0x84;
}
