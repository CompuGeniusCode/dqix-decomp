#include <globaldefs.h>
#include "std_library_functions.h"

int GetData02104304Field4();
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
extern int data_020f2a1c;
extern int data_020f2a14;

struct ElemFields_021e05e4 {
    unsigned int pad0[2];
    unsigned int lowBits : 4;
    unsigned int rest : 28;
};

// USA: func_ov023_021e05e4
ARM int ClearBufferAndCheckField_021e05e4(void* obj) {
    int listPtr = GetData02104304Field4();

    if (*(unsigned short*)((char*)obj + 0x774) & 0x1000) return 8;
    if (*(void**)((char*)obj + 0x4c) == 0) return 3;

    memset((char*)obj + 0x630, 0, 0x100);

    int result = CallFunc0202fa38Mode2(listPtr, data_020f2a1c, data_020f2a14, 0);
    *(int*)((char*)obj + 0x740) = result;

    unsigned int fieldVal = ((struct ElemFields_021e05e4*)(*(void**)((char*)obj + 0x4c)))->lowBits;
    int cond = fieldVal <= 7;
    if (cond != 0) return 3;

    if (*(unsigned short*)((char*)obj + 0x774) & 0x400) return 3;
    return 8;
}
