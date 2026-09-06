#include <globaldefs.h>

struct NibbleElem02098eac {
    char pad[0xc];
    unsigned int field0 : 4;
    unsigned int nibble : 4;
    char pad2[0xe8 - 0x10];
};

// USA: func_02098eac
ARM int CountNibble0xcEqualsA(struct NibbleElem02098eac* arr) {
    int count = 0;
    int i;
    for (i = 0; i < 30; i++) {
        if (arr[i].nibble == 0xa) {
            count++;
        }
    }
    return count;
}
