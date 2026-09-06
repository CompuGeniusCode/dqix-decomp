#include <globaldefs.h>

extern int data_020f10f8;
extern int data_020f1118;
extern int data_020f1108;
extern "C" void func_0208af78(void*);

// USA: func_0208b508
ARM void* InitObjectTables0208b508(void* obj) {
    *(int**)((char*)obj + 0x4)  = &data_020f10f8;
    *(int**)((char*)obj + 0x24) = &data_020f1118;
    *(int**)((char*)obj + 0x40) = &data_020f1118;
    *(int**)((char*)obj + 0x5c) = &data_020f1108;
    *(int**)((char*)obj + 0x78) = &data_020f1118;
    func_0208af78(obj);
    return obj;
}
