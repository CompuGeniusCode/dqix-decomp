#include <globaldefs.h>

struct Element020dfa68 {
    int a;
    int b;
};

struct Container020dfa68 {
    unsigned short count;
    unsigned short pad2;
    int pad4;
    struct Element020dfa68 *elements;
};

typedef int (*ElementCallback020dfa68)(struct Container020dfa68 *, struct Element020dfa68 *);

// USA: func_020dfa68
ARM int ForEachElement020dfa68(struct Container020dfa68 *self, ElementCallback020dfa68 cb) {
    int count;
    struct Element020dfa68 *elem;
    int i;

    elem = self->elements;
    if (elem == NULL || (count = self->count) == 0 || cb == NULL) return 0;
    for (i = 0; i < count; i++, elem++) {
        cb(self, elem);
    }
    return 1;
}
