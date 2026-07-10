#include <globaldefs.h>

extern "C" void func_020bf148(void* obj, int arg);

// USA: func_020bec58
ARM void NotifyObjectIfPresent020bec58(void* volatile* slot, int arg) {
    if (*slot != NULL) {
        func_020bf148(*slot, arg);
    }
}
