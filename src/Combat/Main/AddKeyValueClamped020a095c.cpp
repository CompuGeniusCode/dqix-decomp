#include <globaldefs.h>

struct S_a0af4;
short FindKeyIndex020a0af4(struct S_a0af4* p, int key);

struct KeyMap020a095c { short* keys; signed char* vals; short count; };

// USA: func_020a095c
ARM int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount) {
    short* keys = map->keys;
    signed char* vals = map->vals;
    short count = map->count;
    short idx;
    int ret;
    if (key < 0) {
        return 0;
    }
    if (amount <= 0) {
        return 0;
    }
    ret = 0;
    idx = FindKeyIndex020a0af4((struct S_a0af4*)map, key);
    if (idx >= 0) {
        ret = 1;
        if (vals[idx] < 99) {
            signed char room = 99 - vals[idx];
            if (amount > room) amount = room;
            vals[idx] += amount;
        }
    } else {
        short i;
        for (i = 0; i < count; i++) {
            if (keys[i] < 0) {
                keys[i] = key;
                vals[i] = amount;
                ret = 1;
                break;
            }
        }
    }
    return ret;
}
