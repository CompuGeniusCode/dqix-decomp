#include <globaldefs.h>

struct NitroVM;
int NitroVM_Seek(struct NitroVM* vm, int position, int whence);
int NitroVM_ReadSync(struct NitroVM* vm, void* dst, int capacity);

struct Obj020c00c8 {
    char pad0[0xa4];
    int field_a4;
};

// USA: func_020c00c8
ARM int AdjustDeltaThenSetupEffect020c00c8(struct Obj020c00c8* obj, int b, int c, int d) {
    NitroVM_Seek((struct NitroVM*)((char*)obj + 0x5c), obj->field_a4 + d, 0);
    return NitroVM_ReadSync((struct NitroVM*)((char*)obj + 0x5c), (void*)b, c);
}
