#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

int GetData02104304Field4();

struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);

void InitStruct0205a444(char* obj);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);
extern "C" void func_020301c8(int listPtr, int handle);

// USA: func_ov012_021862fc
extern "C" ARM void func_ov012_021862fc(char* self) {
    int listPtr = GetData02104304Field4();

    for (int i = 0; i < 3; i++) {
        Init0205a198((struct Struct0205a198*)(*(char**)(self + 0x1000 + 0x36c) + i * 0x28));
    }

    InitStruct0205a444(*(char**)(self + 0x1000 + 0x368));

    *(unsigned char*)(*(char**)(self + 0x1000 + 0x368) + 0x50) = 1;

    char* p1 = *(char**)(self + 0x1000 + 0x368);
    *(int*)(p1 + 0x40) = *(int*)(self + 0x1000 + 0x36c);
    *(short*)(p1 + 0x4c) = 3;

    void* recOut;
    int out1;
    int out2;
    int fieldOut;
    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *(int*)(self + 0x1000 + 0x394), &out1, &out2);

    int count = CountActiveEntries((struct ActiveEntry02046900*)out1);
    ((SafeAllocator*)(self + 0x98))->Reset();

    for (int i = 0; i < count; i++) {
        void* result = FindRecordByIndex((struct Rec020467f0*)out1, i, &recOut, &fieldOut);
        func_0205a528(*(char**)(self + 0x1000 + 0x368), result, fieldOut, self + 0x98);
    }

    func_020301c8(listPtr, *(int*)(self + 0x1000 + 0x394));
    *(int*)(self + 0x1000 + 0x394) = -1;
}
