#include <globaldefs.h>

struct Element020e545c {
    unsigned int w[4];
};

struct ElementList020e545c {
    unsigned int count : 12;
    unsigned int pad : 20;
    struct Element020e545c* elements;
};

typedef void (*ElementCallback020e545c)(struct ElementList020e545c*, struct Element020e545c*);

// USA: func_020e545c
ARM int InvokeCallbackPerElement020e545c(struct ElementList020e545c* list, ElementCallback020e545c callback) {
    int count;
    struct Element020e545c* element = list->elements;
    int i;
    if (!(element != NULL && (count = list->count) != 0 && callback != NULL)) {
        return 0;
    }
    i = 0;
    while (i < count) {
        callback(list, element);
        i++;
        element++;
    }
    return 1;
}
