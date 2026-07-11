#include <globaldefs.h>

extern "C" void func_0205e324(void* obj);
extern "C" void func_0205e180(void* obj);

// USA: func_0202c814
ARM void* ReleaseBattleArray0202c814(void* obj) {
    func_0205e324(obj);
    func_0205e180((char*)obj + 0x1518);
    func_0205e180((char*)obj + 0x150c);
    func_0205e180((char*)obj + 0x1500);
    return obj;
}
