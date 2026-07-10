#include <globaldefs.h>

struct Variant02030b0c;
struct WordList0209ccec;
int GetIntFromVariant02030b0c(struct Variant02030b0c*);
void AllocateWordList0209ccec(struct WordList0209ccec*, int);
extern int data_02109be0;

// USA: func_0209cb74
ARM int AllocateGlobalWordListFromVariant(struct Variant02030b0c* p) {
    AllocateWordList0209ccec((struct WordList0209ccec*)&data_02109be0, GetIntFromVariant02030b0c(p));
    return 1;
}
