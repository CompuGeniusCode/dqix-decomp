#include <globaldefs.h>

struct KeyedList0207caa4;
int FindEntryIndexInKeyedList0207caa4(struct KeyedList0207caa4* base, int value, int key);

struct KeyedList0207c484 {
    char pad0[0xbd0];
    short* valueArrays[8];
    signed char* countArrays[8];
    short counts[8];
    unsigned char keys[8];
};

// USA: func_0207c484
ARM int DecrementKeyedStackAmount0207c484(struct KeyedList0207c484* obj, int value, int amount, int key) {
    int idx;
    int i;
    int result;
    signed char* countArr;

    if (amount <= 0) {
        return 0;
    }

    result = FindEntryIndexInKeyedList0207caa4((struct KeyedList0207caa4*)obj, value, key);
    if (result < 0) {
        return 0;
    }

    for (i = 0; i < 8; i++) {
        if (key == obj->keys[i]) {
            idx = i;
            break;
        }
    }

    countArr = obj->countArrays[idx];
    countArr[result] = countArr[result] - amount;
    if (countArr[result] <= 0) {
        obj->valueArrays[idx][result] = -1;
        countArr[result] = 0;
    }

    return 1;
}
