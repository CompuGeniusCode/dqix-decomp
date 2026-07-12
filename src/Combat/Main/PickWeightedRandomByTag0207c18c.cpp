#include <globaldefs.h>
int GetRandomUpTo02032370(int);

struct Elem0207c1ec;
struct Container0207c1ec;
int CollectByTag0207c1ec(struct Container0207c1ec* s, int key, struct Elem0207c1ec** out, int max);


// USA: func_0207c18c
ARM struct Elem0207c1ec* PickWeightedRandomByTag0207c18c(struct Container0207c1ec* s, int key) {
    struct Elem0207c1ec* buf[32];
    int count = CollectByTag0207c1ec(s, key, buf, 0x20);
    if (count == 0) return NULL;
    int roll = GetRandomUpTo02032370((int)(0x64));
    int i;
    for (i = 0; i < count; i++) {
        roll -= ((unsigned char*)buf[i])[1];
        if (roll < 0) return buf[i];
    }
    return NULL;
}
