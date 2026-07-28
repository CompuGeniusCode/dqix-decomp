#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void*);
struct Obj021e1318;
void ClearObj_021e1318(Obj021e1318* obj);

// USA: func_ov023_021fc1f4  (semantic: SetTypeAndClear_021fc1f4)
extern "C" ARM int func_ov023_021fc1f4(void* obj, void* unused, short arg3, short arg4) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0x12;
    *(unsigned short*)((char*)obj + 0x6) = arg3;
    *(unsigned short*)((char*)obj + 0x8) = arg4;
    ClearObj_021e1318((Obj021e1318*)((char*)obj + 0x20));
    return 1;
}
