#include <globaldefs.h>

struct Entry0209bdc8 {
    unsigned int f0;
    unsigned int state : 3;
    unsigned int : 10;
    unsigned int mask : 8;
    unsigned int : 11;
    char pad[0x18];
};

struct Container0209bdc8 {
    struct Entry0209bdc8 entries[6];
    int count;
};

// USA: func_0209bdc8
ARM struct Entry0209bdc8* FindActiveEntry0209bdc8(struct Container0209bdc8* c, int flag, unsigned int mask) {
    unsigned int want = (flag == 0);
    int i;
    for (i = 0; i < c->count; i++) {
        struct Entry0209bdc8* e = &c->entries[i];
        if (want == e->state || e->state == 2) {
            if (mask & e->mask) {
                return e;
            }
        }
    }
    return 0;
}
