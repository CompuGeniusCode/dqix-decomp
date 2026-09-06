#include <globaldefs.h>
#include "std_library_functions.h"

struct SearchNode0207afbc {
    char pad[0xac];
    char name[0x54];
    struct SearchNode0207afbc* next;
};

// USA: func_0207afbc
ARM SearchNode0207afbc* FindNodeByName0207afbc(SearchNode0207afbc** head, const char* name) {
    SearchNode0207afbc* n;
    if (name == NULL) return NULL;
    n = *head;
    while (n != NULL) {
        if (strcmp(name, n->name) == 0) return n;
        n = n->next;
    }
    return NULL;
}
