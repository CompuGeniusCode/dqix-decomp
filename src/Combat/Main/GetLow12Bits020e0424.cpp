#include <globaldefs.h>

struct Header020e0424 {
    unsigned int lowBits : 12;
    unsigned int rest : 20;
};

// USA: func_020e0424
ARM unsigned int GetLow12Bits020e0424(struct Header020e0424* obj) {
    return obj->lowBits;
}
