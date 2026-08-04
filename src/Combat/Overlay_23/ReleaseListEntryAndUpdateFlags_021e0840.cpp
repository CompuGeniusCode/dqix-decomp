#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int GetData02104304Field4();
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40* p);
void ClearStruct16(void* p);
void ResetIfNonNeg_021db2e4(volatile int* p);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);

int TestBitInByteArray(int unused, unsigned char* arr, int index);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020301c8(int a, int b);
    void func_020df850(void* a, void* b, int out1, int out2, int fifth);
    void* func_0205ec34(void);
    int func_02005a94(signed char* s);
    void func_0204c684(void* buf);
    void func_ov023_021db314(void* obj, short* out, short* outCount);
    void func_ov023_021db634(void* a, void* buf);
    int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
}

extern int data_ov023_021ff9e0[];

struct Entry021e0840 {
    unsigned char pad0;
    unsigned char flag1;
    unsigned char pad2[2];
    char* str;
};

struct List021e0840 {
    unsigned char pad0[2];
    short count;
    Entry021e0840* entries;
};

// USA: func_ov023_021e0840  (semantic: ReleaseListEntryAndUpdateFlags_021e0840)
extern "C" ARM int func_ov023_021e0840(void* obj_) {
    char* obj = (char*)obj_;
    char buf[0xe0];
    short codes[12];
    int out1, out2;
    short count2;

    if (*(int*)(obj + 0x744) == -1) {
        return 0xd;
    }

    int listPtr = GetData02104304Field4();
    if (!func_0202fdd0(listPtr, *(int*)(obj + 0x744))) {
        goto ret9;
    }

    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *(int*)(obj + 0x744), &out1, &out2);
    if (out1 == 0 || out2 == 0) {
        goto ret9;
    }

    ResetAndDetach020dfc6c((struct Struct020dfc40*)(obj + 0x8c));
    ClearStruct16(obj + 0x7c);
    ResetAndDetach020dfc6c((struct Struct020dfc40*)(obj + 0xa4));
    ((class SafeAllocator*)(obj + 0x28))->Reset();

    int v = *(short*)((char*)*(void**)(obj + 0x4c) + 0x18);
    func_020df850(obj + 0x6c, obj + 0x28, out1, out2, v);

    struct List021e0840* list = *(struct List021e0840**)(obj + 0x74);
    if (list) {
        int i;
        short count;
        void* base;
        struct Entry021e0840* entry = list->entries;
        base = func_0205ec34();
        count = list->count;
        for (i = 0; i < count; i++, entry++) {
            char* str = entry->str;
            if (!str) continue;
            if ((signed char)str[0] != 'f') continue;
            if (strlen(str) < 5) continue;
            int parsed = func_02005a94((signed char*)(str + 5));
            int index = parsed + 0x12 + 0xc00;
            if (!TestBitInByteArray((int)base, (unsigned char*)base + 0x8c, index)) {
                entry->flag1 = 0;
            }
        }
    }

    func_020301c8(listPtr, *(int*)(obj + 0x744));
    *(int*)(obj + 0x744) = -1;

    count2 = 0;
    if (*(void**)(obj + 0x74)) {
        func_ov023_021db314(obj + 0x6c, codes, &count2);
    }
    if (count2 != 0) {
        goto retB;
    }

    func_0204c684(buf);
    if (InitBufferFromDataField4_021ddc34(buf, 0, 0, 0x1c, 6)) {
        if (!(*(unsigned short*)(obj + 0x774) & 0x400)) {
            func_ov023_021db634(obj + 0xcc, buf);
        }
        int result = func_ov023_021ddc98(buf, *(int*)(obj + 0x75c), (unsigned short)data_ov023_021ff9e0[3], 0);
        *(int*)(obj + 0x75c) = *(int*)(obj + 0x75c) + result;
    }

    ResetIfNonNeg_021db2e4((volatile int*)(obj + 0x748));
    return 0xd;

retB:
    return 0xb;

ret9:
    return 9;
}
