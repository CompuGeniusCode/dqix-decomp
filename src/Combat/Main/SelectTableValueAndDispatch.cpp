#include <globaldefs.h>

extern "C" void func_02010288(void*, unsigned int);
extern unsigned int data_020f33b4[];

// USA: func_02010364
ARM void SelectTableValueAndDispatch(char* obj, int index) {
    if (index < 4) {
        unsigned int table[4];
        *(int*)(obj + 0x3dc) = index;
        table[0] = data_020f33b4[5];
        table[1] = data_020f33b4[4];
        table[2] = data_020f33b4[3];
        table[3] = data_020f33b4[2];
        func_02010288(obj, table[index]);
    }
}
