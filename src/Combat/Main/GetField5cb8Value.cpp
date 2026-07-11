#include <globaldefs.h>

// USA: func_02010804
ARM int GetField5cb8Value(char* obj) {
    return *(int*)(obj + 0x5cb8);
}
