#include <globaldefs.h>

struct Element020a939c {
    unsigned char data[0x40];
};

struct Container020a939c {
    unsigned int count : 12;
    struct Element020a939c *elements;
};

// USA: func_020a939c
ARM struct Element020a939c* GetIndexedElement020a939c(struct Container020a939c *c, int index) {
    if (index < 0 || index >= (int)c->count || c->elements == 0) {
        return 0;
    }
    return &c->elements[index];
}
