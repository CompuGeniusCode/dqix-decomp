#include <globaldefs.h>
#include "std_library_functions.h"

struct Elem0203066c { unsigned int key; int val; };
struct Obj0203066c { int count; struct Elem0203066c* list; };

// USA: func_0203066c  (semantic: SortListAndCount_0203066c)
extern "C" ARM int func_0203066c(struct Obj0203066c* obj, struct Elem0203066c* arr) {
    int count;
    struct Elem0203066c* q;
    int bound, swapped;
    struct Elem0203066c* p;
    int i;
    struct Elem0203066c temp;

    if (arr == 0) {
        return 0;
    }
    obj->list = arr;

    count = 0;
    q = arr;
    while (q->key != 0) {
        q++;
        count++;
    }
    obj->count = count;

    bound = count - 1;
    do {
        swapped = 0;
        p = arr;
        for (i = 0; i < bound; i++, p++) {
            if (p[0].key > p[1].key) {
                swapped = 1;
                memcpy(&temp, p, 8);
                memcpy(p, p + 1, 8);
                memcpy(p + 1, &temp, 8);
            }
        }
    } while (swapped && (bound--, 1));
    return 1;
}
