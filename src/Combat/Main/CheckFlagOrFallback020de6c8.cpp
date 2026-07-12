#include <globaldefs.h>
int RemapSlotIndicesToPointers020de5b0(struct Container020de5b0*);

extern "C" void func_020de574(void);
extern "C" void func_020de714(void* a, void* b, unsigned char* out, void* fn);

// USA: func_020de6c8
ARM int CheckFlagOrFallback020de6c8(void* obj, void* a, void* b) {
    unsigned char flag;
    if (a == NULL || b == NULL) return 0;
    func_020de714(obj, a, &flag, (void*)func_020de574);
    if (flag != 0) return 1;
    return RemapSlotIndicesToPointers020de5b0((struct Container020de5b0*)(obj));
}
