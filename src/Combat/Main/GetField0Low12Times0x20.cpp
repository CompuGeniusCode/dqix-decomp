#include <globaldefs.h>

struct Field0Low12_02097408 {
    unsigned int value : 12;
};

// USA: func_02097408
ARM int GetField0Low12Times0x20(struct Field0Low12_02097408* obj) {
    return obj->value * 0x20;
}
