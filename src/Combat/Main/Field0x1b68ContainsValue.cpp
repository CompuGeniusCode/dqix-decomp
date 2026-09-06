#include <globaldefs.h>

struct ValueList02098e3c {
    char pad[0x1b68];
    unsigned int arr[3];
};

// USA: func_02098e3c
ARM int Field0x1b68ContainsValue(struct ValueList02098e3c* s, int val) {
    int i;
    for (i = 0; i < 3; i++) {
        if (val == s->arr[i]) {
            return 1;
        }
    }
    return 0;
}
