#include <globaldefs.h>

struct AllocIface022075f4 {
    void* unk0;
    void* unk4;
    void* unk8;
    void* (*allocate)(void*, unsigned int);
};

extern AllocIface022075f4 data_ov031_0224e234;

// USA: func_ov031_022075f4
ARM void* AllocateWithSizeHeader_022075f4(unsigned int size) {
    unsigned int total = size + 4;
    void* ptr = data_ov031_0224e234.allocate(0, total);
    if (ptr != NULL) {
        *(unsigned int*)ptr = total;
        ptr = (char*)ptr + 4;
    }
    return ptr;
}
