#include <globaldefs.h>

struct RangeHolder020b0e6c;
extern int FindValueInRangeList(struct RangeHolder020b0e6c* obj, unsigned int key);

struct Holder020b0eb4;
extern void* LookupRangeEntry020b0eb4(struct Holder020b0eb4** slot, unsigned int key);

struct Header020b1d70 {
    unsigned char b0;
    unsigned char b1;
    unsigned short stride;
    unsigned char pad4[3];
    unsigned char mode;
};

struct Obj020b1d70 {
    unsigned char pad0[2];
    unsigned short fallbackKey;
    unsigned char pad1[4];
    struct Header020b1d70* header;
};

struct Delta020b1d70 {
    signed char d0;
    unsigned char d1;
    signed char d2;
};

struct ParamA020b1d70;

struct CallbackHolder020b1d70 {
    void (*fn)(struct ParamA020b1d70* paramA, struct Obj020b1d70** paramB, int a, int b, int e, void* loc);
};

struct ParamA020b1d70 {
    unsigned char pad[0x14];
    struct CallbackHolder020b1d70* cb;
};

struct Local020b1d70 {
    struct Delta020b1d70* resultPtr;
    void* elemPtr;
};

// USA: func_020b1d70
ARM int ApplyRangeDeltaCallback020b1d70(struct ParamA020b1d70* paramA, struct Obj020b1d70** paramB, int accA, int accB, int paramE, unsigned short paramF) {
    int key = FindValueInRangeList((struct RangeHolder020b0e6c*)paramB, paramF);
    if (key == 0xffff) {
        key = (*paramB)->fallbackKey;
    }

    struct Delta020b1d70* result = (struct Delta020b1d70*)LookupRangeEntry020b0eb4((struct Holder020b0eb4**)paramB, key);

    struct Local020b1d70 local;
    local.resultPtr = result;
    local.elemPtr = (char*)(*paramB)->header + 8 + key * (*paramB)->header->stride;

    struct Header020b1d70* header = (*paramB)->header;
    switch (header->mode) {
    case 0:
    case 7:
        accA += result->d0;
        break;
    case 1:
    case 2:
        accA -= header->b0;
        accB += result->d0;
        break;
    case 3:
    case 4:
        accA -= result->d0 + result->d1;
        accB -= header->b1;
        break;
    case 5:
    case 6:
        accB -= result->d0 + header->b1;
        break;
    default:
        break;
    }

    paramA->cb->fn(paramA, paramB, accA, accB, paramE, &local);

    return local.resultPtr->d2;
}
