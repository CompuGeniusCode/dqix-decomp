#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern unsigned char data_ov004_021707e8;

// USA: func_ov004_02163284
ARM int SetFieldsAndFlagBit0_02163284(void* a) {
    *(int*)((char*)&data_ov004_021707e8 + 0x20) = -1;
    *(int*)((char*)&data_ov004_021707e8 + 0x24) = 0;
    unsigned char* node = (unsigned char*)func_ov004_0215e47c(a, 9);
    node[0xc] |= 1;
    return 0;
}
