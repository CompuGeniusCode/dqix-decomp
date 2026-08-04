#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry021e6b8c {
    int fieldA;
    short fieldB;
    short fieldC;
    short weight;
    short factor;
};

struct Frame021e6b8c {
    void* q;
    void* p;
    unsigned char local14[0xc];
};

extern "C" void func_ov003_0215ec68(int idx, short* outA, short* outB);
extern "C" void func_0205b890(void* arr, int count, void* table);
extern "C" void _Z20ClearTwoWordsAndByteP6S_b20c(void* p);
extern "C" void _Z18SetField0_0205b220Pvi(void* p, int val);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void* p, int arr, unsigned char count);
extern "C" int func_0205b734(void* a, int b, int c, short d, short e, int f);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);
extern "C" int func_020420e8(void* p, int flag);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(void* p, unsigned size);
extern "C" void _Z15CleanCacheRangePKvj(void* p, unsigned size);
extern "C" int func_020c5a28(int, int, unsigned int);

// USA: func_ov023_021e6b8c
ARM void UpdateEntryTexture_021e6b8c(int* obj) {
    char* base = (char*)obj + 0x1000;
    if (*(unsigned char*)(base + 0x371) != 0xe) return;
    unsigned char state = *(unsigned char*)(base + 0x370);
    if (state <= 1) return;
    if (state >= 0xa) return;

    char* r5 = *(char**)*(char**)obj;
    unsigned char fieldE;
    if (r5 == 0 || (fieldE = *(unsigned char*)(r5 + 0xe)) == 3) return;

    char* table = *(char**)(base + 0x364);
    char* entry = table + (fieldE + 0xf) * 0x28;

    short outA, outB;
    func_ov003_0215ec68(fieldE, &outA, &outB);

    Entry021e6b8c arr[3];
    for (int i = 0; i < 3; i++) {
        arr[i].fieldA = 0;
        arr[i].fieldB = 0;
        arr[i].fieldC = 0;
        arr[i].weight = 0;
        arr[i].factor = 0;
    }

    func_0205b890(arr, 3, entry);

    int sum = 0;
    int accum = 0;
    for (int i = 0; i < 3; i++) {
        arr[i].fieldB = (short)sum;
        sum += arr[i].weight;
        accum += (arr[i].weight * arr[i].factor) >> 1;
    }

    Frame021e6b8c frame;
    char* p = *(char**)(entry + 4);
    unsigned short masked = *(unsigned short*)(p + 4) & 0x3ff;
    unsigned short shifted = masked << 5;
    void* src = (void*)(shifted + 0x6400000);
    frame.q = *(void**)(entry + 0);
    frame.p = p;
    memcpy(*(void**)((char*)obj + 0x1000 + 0x37c), src, accum);

    char* worldB = *(char**)obj;
    unsigned char f0d = *(unsigned char*)(r5 + 0xd);
    unsigned char f1e = *(unsigned char*)(worldB + 0x1e);
    unsigned char f20 = *(unsigned char*)(worldB + 0x20);
    int r8 = *(int*)(r5 + 0x4);
    if (f0d == 0 && (f20 != 0 || (f1e & 2))) {
        r8 = *(int*)(r5 + 0x8);
    }

    int measured = func_020420e8((void*)r8, 1);
    int half = (outA - measured) >> 1;

    _Z20ClearTwoWordsAndByteP6S_b20c(frame.local14);
    _Z18SetField0_0205b220Pvi(frame.local14, (int)*(void**)((char*)obj + 0x1000 + 0x37c));
    _Z29SetFieldsAt0x4And0x8_0205b228Pvih(frame.local14, (int)(void*)arr, 3);

    func_0205b734(frame.local14, 9, 9, (short)(outA + 7), (short)(outB + 7), 9);
    func_0205b234(frame.local14, (short)(half + 8), (short)10, r8, (unsigned char)2, (unsigned char)1);

    _Z25CleanInvalidateCacheRangePKvj(*(void**)((char*)obj + 0x1000 + 0x37c), accum);
    func_020c5a28((int)*(void**)((char*)obj + 0x1000 + 0x37c), (int)shifted, accum);
    _Z15CleanCacheRangePKvj(*(void**)((char*)obj + 0x1000 + 0x37c), accum);
}
