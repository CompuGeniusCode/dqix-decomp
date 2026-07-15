#include <globaldefs.h>

void FreeObjectSlot0204715c(char* obj);

// USA: func_ov017_021b65bc
ARM void CheckFlag3ThenFree_021b65bc(char* obj) {
    if (*(unsigned char*)(obj + 0xfc) != 3) {
        return;
    }
    FreeObjectSlot0204715c(obj + 0xc);
}
