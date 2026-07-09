#include <globaldefs.h>

struct Elem020c01ac { int f0; int f4; int f8; };
struct List020c01ac {
    char pad[0x1c];
    unsigned int count;
    struct Elem020c01ac elems[1];
};

// USA: func_020c01ac
ARM struct Elem020c01ac *GetValidElement020c01ac(struct List020c01ac *list, int index) {
    struct Elem020c01ac *e;
    if (index < 0) {
        return NULL;
    }
    if (index >= list->count) {
        return NULL;
    }
    e = &list->elems[index];
    if (e->f0 == -1) {
        return NULL;
    }
    return e;
}
