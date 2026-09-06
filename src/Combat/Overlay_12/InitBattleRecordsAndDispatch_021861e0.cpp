#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);

struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

void InitStruct0205a444(char* obj);

struct List0202fec8;

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);

// USA: func_ov012_021861e0  (semantic: InitBattleRecordsAndDispatch_021861e0)
extern "C" ARM void func_ov012_021861e0(char* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();

    for (unsigned char i = 0; i < 0x13; i++) {
        Init0205a198((struct Struct0205a198*)(*(char**)(obj + 0x1000 + 0x364) + i * 0x28));
    }

    ClearField0And40205a234(*(struct ClearTarget0205a234**)(obj + 0x1000 + 0x360));
    InitStruct0205a444(*(char**)(obj + 0x1000 + 0x35c));

    *(unsigned char*)(*(char**)(obj + 0x1000 + 0x35c) + 0x50) = 0;

    char* p1 = *(char**)(obj + 0x1000 + 0x35c);
    *(int*)(p1 + 0x40) = *(int*)(obj + 0x1000 + 0x364);
    *(short*)(p1 + 0x4c) = 0x13;

    int t360 = *(int*)(obj + 0x1000 + 0x360);
    char* p2 = *(char**)(obj + 0x1000 + 0x35c);
    *(int*)(p2 + 0x3c) = t360;

    void* recOut;
    int out1;
    int out2;
    int fieldOut;
    ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)(obj + 0x1000 + 0x390)), (void**)(&out1), (unsigned int*)(&out2));

    int count = CountActiveEntries((struct ActiveEntry02046900*)out1);
    ((SafeAllocator*)(obj + 0x5c))->Reset();

    for (int i = 0; i < count; i++) {
        void* result = FindRecordByIndex((struct Rec020467f0*)out1, i, &recOut, &fieldOut);
        func_0205a528(*(char**)(obj + 0x1000 + 0x35c), result, fieldOut, obj + 0x5c);
    }

    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)(obj + 0x1000 + 0x390)));
    *(int*)(obj + 0x1000 + 0x390) = -1;
}
