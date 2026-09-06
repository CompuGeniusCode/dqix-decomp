#include <globaldefs.h>

extern "C" void VectorizedInvertedMemcpy(void* src, void* dest, unsigned int len);
extern "C" void func_020c04e8(void* obj);

// USA: func_020c0368  (semantic: WriteToRingBuffer_020c0368)
extern "C" ARM void func_020c0368(void* obj, void* src, unsigned int size) {
    unsigned int offset = *(unsigned int*)((char*)obj + 0x10) & 0x3f;
    *(unsigned long long*)((char*)obj + 0x10) += size;
    unsigned int room = 0x40 - offset;
    if (room > size) {
        if (size == 0) return;
        VectorizedInvertedMemcpy(src, (char*)obj + 0x18 + offset, size);
        return;
    }
    VectorizedInvertedMemcpy(src, (char*)obj + 0x18 + offset, room);
    func_020c04e8(obj);
    size -= room;
    int blocks = size >> 6;
    char* srcPtr = (char*)src + room;
    if (blocks > 0) {
        do {
            VectorizedInvertedMemcpy(srcPtr, (char*)obj + 0x18, 0x40);
            srcPtr += 0x40;
            func_020c04e8(obj);
            blocks--;
        } while (blocks > 0);
    }
    unsigned int tail = size & 0x3f;
    if (tail == 0) return;
    VectorizedInvertedMemcpy(srcPtr, (char*)obj + 0x18, tail);
}
