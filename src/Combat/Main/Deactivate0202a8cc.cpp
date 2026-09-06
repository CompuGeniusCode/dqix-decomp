#include <globaldefs.h>

extern "C" void func_0202a6c4(void* obj);

typedef void (*Callback0202a8cc)(void* obj);

// USA: func_0202a8cc
ARM void Deactivate0202a8cc(char* obj, int flag) {
    if (*(unsigned char*)(obj + 0x6c) == 0) return;
    *(unsigned char*)(obj + 0x6c) = 2;
    func_0202a6c4(obj);
    *(unsigned char*)(obj + 0x71) = 0;
    *(unsigned char*)(obj + 0x73) = 0;
    *(unsigned char*)(obj + 0x74) = 0;
    if (flag != 0 && *(Callback0202a8cc*)(obj + 0x78) != NULL) {
        (*(Callback0202a8cc*)(obj + 0x78))(obj);
    }
}
