#include <globaldefs.h>

struct Header020dffb8 {
    unsigned int count : 12;
    unsigned int rest : 20;
};

// USA: func_020dffb8
ARM int GetArrayByteSize020dffb8(struct Header020dffb8 *obj) {
    return obj->count * 8;
}
