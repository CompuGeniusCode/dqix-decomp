#include <globaldefs.h>

struct Field0Low12_02079b94 {
    unsigned int value : 12;
};

// USA: func_02079b94
ARM int GetField0Low12Times60(struct Field0Low12_02079b94* obj) {
    return obj->value * 60;
}
