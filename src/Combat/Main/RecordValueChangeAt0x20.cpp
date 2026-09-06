#include <globaldefs.h>

struct HalfwordRecord02052884 {
    char pad[0x20];
    short current;
    short previous;
    short latest;
    short kind;
    short counter;
};

// USA: func_02052884
ARM void RecordValueChangeAt0x20(struct HalfwordRecord02052884* rec, short value, short kind) {
    if (kind == 0 || value == rec->current) {
        rec->current = value;
        rec->previous = value;
        rec->latest = value;
        rec->kind = 0;
        rec->counter = 0;
        return;
    }
    rec->previous = rec->current;
    rec->latest = value;
    rec->kind = kind;
    rec->counter = 0;
}
