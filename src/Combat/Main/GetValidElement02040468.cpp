#include <globaldefs.h>

struct Element02040468 {
    char unk[0x38];
    int flag;
};

struct List02040468 {
    unsigned int count;
    int unk4;
    struct Element02040468* elements;
};

// USA: func_02040468
ARM struct Element02040468* GetValidElement02040468(struct List02040468* list, int index) {
    struct Element02040468* elements = list->elements;
    struct Element02040468* element;
    if (elements == 0) {
        return 0;
    }
    if (index < 0 || list->count <= (unsigned int)index) {
        return 0;
    }
    element = &elements[index];
    if (element->flag < 0) {
        element = 0;
    }
    return element;
}
