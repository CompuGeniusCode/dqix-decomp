#include <globaldefs.h>

// USA: func_0202053c
ARM unsigned short GetTableValue(void* obj) {
    char* p = *(char**)((char*)obj + 0x150);
    int index = *(int*)(p + 0x950);
    return *(unsigned short*)(p + index * 2 + 0x16c);
}
