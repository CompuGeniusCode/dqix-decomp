#include <globaldefs.h>
void InitActorContext0209c20c(struct Actor0209c20c*);

void FreeAndReinit0203a950(void*);

// USA: func_0209c278
ARM void ResetAndReinit0209c278(void* obj) {
    InitActorContext0209c20c((struct Actor0209c20c*)(obj));
    FreeAndReinit0203a950(obj);
}
