#include <globaldefs.h>

struct ReadClearByte02098ee8 {
    char pad[0x1b61];
    unsigned char flag;
};

// USA: func_02098ee8
ARM unsigned char ReadAndClearByte0x1b61(struct ReadClearByte02098ee8* s) {
    unsigned char old = s->flag;
    s->flag = 0;
    return old;
}
