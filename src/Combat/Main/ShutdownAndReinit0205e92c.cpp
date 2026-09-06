#include <globaldefs.h>

struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(struct Obj_0205e8ec*);
void FreeAndReinit0203a950(void*);

// USA: func_0205e92c
ARM void ShutdownAndReinit0205e92c(void* obj) {
    RefreshDisplayState0205e8ec((struct Obj_0205e8ec*)obj);
    FreeAndReinit0203a950(obj);
}
