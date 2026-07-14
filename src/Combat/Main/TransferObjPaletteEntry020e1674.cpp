#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2);
int TransferSubObjPalette(int arg0, int arg1, unsigned int arg2);

struct Inner020e1674 {
    char pad[0x3e];
    unsigned char flag;
};
struct Obj020e1674 {
    char pad[4];
    struct Inner020e1674* ptr;
};

// USA: func_020e1674
ARM void TransferObjPaletteEntry020e1674(struct Obj020e1674* obj, int idx, int sel) {
    int off, addr;
    if (sel < 0 || sel >= 2) return;
    addr = (int)((char*)obj + 0x22 + sel * 2);
    off = idx * 2;
    CleanInvalidateCacheRange((const void*)(addr), 2);
    off += 0x1c0;
    if (obj->ptr->flag == 0) {
        TransferMainObjPalette(addr, off, 2);
    } else {
        TransferSubObjPalette(addr, off, 2);
    }
    CleanCacheRange((const void*)(addr), 2);
}
