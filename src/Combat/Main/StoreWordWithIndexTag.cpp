#include <globaldefs.h>

extern unsigned int data_0210a0b8;

// USA: func_020b38ec
ARM void StoreWordWithIndexTag(int index, unsigned int value) {
    (&data_0210a0b8)[index] = value | (index << 30);
}
