#include <globaldefs.h>
#include "std_library_functions.h"

void ShiftInBitOnGlobalObject();
void HalveGlobalObjectCounter(void);
extern "C" int func_0207568c(void* a, void* b, int* out);
extern "C" void func_020d3c84(void* obj, int header, int len);

extern int data_020f22e0;
extern int data_020f22f4;

struct Obj020d3c28 {
    unsigned char pad[0xb4];
    int fieldB4;
};

// USA: func_020d3c28
ARM void InitAndMaybeStartStream020d3c28(struct Obj020d3c28* obj) {
    int localVar;
    int result;
    memset(obj, 0, 0xb4);
    obj->fieldB4 = 0;
    ShiftInBitOnGlobalObject();
    result = func_0207568c(&data_020f22e0, &data_020f22f4, &localVar);
    if (result != 0) {
        func_020d3c84(obj, result, localVar);
    }
    HalveGlobalObjectCounter();
}
