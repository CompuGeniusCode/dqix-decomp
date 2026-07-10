#include <globaldefs.h>

void* SetGlobalContext02110370(void* value);
int ScaleField0x160By1000(void* obj);

// USA: func_0203adfc
ARM int IsScaledFieldPositive0203adfc(void* obj, void* target) {
    int result;
    if (*(int*)obj == 0) return 0;
    SetGlobalContext02110370((char*)obj + 4);
    if (target != NULL) {
        result = ScaleField0x160By1000(target);
    } else {
        result = ScaleField0x160By1000((char*)obj + 0x9c);
    }
    return result > 0 ? 1 : 0;
}
