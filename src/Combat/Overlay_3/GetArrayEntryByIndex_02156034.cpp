#include <globaldefs.h>

// USA: func_ov003_02156034
ARM void* GetArrayEntryByIndex_02156034(void* obj) {
    short val = *(short*)((char*)obj + 0x1e4);
    void** arr = *(void***)((char*)obj + 0x20);
    short idx = (short)(val - 0x13);
    return arr[idx];
}
