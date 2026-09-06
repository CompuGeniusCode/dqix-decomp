#include <globaldefs.h>
void ClearField0x0_020bec74(int*);
void ClearField0x0_020bc078(int*);


// USA: func_0203a914
ARM void InitObjectFields0203a914(void* obj) {
    char* p = (char*)obj;
    *(int*)(p + 0x0) = 0;
    ClearField0x0_020bc078((int*)(p + 0x98));
    ClearField0x0_020bec74((int*)(p + 0x9c));
    *(short*)(p + 0xa4) = -1;
    *(int*)(p + 0xa8) = 0;
    *(short*)(p + 0xac) = -1;
    *(short*)(p + 0xae) = -1;
}
