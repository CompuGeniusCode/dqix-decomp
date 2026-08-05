#include <globaldefs.h>

struct KeyedList0207caa4;
int FindEntryIndexInKeyedList0207caa4(struct KeyedList0207caa4* base, int value, int key);

struct KeyedList0207c378 {
    char pad0[0xbd0];
    short* valueArrays[8];
    signed char* countArrays[8];
    short counts[8];
    unsigned char keys[8];
};

// USA: func_0207c378  (semantic: IncrementKeyedStackAmount0207c378)
extern "C" ARM int func_0207c378(struct KeyedList0207c378* obj, int value, int amount, int key) {
    int found;
    signed char* countArr;
    int idx;
    int i;
    int result;
    short* values;
    short count;
    short j;

    if (amount <= 0) {
        return 0;
    }

    result = FindEntryIndexInKeyedList0207caa4((struct KeyedList0207caa4*)obj, value, key);
    if (result == -2) {
        return 0;
    }

    idx = -1;
    for (i = 0; i < 8; i++) {
        if (key == obj->keys[i]) {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        return 0;
    }

    countArr = obj->countArrays[idx];
    found = 0;
    if (result >= 0) {
        countArr[result] += amount;
        found = 1;
        if (countArr[result] > 0x63) {
            countArr[result] = 0x63;
        }
    } else {
        values = obj->valueArrays[idx];
        count = obj->counts[idx];
        for (j = 0; j < count; j++) {
            if (values[j] < 0) {
                values[j] = value;
                countArr[j] = amount;
                found = 1;
                if (countArr[j] > 0x63) {
                    countArr[j] = 0x63;
                }
                break;
            }
        }
    }
    return found;
}
