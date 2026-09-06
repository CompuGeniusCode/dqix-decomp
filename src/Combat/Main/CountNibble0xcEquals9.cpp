#include <globaldefs.h>

struct NibbleElem02098e70 {
    char pad[0xc];
    unsigned int field0 : 4;
    unsigned int nibble : 4;
    char pad2[0xe8 - 0x10];
};

// USA: func_02098e70
ARM int CountNibble0xcEquals9(struct NibbleElem02098e70* arr) {
    int count = 0;
    int i;
    for (i = 0; i < 30; i++) {
        if (arr[i].nibble == 9) {
            count++;
        }
    }
    return count;
}
