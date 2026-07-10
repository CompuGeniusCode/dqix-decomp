#include <globaldefs.h>

struct List0207ec28;
void DrainThreeLists0207ec28(struct List0207ec28*);
void ResetStruct02034d04(unsigned char* obj);

// USA: func_02037138
ARM void ResetStreamContext02037138(unsigned char* obj) {
    if (*(void**)(obj + 8)) DrainThreeLists0207ec28((struct List0207ec28*)*(void**)(obj + 8));
    *(int*)(obj + 0x10) = 0;
    *(char*)(obj + 0x18) = -1;
    *(int*)(obj + 0x14) = 0;
    ResetStruct02034d04(obj + 0x2c);
}
