#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);

struct B190Outer;
int GetBits12To15Clamped(int unused, struct B190Outer* obj);
void* GetEntryPtr_021fa854(char* obj, unsigned int idx);
void SetBit_021f6e10(void* obj, int idx, unsigned int bit);
int GetGlobalField0x1c020421a0();

int FindFileOrRecord_021fad20(const void* narcBuffer, const char* name, const void** outData, unsigned int* outSize);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);

struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* p);

struct ListNode021f6d14 { unsigned int key; int pad4; void* prev; void* next; };
struct List021f6d14;
extern "C" void func_ov023_021f6d14(struct List021f6d14* list, struct ListNode021f6d14* node);

extern const char data_ov023_021fec44[];
extern const char data_ov023_021fec49[];
extern const char data_ov023_021fec4e[];
extern const char data_ov023_021fec53[];

// USA: func_ov023_021fab48  (semantic: LoadEntryFilesAndRegister_021fab48)
extern "C" ARM void func_ov023_021fab48(void* obj, void* ctx, const void* narcBuffer, int flag4) {
    if (narcBuffer == 0 || flag4 == 0) return;
    void* base = func_ov011_021845f8(ctx, *(unsigned short*)((char*)obj + 8));
    if (base == 0) return;
    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();

    const void* outData;
    unsigned int outSize;
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec44, &outData, &outSize) != 0) {
        func_0205a528((char*)obj + 0x24, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec49, &outData, &outSize) != 0) {
        func_0205a528((char*)obj + 0x24, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec4e, &outData, &outSize) != 0) {
        func_0205a528((char*)obj + 0x24, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec53, &outData, &outSize) != 0) {
        void* alloc = ((SafeAllocator*)((char*)base + 4))->Allocate(8);
        if (alloc != 0) {
            ClearField0And40205a234((struct ClearTarget0205a234*)alloc);
            *(void**)((char*)obj + 0x60) = alloc;
            func_0205a528((char*)obj + 0x24, (void*)outData, (int)outSize, (char*)base + 4);
        }
    }

    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();
    void* list;
    int field6c = *(int*)((char*)obj + 0x6c);
    list = func_ov011_021849c8(ctx);
    *(int*)((char*)obj + 0x78) = 0;
    *(int*)((char*)obj + 0x7c) = field6c;
    func_ov023_021f6d14((struct List021f6d14*)list, (struct ListNode021f6d14*)((char*)obj + 0x78));

    for (unsigned int i = 0; i < *(unsigned short*)((char*)obj + 0x72); i++) {
        void* entry = GetEntryPtr_021fa854((char*)obj + 0x24, (unsigned short)i);
        if (entry != 0) {
            int bits = GetBits12To15Clamped((int)((char*)obj + 0x24), (struct B190Outer*)entry);
            unsigned char byteVal = *(unsigned char*)((char*)obj + 0x74);
            SetBit_021f6e10(list, byteVal, (unsigned int)bits);
        }
    }

    char* global = (char*)GetGlobalField0x1c020421a0();
    *(void**)(global + 0x2d8) = (char*)obj + 0x24;
    *(int*)(global + 0x2dc) = *(int*)((char*)obj + 0x64);
    *(short*)(global + 0x2e4) = 0;
    *(int*)(global + 0x2e0) = *(int*)((char*)obj + 0x60);
    *(unsigned char*)(global + 0x2e6) = 1;
}
