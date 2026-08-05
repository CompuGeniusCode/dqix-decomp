#include <globaldefs.h>

struct RangeHolder020b0e6c;
int FindValueInRangeList(RangeHolder020b0e6c* obj, unsigned int key);

struct Holder020b0eb4;
void* LookupRangeEntry020b0eb4(Holder020b0eb4** slot, unsigned int key);

typedef int (*Callback020b0f00)(int*, int);

struct Obj020b0f00 {
    void* slot;
    Callback020b0f00 next;
};

// USA: func_020b0f00  (semantic: GetSequentialValues_020b0f00)
extern "C" ARM int func_020b0f00(Obj020b0f00* obj, int base, int initialLocal, int* outPtr) {
    int local = initialLocal;
    int total = 0;
    Callback020b0f00 next = obj->next;
    int id = next(&local, base);
    if (id != 0) {
        do {
            if (id == 0xa) break;

            int val = FindValueInRangeList((RangeHolder020b0e6c*)obj, id);
            if (val == 0xffff) {
                val = *(unsigned short*)((char*)obj->slot + 2);
            }
            void* entry = LookupRangeEntry020b0eb4((Holder020b0eb4**)obj, val);
            int fieldVal = *(signed char*)((char*)entry + 2);
            int delta = base + fieldVal;
            total = total + delta;
            id = next(&local, delta);
        } while (id != 0);
    }

    if (outPtr != 0) {
        outPtr[0] = (id == 0xa) ? local : 0;
    }
    if (total > 0) {
        total = total - base;
    }
    return total;
}
