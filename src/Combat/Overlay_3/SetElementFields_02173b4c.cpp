#include <globaldefs.h>

extern "C" void* _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j(void*, unsigned int);
extern "C" void func_0205ac40(void*, void*);

// USA: func_ov003_02173b4c  (semantic: SetElementFields_02173b4c)
extern "C" ARM void func_ov003_02173b4c(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int flag;
    void* elem;
    if (o[0xec] == 0) {
        return;
    }
    if (o[0xec] == 1) {
        if (o[0xee] < 2) {
            return;
        }
    }
    flag = 6;
    if (o[0] != 0) {
        flag = 7;
    }
    elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + 0x130, flag);
    if (elem == 0) {
        return;
    }
    *(int*)((char*)elem + 0x14) = 0x44000;
    *(int*)((char*)elem + 0x18) = 0x5f000;
    func_0205ac40((char*)obj + 0x130, elem);
}
