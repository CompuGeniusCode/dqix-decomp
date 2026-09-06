#include <globaldefs.h>

struct Struct_0205d67c;
int GetFlagB4_0205d67c(struct Struct_0205d67c* p);
extern "C" void func_ov002_02156e90(void* obj);

// USA: func_ov002_02156ff0
ARM void ClearMatchingEntry_02156ff0(unsigned char* obj, int key) {
    while (GetFlagB4_0205d67c((struct Struct_0205d67c*)(obj + 0x2c8 + 0xc00))) {
        if (*(int*)(obj + 0x1000 + 0xbb8) == key) {
            return;
        }
        func_ov002_02156e90(obj);
    }
}
