#include <globaldefs.h>

struct Element_1f2a4 {
    char unk[0x20];
};

struct Manager_1f2a4 {
    char unk[0xc];
    struct Element_1f2a4* elements;
    int count;
};

// USA: func_0201f2a4
ARM struct Element_1f2a4* GetElementByIndexStride0x20(struct Manager_1f2a4* manager, int index) {
    if (index < 0 || manager->count <= index) {
        return 0;
    }
    return &manager->elements[index];
}
