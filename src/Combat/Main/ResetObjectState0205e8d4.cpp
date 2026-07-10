#include <globaldefs.h>

void FreeAndReinit0203a950(void* obj);
struct Obj_0205e88c;
void InitDisplayState0205e88c(struct Obj_0205e88c*);

// USA: func_0205e8d4
ARM void ResetObjectState0205e8d4(void* obj) {
    FreeAndReinit0203a950(obj);
    InitDisplayState0205e88c((struct Obj_0205e88c*)obj);
}
