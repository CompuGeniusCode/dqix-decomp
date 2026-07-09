#include <globaldefs.h>

struct ArrayHeader0207ef60 {
    unsigned int data;
    unsigned short count;
    unsigned short capacity;
};

// USA: func_0207ef60
ARM void InitArrayHeader(struct ArrayHeader0207ef60* arr) {
    arr->data = 0;
    arr->capacity = 0;
    arr->count = 0;
}
