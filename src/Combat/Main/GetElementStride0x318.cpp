#include <globaldefs.h>

struct Element0x318_02028bac {
    unsigned char data[0x318];
};

// USA: func_02028bac
ARM struct Element0x318_02028bac* GetElementStride0x318(struct Element0x318_02028bac* base, int index) {
    if (index < 0 || index >= 4) {
        return NULL;
    }
    return &base[index];
}
