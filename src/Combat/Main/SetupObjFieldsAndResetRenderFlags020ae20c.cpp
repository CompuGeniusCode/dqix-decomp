#include <globaldefs.h>

struct Fields020407b4 {
    char unk0[0x44];
    int field44;
    int field48;
    int field4c;
};

void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c);
void StoreVec3AtField0x50(unsigned char* obj, int a, int b, int c);
void* GetPtrField0x114(void* obj);
int CheckBits5To9NonZero0204bedc(unsigned short* obj);
void PackFieldsAt0x9c(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f);
void SetOrClearEntryIntFlags(unsigned char* obj, int set, int mask);
extern "C" void func_02035a2c(struct Fields020407b4*, int);

// USA: func_020ae20c
ARM void SetupObjFieldsAndResetRenderFlags020ae20c(void* obj, struct Fields020407b4* b, int* v, int c) {
    if (b == NULL) return;

    SetFields0x44(b, v[0], 0xffffd009, v[2]);
    StoreVec3AtField0x50((unsigned char*)b, 0, c, 0);

    int flag = 0xc;
    void* p = GetPtrField0x114(obj);
    if (p != NULL) {
        if (CheckBits5To9NonZero0204bedc((unsigned short*)p))
            flag = 0x14;
    }

    PackFieldsAt0x9c(1, 3, 1, 0, flag, 0x8000);
    {
        void* inner = *(void**)((char*)b + 8);
        unsigned char* target = *(unsigned char**)((char*)inner + 0x54);
        SetOrClearEntryIntFlags(target, 0, 0x30);
        SetOrClearEntryIntFlags(target, 0, 0xc0);
        SetOrClearEntryIntFlags(target, 0, 0x3f000000);
        SetOrClearEntryIntFlags(target, 0, 0x1f0000);
        SetOrClearEntryIntFlags(target, 0, 0x8000);
    }
    func_02035a2c(b, 1);

    PackFieldsAt0x9c(1, 3, 3, 0x3c, flag, 0x8000);
    {
        void* inner = *(void**)((char*)b + 8);
        unsigned char* target = *(unsigned char**)((char*)inner + 0x54);
        SetOrClearEntryIntFlags(target, 0, 0x30);
        SetOrClearEntryIntFlags(target, 0, 0xc0);
        SetOrClearEntryIntFlags(target, 0, 0x3f000000);
        SetOrClearEntryIntFlags(target, 0, 0x1f0000);
        SetOrClearEntryIntFlags(target, 0, 0x8000);
    }
    func_02035a2c(b, 1);
}
