#include <globaldefs.h>

extern "C" long long func_020c8d5c(void);

struct StateObj0201fc40 {
    unsigned char state;
    unsigned char f1;
    unsigned char f2;
    unsigned char pad3;
    unsigned short f4;
    unsigned short pad6;
    long long f8;
};

// USA: func_0201fc40
ARM void ResetStateTimer0201fc40(struct StateObj0201fc40* p, int arg) {
    if (p->f2 != 0) return;
    if (p->state == 1 || p->state == 4) {
        p->f1 = 3;
        p->f4 = arg;
        p->f8 = func_020c8d5c();
        return;
    }
    if (p->state == 3 || p->state == 2) {
        p->f4 = arg;
        p->f8 = func_020c8d5c();
    }
}
