#include <globaldefs.h>

struct Node02158d8c {
    char pad[0x1c];
    struct Node02158d8c* next;
};

// USA: func_ov006_02158d8c
ARM struct Node02158d8c* FindNodeOrMark_02158d8c(void* objRaw, short life) {
    char* obj = (char*)objRaw;
    struct Node02158d8c* n = *(struct Node02158d8c**)(obj + 0x30);
    short i = 0;
    while (n != NULL && life != 0) {
        if (n->next == NULL) {
            obj = obj + 0x300;
            *(short*)(obj + 0x6a) = i + 0x29;
            break;
        }
        life--;
        i++;
        n = n->next;
    }
    return n;
}
