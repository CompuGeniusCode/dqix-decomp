#include <globaldefs.h>

extern "C" void func_02015554(void* a, void* b);

// USA: func_02015518
ARM void ForEachElement02015518(void* a, char* list) {
    int count = *(int*)(list + 0x14);
    int i;
    for (i = 0; i < count; i++) {
        func_02015554(a, *(char**)(list + 0x44) + i * 0x70);
    }
}
