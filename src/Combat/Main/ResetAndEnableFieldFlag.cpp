#include <globaldefs.h>

struct FieldFlagBlock {
    char unk[0x63DC];
    union {
        unsigned char raw;
        struct {
            unsigned char active : 1;
        } bits;
    } flags;
};

// USA: func_02011b24
ARM void ResetAndEnableFieldFlag(struct FieldFlagBlock* block) {
    block->flags.raw = 0;
    block->flags.bits.active = 1;
}
