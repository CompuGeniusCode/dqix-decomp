#include <globaldefs.h>

struct Element02047a3c {
    char pad0;
    unsigned char byte1;
    char pad2[6];
};

struct Owner02047a3c {
    char pad0[8];
    struct Element02047a3c* elements;
    char pad1[0x84 - 0xc];
    unsigned char enabled : 1;
    unsigned char flagsRest : 7;
};

// USA: func_02047a3c
ARM int GetElementByte1IfEnabled(struct Owner02047a3c* obj, int index) {
    if (obj->enabled) {
        return obj->elements[index].byte1;
    }
    return 0;
}
