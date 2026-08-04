#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"

int GetData02104304Field4();
extern "C" int func_0202fdd0(int, int);

struct Obj021dcb70;
unsigned char LookupByField8_021dcb70(struct Obj021dcb70* p);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204b5b4(void*, int);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str);

extern "C" int func_ov023_021e20f0(void*, void*, void*, void*);

void ClearFields_021e20c0(void* p);

extern "C" void func_020301c8(int, int);
extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* obj, void* p);

unsigned int GetSubBg0ScreenBaseAddr(void);
unsigned int GetBgCharBaseAddress020c4d1c(void);

extern const char* data_ov023_021fda78[];

// USA: func_ov023_021dfecc  (semantic: ResetAndDispatchListEntries_021dfecc)
extern "C" ARM int func_ov023_021dfecc(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    struct List0204af64 listObj;
    int listVal1;
    void* recPtr;
    int listVal2;
    int sizeOut;
    void* dummyOut;
    int result;

    int listPtr = GetData02104304Field4();
    int handle = *(int*)(obj + 0x734);
    if (func_0202fdd0(listPtr, handle) != 0) {
        unsigned char lookupResult = LookupByField8_021dcb70((struct Obj021dcb70*)*(void**)(obj + 0x50));
        GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *(int*)(obj + 0x734), &listVal1, &listVal2);

        if (listVal1 != 0 && listVal2 != 0) {
            ResetList0204af64(&listObj);

            signed char f7c = *(signed char*)(obj + 0x700 + 0x7c);
            if (f7c == 1) {
                listObj.b1c_lo = f7c;
                listObj.b1c_hi = 1;
            } else {
                listObj.b1c_lo = f7c;
                listObj.b1c_hi = 3;
            }

            func_0204b5b4(&listObj, 3);
            SetWord0x18ClearByte0x1f((unsigned char*)&listObj, 0);
            DispatchViaTable0204b5e8((struct Obj0204b5e8*)&listObj, 0, 0);

            if (*(signed char*)(obj + 0x700 + 0x7c) == 1) {
                volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
                unsigned int bits = 0x12;
                if (lookupResult != 0) bits |= 1;
                *reg = (*reg & ~0x1f00) | (bits << 8);
            }

            if (lookupResult == 0 && *(unsigned char*)(obj + 0x778) != 0) {
                int count = CountActiveEntries((struct ActiveEntry02046900*)listVal1);
                for (unsigned char i = 0; i < count; i++) {
                    recPtr = FindRecordByIndex((struct Rec020467f0*)listVal1, i, &dummyOut, &sizeOut);
                    if (recPtr) {
                        DispatchByTag0204b2e0(&listObj, (char*)recPtr);
                        DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&listObj, (char*)recPtr);
                        func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                    }
                }
            } else {
                ClearFields_021e20c0(obj + 0xcc);
                ((SafeAllocator*)obj)->Reset();
                for (unsigned char i = 0; i < 4; i++) {
                    if (FindFilesInNarcBySubstring((const void*)listVal1, data_ov023_021fda78[i],
                            (const void**)&recPtr, (unsigned int*)&sizeOut, 1) != 0) {
                        if (i != 3) {
                            DispatchByTag0204b2e0(&listObj, (char*)recPtr);
                            DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&listObj, (char*)recPtr);
                        } else {
                            func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                        }
                    }
                }
            }

            *(int*)(obj + 0x75c) = 0x3800;
            if (*(signed char*)(obj + 0x700 + 0x7b) == 1) {
                *(int*)(obj + 0x75c) = 0x2800;
            }
            *(int*)(obj + 0x760) = 0;
            *(int*)(obj + 0x768) = 0;

            if (*(signed char*)(obj + 0x700 + 0x7c) == 1) {
                memset((void*)GetSubBg0ScreenBaseAddr(), 0, 0x800);
                if (*(void**)(obj + 0x50) != 0) {
                    func_ov023_021dde00(obj);
                    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
                    *reg = (*reg & ~0x1f00) | 0x1300;
                }
            } else {
                memset((void*)GetBgCharBaseAddress020c4d1c(), 0, 0x800);
                if (*(void**)(obj + 0x50) != 0) {
                    func_ov023_021dde00(obj);
                }
            }
            func_ov023_021dbd10(obj + 0xcc, *(void**)(obj + 0x50));
        }

        *(unsigned char*)(obj + 0x779) = lookupResult;
        func_020301c8(listPtr, *(int*)(obj + 0x734));
        *(int*)(obj + 0x734) = -1;
        *(void**)(obj + 0x4c) = *(void**)(obj + 0x50);
        *(void**)(obj + 0x50) = 0;

        unsigned short flags74 = *(unsigned short*)(obj + 0x700 + 0x74);
        if (flags74 & 0x40) {
            if (!(flags74 & 4)) {
                flags74 |= 0x20;
                *(unsigned short*)(obj + 0x700 + 0x74) = flags74;
            }
        }

        for (int i = 0; i < 7; i++) {
            *(int*)(obj + 0x738 + i * 4) = -1;
        }

        flags74 = *(unsigned short*)(obj + 0x700 + 0x74);
        flags74 |= 0x4;
        flags74 |= 0x2000;
        *(unsigned short*)(obj + 0x700 + 0x74) = flags74;

        result = (*(void**)(obj + 0x4c) == 0) ? -1 : 2;
    } else {
        result = 1;
    }
    return result;
}
