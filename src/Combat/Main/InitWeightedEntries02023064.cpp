#include <globaldefs.h>

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

void ClearStruct02020520(struct Struct02020520* s);

// USA: func_02023064
ARM void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d) {
    int result = 0;
    unsigned int i;
    for (i = 0; i < count; i++) {
        struct Struct02020520* elem = &arr[i];
        ClearStruct02020520(elem);
        elem->a = result;
        elem->b = a[i];
        elem->c = b[i];
        elem->d = c[i];
        elem->e = d[i];
        result += (c[i] * d[i]) / 2;
    }
}
