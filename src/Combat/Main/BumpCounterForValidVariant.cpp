#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Data02109404 {
    unsigned char pad[6];
    unsigned short count;
};
extern struct Data02109404 data_02109404;

// USA: func_020954e8
ARM int BumpCounterForValidVariant(struct Variant02030b0c* p) {
    int v = _ZNK6Script9Parameter5ToIntEv(p);
    if (v == 0xff || v == 0) {
        return 1;
    }
    data_02109404.count++;
    return 1;
}
