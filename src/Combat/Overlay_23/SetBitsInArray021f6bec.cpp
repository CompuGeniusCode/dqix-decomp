#include <globaldefs.h>

// USA: func_ov023_021f6bec
ARM void SetBitsInArray021f6bec(void* obj, int elemIndex, unsigned int startBit, unsigned int count) {
    if (startBit >= 0x80) return;
    int* arr = (int*)((char*)obj + 8 + (elemIndex << 4));
    unsigned short n = 0;
    while (n < count) {
        int idx = startBit / 4;
        arr[idx] |= 1 << (startBit & 3);
        startBit++;
        n++;
    }
}
