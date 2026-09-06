#include <globaldefs.h>

struct Obj020bdac0;
int SaveStateAndAllocateChild020bdac0(struct Obj020bdac0*);

// USA: func_0203aa64
ARM int GetFromField00203aa64(void* obj) {
    void* p = *(void**)obj;
    if (p == NULL) return 0;
    return SaveStateAndAllocateChild020bdac0((struct Obj020bdac0*)p);
}
