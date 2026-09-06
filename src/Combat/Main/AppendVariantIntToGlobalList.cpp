#include <globaldefs.h>

struct Variant02030b0c;
struct Element0209ccc8;
struct ElementList0209ccc8;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);
void AppendElementCapped0209ccc8(struct ElementList0209ccc8*, struct Element0209ccc8*);
extern int data_02109be0;

// USA: func_0209cb94
ARM int AppendVariantIntToGlobalList(struct Variant02030b0c* p) {
    int value = _ZNK6Script9Parameter5ToIntEv(p);
    AppendElementCapped0209ccc8((struct ElementList0209ccc8*)&data_02109be0, (struct Element0209ccc8*)&value);
    return 1;
}
