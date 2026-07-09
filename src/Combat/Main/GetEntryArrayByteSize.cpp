#include <globaldefs.h>

struct Header0206f0f8 {
    unsigned int count : 12;
    unsigned int rest : 20;
};

// USA: func_0206f0f8
ARM int GetEntryArrayByteSize(struct Header0206f0f8 *obj) {
    return obj->count * 0x1C;
}
