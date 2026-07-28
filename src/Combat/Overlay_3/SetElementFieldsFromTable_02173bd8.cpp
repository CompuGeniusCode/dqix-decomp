#include <globaldefs.h>

extern "C" void* _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j(void*, unsigned int);
extern "C" void func_0205ac40(void*, void*);
extern signed char data_ov003_0217fa14[];

// USA: func_ov003_02173bd8  (semantic: SetElementFieldsFromTable_02173bd8)
extern "C" ARM void func_ov003_02173bd8(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int index;
    void* elem;
    if (o[0xec] == 0) {
        return;
    }
    if (o[0xec] == 1) {
        if (o[0xee] < 2) {
            return;
        }
    }
    if (o[0xd4] > 3) {
        return;
    }
    index = data_ov003_0217fa14[o[0xd4]];
    elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + 0x130, index);
    *(int*)((char*)elem + 0x14) = 0xb8000;
    *(int*)((char*)elem + 0x18) = 0x2f000;
    func_0205ac40((char*)obj + 0x130, elem);
}
