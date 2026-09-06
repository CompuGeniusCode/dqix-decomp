#include <globaldefs.h>

struct Element020dffc8 {
    int a;
    int b;
};

struct Container020dffc8 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Element020dffc8 *elements;
};

typedef int (*ElementCallback020dffc8)(struct Container020dffc8 *, struct Element020dffc8 *);

// USA: func_020dffc8
ARM int ForEachElement020dffc8(struct Container020dffc8 *self, ElementCallback020dffc8 cb) {
    int count;
    struct Element020dffc8 *elem;
    int i;

    elem = self->elements;
    if (elem == NULL || (count = self->count) == 0 || cb == NULL) return 0;
    for (i = 0; i < count; i++, elem++) {
        cb(self, elem);
    }
    return 1;
}
