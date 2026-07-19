#include <globaldefs.h>

struct Obj021f6f08;
unsigned int GetShort6_021f6f08(struct Obj021f6f08*);

// USA: func_ov023_021f6880  (semantic: FindNodeByShort6_021f6880)
extern "C" ARM void* func_ov023_021f6880(void** list, int value) {
    void* node = *list;
    while (node != 0) {
        if ((int)GetShort6_021f6f08((struct Obj021f6f08*)node) == value) return node;
        node = *(void**)((char*)node + 0x18);
    }
    return 0;
}
