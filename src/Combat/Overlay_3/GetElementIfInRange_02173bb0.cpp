#include <globaldefs.h>

struct Obj02173bb0 {
    unsigned char pad0[0x40];
    char* field40;
    unsigned char pad1[0xa];
    unsigned short field4e;
};

// USA: func_ov003_02173bb0
ARM void* GetElementIfInRange_02173bb0(Obj02173bb0* obj, unsigned int index) {
    char* base = obj->field40;
    char* result = NULL;
    if (base != NULL) {
        if (index < obj->field4e) {
            result = base + index * 0x28;
        }
    }
    return result;
}
