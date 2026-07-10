#include <globaldefs.h>

struct Pair020afd88 {
    void* container;
    unsigned int index;
};

struct Container020afd88 {
    char pad[0x60];
    void* arr;
};

extern "C" int func_020cc9c8(void* self, struct Pair020afd88 s);

// USA: func_020afd88
ARM int CallIfIndexInBounds020afd88(void* self, struct Container020afd88* container, unsigned int index) {
    int result = 0;
    if (index < *(unsigned short*)((char*)container->arr + 8)) {
        struct Pair020afd88 s;
        s.container = container;
        s.index = index;
        result = func_020cc9c8(self, s);
    }
    return result;
}
