#include <globaldefs.h>

struct HandleFieldC_02097240 {
    int pad0;
    int pad4;
    int pad8;
    short value;
};

short GetHandleFieldC(struct HandleFieldC_02097240* obj);

struct List02097430 {
    int pad0;
    unsigned int field4 : 12;
    unsigned int field4hi : 20;
    char* arrayBase;
};

// USA: func_02097430
ARM void* FindHandleFieldC02097430(struct List02097430* obj, int target) {
    int hi, lo;
    char* base = obj->arrayBase;
    if (base == 0 || (void*)GetHandleFieldC == 0) return 0;
    unsigned int count = obj->field4;
    if (count == 0) return 0;
    hi = count - 1;
    lo = 0;
    void* found = 0;
    while (lo <= hi) {
        int mid = lo + ((hi - lo + 1) >> 1);
        HandleFieldC_02097240* elem = (HandleFieldC_02097240*)(base + (mid << 5));
        found = elem;
        int val = GetHandleFieldC(elem);
        if (val == target) return found;
        if (val > target) hi = mid - 1;
        else lo = mid + 1;
    }
    return 0;
}
