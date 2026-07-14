#include <globaldefs.h>

extern "C" void func_020b6acc(int id, void* data, int count);
void SubmitPendingCommandBlocks(void* r6, void* r5);

struct Hdr020b6c3c {
    char pad0;
    unsigned char count;
    char pad2[4];
    unsigned short stride;
};

#pragma optimize_for_size off
// USA: func_020b6c3c
ARM int GetBitsAndDispatch020b6c3c(void* a0, void* a1, void* a2, unsigned int a3) {
    void* field = *(void**)((char*)a0 + 4);
    struct Hdr020b6c3c* hdr = (struct Hdr020b6c3c*)((char*)field + 0x40);
    unsigned int* entryPtr;
    void* result;

    if (hdr == 0) goto labelZero;
    if (hdr != 0 && a3 < hdr->count) {
        unsigned short stride = hdr->stride;
        unsigned short elemSize = *(unsigned short*)((char*)hdr + stride);
        entryPtr = (unsigned int*)((char*)hdr + stride + 4 + elemSize * a3);
    } else {
        entryPtr = 0;
    }
    if (entryPtr != 0) {
        result = (char*)hdr + *entryPtr;
        goto labelRead;
    }
labelZero:
    result = 0;
labelRead:
    {
        unsigned short v = *(unsigned short*)result;
        unsigned int masked = (unsigned int)v & 0xf800;
        unsigned int bits = masked >> 0xb;
        if (bits != 0x1f) {
            int arr[1];
            arr[0] = bits;
            func_020b6acc(0x14, arr, 1);
            if (a1 != 0 || a2 != 0) {
                SubmitPendingCommandBlocks(a1, a2);
            }
            return 1;
        }
    }
    return 0;
}
