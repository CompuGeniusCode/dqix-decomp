#include <globaldefs.h>

struct HandleFieldC_02097240;
extern "C" int GetHandleFieldC(struct HandleFieldC_02097240* obj);

struct Manager_1f2a4 {
    char pad0[4];
    unsigned int count : 12;
    unsigned int flagsRest : 20;
    char* arr;
};

// USA: func_02097430
ARM struct HandleFieldC_02097240* SearchArrayByHandleFieldC02097430(struct Manager_1f2a4* mgr, int key) {
    struct HandleFieldC_02097240* entry;
    if (mgr->arr == 0 || (int)GetHandleFieldC == 0) {
        entry = 0;
        goto found;
    }
    {
        int count = mgr->count;
        if (count == 0) {
            entry = 0;
            goto found;
        }
        int hi = count - 1;
        int lo = 0;
        char* arr = mgr->arr;
        while (lo <= hi) {
            int mid = lo + ((hi - lo + 1) >> 1);
            entry = (struct HandleFieldC_02097240*)(arr + (mid << 5));
            int val = GetHandleFieldC(entry);
            if (val == key) goto found;
            if (val > key) hi = mid - 1;
            else lo = mid + 1;
        }
        entry = 0;
    }
found:
    return entry;
}
