#include <globaldefs.h>

struct ShortSetStruct0216fdf8 {
    char pad[4];
    short arr[64];
    int count;
};

// USA: func_ov000_0216fdf8
ARM void AppendUniqueShort0216fdf8(struct ShortSetStruct0216fdf8* s, int val) {
    int i;
    if (s->count > 0x3f) return;
    if (val <= 0) return;
    for (i = 0; i < s->count; i++) {
        if (val == s->arr[i]) return;
    }
    s->arr[s->count] = (short)val;
    s->count = s->count + 1;
}
