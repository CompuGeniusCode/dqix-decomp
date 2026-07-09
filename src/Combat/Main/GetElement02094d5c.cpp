#include <globaldefs.h>

struct GetElement02094d5cElem { char pad[0x14]; };
struct GetElement02094d5cList { struct GetElement02094d5cElem* elems; };

// USA: func_02094d5c
ARM struct GetElement02094d5cElem* GetElement02094d5c(struct GetElement02094d5cList* list, int index) {
    return list->elems + index;
}
