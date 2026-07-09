#include <globaldefs.h>

struct Field4Low12_02097420 {
    unsigned int pad0;
    unsigned int value : 12;
};

// USA: func_02097420
ARM int GetField4Low12(struct Field4Low12_02097420* obj) {
    return obj->value;
}
