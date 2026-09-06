#include <globaldefs.h>

struct FlagBlob02027bac {
    unsigned char pad[0xa97];
    unsigned char flags;
};

// USA: func_02027bac
ARM void SetFlagsAt0xa97(struct FlagBlob02027bac* p, unsigned char flags) {
    p->flags |= flags;
}
