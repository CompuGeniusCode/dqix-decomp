#include <globaldefs.h>

void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_0211e33c[];

// USA: func_ov001_0215a750
ARM unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr) {
    ShiftInBitOnGlobalObject();
    unsigned int size = 0;
    void* result = LoadFileIntoMemory(path, data_0211e33c, &size);
    if (result == NULL) return 0;
    HalveGlobalObjectCounter();
    *outPtr = data_0211e33c;
    return size;
}
