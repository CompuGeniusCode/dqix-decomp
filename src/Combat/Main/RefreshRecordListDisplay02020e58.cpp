#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"



struct List0202fec8;

struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void ResetList0204af64(List0204af64* obj);

void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);

extern "C" void func_0204b5b4(void*, int);

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(Obj0204b5e8* obj, int a, int b);

void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8* obj, void* buf);

struct List0204afb4;
void ResetRecordList0204afb4(List0204afb4* obj);


struct LocalListStruct02020e58 {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1d[3];
};

// USA: func_02020e58
ARM void RefreshRecordListDisplay02020e58(void* self, int* handle) {
    int data4 = (int)BackgroundLoader::GetInstance();
    int recListHead = 0;
    int val2Ignored = 0;
    int r = ((BackgroundLoader*)(data4))->GetTaskStatus((int)(*handle));
    if (r == -1) {
        *(unsigned int*)0x04001000 = (*(unsigned int*)0x04001000 & ~0x1f00) | 0x200;
        *((unsigned char*)self + 0x768) = 0;
    } else {
        void* dummyPtr;
        void* arrayC[3];
        int arrayB[3];
        LocalListStruct02020e58 s;

        ((BackgroundLoader*)((List0202fec8*)data4))->GetLoadedFileByID((int)(*handle), (void**)(&recListHead), (unsigned int*)(&val2Ignored));
        int count = CountActiveEntries((ActiveEntry02046900*)recListHead);
        for (int i = 0; i < count; i++) {
            arrayC[i] = FindRecordByIndex((Rec020467f0*)recListHead, i, &dummyPtr, &arrayB[i]);
        }
        ResetList0204af64((List0204af64*)&s);
        s.lo = 1;
        s.hi = 0;
        func_0204b5b4(&s, 2);
        SetWord0x18ClearByte0x1f((unsigned char*)&s, 0);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&s, 0, 0);
        for (int i = 0; i < count; i++) {
            DispatchByTag0204b2e0(&s, (char*)arrayC[i]);
            DispatchByTagLookup0204b3a0((SelfTag0204b3a0*)&s, (char*)arrayC[i]);
        }
        FlushAndDispatchList0204b0e8((List0204b0e8*)&s, 0);
        ResetRecordList0204afb4((List0204afb4*)&s);
        *((unsigned char*)self + 0x55c) = 1;
    }
    int data4b = (int)BackgroundLoader::GetInstance();
    ((BackgroundLoader*)(data4b))->RemoveTask((int)(*handle));
    *handle = -1;
}
