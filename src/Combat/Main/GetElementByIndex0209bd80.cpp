#include <globaldefs.h>

struct GetElementByIndex0209bd80Element { char pad[0x20]; };
struct GetElementByIndex0209bd80Container { struct GetElementByIndex0209bd80Element elems[6]; int count; };

// USA: func_0209bd80
ARM struct GetElementByIndex0209bd80Element* GetElementByIndex0209bd80(struct GetElementByIndex0209bd80Container *c, int index) {
    if (c->count <= index) return NULL;
    return &c->elems[index];
}
