#include <globaldefs.h>

void FreeAndReinit0203a950(void* obj);
extern "C" void func_0205e88c(void* obj);

// USA: func_0205e8d4
ARM void ResetObjectState0205e8d4(void* obj) {
    FreeAndReinit0203a950(obj);
    func_0205e88c(obj);
}
