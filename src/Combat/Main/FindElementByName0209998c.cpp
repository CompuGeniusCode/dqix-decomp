#include <globaldefs.h>
#include "std_library_functions.h"

struct Elem0209998c {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    char f5[7];
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char pad;
};

struct List0209998c {
    struct Elem0209998c* data;
    int count;
    int cap;
};

// USA: func_0209998c
ARM struct Elem0209998c* FindElementByName0209998c(struct List0209998c* list, const char* name) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Elem0209998c* elem = &list->data[i];
        if (strcmp(elem->f5, name) == 0) return elem;
    }
    return NULL;
}
