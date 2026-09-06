#include <globaldefs.h>

int GetSubstructByte0x4c(unsigned char*);
int GetSubstructByte0x4d(unsigned char*);

// USA: func_ov025_021e1f08
ARM int GetSubByteOrFallback_021e1f08(unsigned char* obj, unsigned char* other) {
    int a = GetSubstructByte0x4c(obj);
    if (a != 0xff) {
        return a;
    }
    int b = GetSubstructByte0x4d(obj);
    if (b != 0xff) {
        return b;
    }
    void* p = *(void**)(other+0x14);
    if (p != 0) {
        return *(short*)((unsigned char*)p+0xe);
    }
    return b;
}
