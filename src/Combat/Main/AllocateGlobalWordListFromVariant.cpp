#include <globaldefs.h>

struct Variant02030b0c;
struct WordList0209ccec;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);
void AllocateWordList0209ccec(struct WordList0209ccec*, int);
extern int data_02109be0;

// USA: func_0209cb74
ARM int AllocateGlobalWordListFromVariant(struct Variant02030b0c* p) {
    AllocateWordList0209ccec((struct WordList0209ccec*)&data_02109be0, _ZNK6Script9Parameter5ToIntEv(p));
    return 1;
}
