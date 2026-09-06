#include <globaldefs.h>

struct Bytes020e303c;
void ClearFourBytes020e303c(struct Bytes020e303c* s);

struct Entry020e3544 {
    unsigned char id;
    unsigned char pad[3];
};

// USA: func_020e3544
ARM void ClearMatchingEntries020e3544(struct Entry020e3544 *p, int id) {
    int i;
    for (i = 0; i < 8; ) {
        if (p->id == id) {
            ClearFourBytes020e303c((struct Bytes020e303c*)p);
        }
        i++;
        p++;
    }
}
