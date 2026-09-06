#include <globaldefs.h>

struct Obj020bd984;
void DestroyAllocator020bd984(struct Obj020bd984*);
void InitObjectFields0203a914(void*);

// USA: func_0203a950
ARM void FreeAndReinit0203a950(void* obj) {
    void* p = *(void**)obj;
    if (p != NULL) {
        DestroyAllocator020bd984((struct Obj020bd984*)p);
    }
    InitObjectFields0203a914(obj);
}
