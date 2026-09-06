#include <globaldefs.h>

struct Pair020b0d80 { unsigned short key; unsigned short value; };

// USA: func_020b0d80  (semantic: LookupValueByMode_020b0d80)
extern "C" ARM unsigned short func_020b0d80(void* obj, unsigned short input) {
    unsigned short result = 0xffff;
    unsigned short mode = *(unsigned short*)((char*)obj + 4);
    switch (mode) {
    case 0: {
        unsigned short base = *(unsigned short*)obj;
        unsigned short val = *(unsigned short*)((char*)obj + 0xc);
        result = (unsigned short)(val + (input - base));
        break;
    }
    case 1: {
        unsigned short base = *(unsigned short*)obj;
        result = *(unsigned short*)((char*)obj + 0xc + (input - base) * 2);
        break;
    }
    case 2: {
        unsigned short count = *(unsigned short*)((char*)obj + 0xc);
        Pair020b0d80* arr = (Pair020b0d80*)((char*)obj + 0xe);
        Pair020b0d80* lo = arr;
        Pair020b0d80* hi = arr + (count - 1);
        if (lo <= hi) {
            do {
                Pair020b0d80* mid = lo + (hi - lo) / 2;
                if (mid->key < input) lo = mid + 1;
                else if (input < mid->key) hi = mid - 1;
                else { result = mid->value; break; }
            } while (lo <= hi);
        }
        break;
    }
    }
    return result;
}
