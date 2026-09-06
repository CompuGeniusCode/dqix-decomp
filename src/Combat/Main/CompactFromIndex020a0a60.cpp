#include <globaldefs.h>

struct KeyMap020a0a60 {
    short* keys;
    signed char* vals;
    short count;
};

// USA: func_020a0a60
ARM void CompactFromIndex020a0a60(struct KeyMap020a0a60* map, short i) {
    short* keys = map->keys;
    signed char* vals = map->vals;
    int count = map->count;
    short j;
    for (; i < count - 1; i++) {
        if (vals[i] == 0) {
            for (j = i + 1; j < count; j++) {
                if (vals[j] != 0) {
                    keys[i] = keys[j];
                    vals[i] = vals[j];
                    keys[j] = -1;
                    vals[j] = 0;
                    break;
                }
            }
        }
    }
}
