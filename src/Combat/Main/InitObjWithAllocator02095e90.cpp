#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int CallFunc0202fa38ZeroPad(int a, int b, int c);
int GetData02104304Field4();
extern int data_020f1474;

struct Obj02095e90 {
    char pad[0xa8];
    void* fieldA8;
    char pad2[0x4c4 - 0xa8 - 4];
    int field4c4;
};

// USA: func_02095e90
ARM int InitObjWithAllocator02095e90(struct Obj02095e90* obj, SafeAllocator* allocator) {
    void* ptr = allocator->Allocate(0x198);
    obj->fieldA8 = ptr;
    if (ptr == NULL) {
        return 0;
    }
    memset(ptr, 0, 0x198);
    obj->field4c4 = CallFunc0202fa38ZeroPad(GetData02104304Field4(), (int)&data_020f1474, 0);
    return 1;
}
