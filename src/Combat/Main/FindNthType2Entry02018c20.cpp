#include <globaldefs.h>

void* GetElementStride0x74(unsigned char* obj, int index);

// USA: func_02018c20
ARM void* FindNthType2Entry02018c20(unsigned char* obj, int n) {
    unsigned char* p = (unsigned char*)GetElementStride0x74(obj + 0x6c, 0);
    int count = *(int*)(obj + 0x94);
    int i;
    for (i = 0; i < count; i++) {
        if (*(int*)(p + 4) == 2) {
            if (n == 0) return p;
            n--;
        }
        p += 0x74;
    }
    return NULL;
}
