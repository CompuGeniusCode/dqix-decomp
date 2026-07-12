#include <globaldefs.h>

void* NotifyThenResetNameTable(void* obj);
void* ResetNameTableThenNotify(void* obj);
extern "C" void func_0200ee94(void* obj, int a, int b, void* cb1, void* cb2);
extern "C" void func_02039e7c(void* obj);

// USA: func_0203a878
ARM void* InitTwoSubObjectsWithCallbacks0203a878(void* obj) {
    func_0200ee94(obj, 5, 0x88, (void*)ResetNameTableThenNotify, (void*)NotifyThenResetNameTable);
    func_0200ee94((char*)obj + 0x2a8, 5, 0x88, (void*)ResetNameTableThenNotify, (void*)NotifyThenResetNameTable);
    func_02039e7c(obj);
    return obj;
}
