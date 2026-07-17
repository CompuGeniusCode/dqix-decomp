#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220ee50
ARM void* FindNodeByField4_0220ee50(int arg) {
    char *base = (char*)GetData0224e53c_0220d60c() + 0x2000;
    void *listHead = *(void**)(base + 0x270);
    if (listHead == 0) {
        return 0;
    }
    unsigned int cnt = *(unsigned int*)(base + 0x274);
    if (cnt <= 0xc) {
        return 0;
    }
    char *node = *(char**)((char*)listHead + 4);
    if (node == 0) {
        return 0;
    }
    do {
        if (*(int*)(node + 4) == arg) {
            break;
        }
        node = *(char**)(node + 0xc);
    } while (node != 0);
    return node;
}
