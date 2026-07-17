#include <globaldefs.h>

int GetField0x580207ecc4(void* obj);
struct Struct5e00;
int FindAndSetFreeSlot021673e0(struct Struct5e00* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void SetField0x2c(void* obj, int value);
void SetIntAt0xa4(unsigned char* obj, int value);
extern "C" int func_020dc124(void* src, int mode);

// USA: func_ov000_02166784
ARM void AllocateSlotAndConfigureField02166784(struct Struct5e00* obj1, unsigned char* obj2, unsigned char* obj3) {
    int state = *(short*)(obj3 + 0x4);
    int tmp = state - 0xc0;
    void* field;
    int slot;
    if (tmp < 0) return;
    if (tmp > 0xc7) return;
    field = *(void**)(obj2 + 0x8);
    if (!field) return;
    field = (void*)GetField0x580207ecc4(field);
    if (!field) return;
    slot = FindAndSetFreeSlot021673e0(obj1);
    {
        unsigned short off = *(unsigned short*)((char*)field + 0x30);
        int len = *(int*)((char*)field + 0x38);
        CleanInvalidateCacheRange((char*)field + len, off << 3);
        SetField0x2c(field, slot);
        func_020dc124(field, 1);
        SetIntAt0xa4(obj3, slot);
    }
}
