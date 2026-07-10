#include <globaldefs.h>

void FindNodeAndProcess02057fb4(void* list, int id, int a3);
extern "C" void* func_02057924();

struct Obj020dbfa4 {
    char pad0[8];
    int word_8;
    char pad_c[4];
    int word_10;
    unsigned char byte_14;
};

// USA: func_020dbfa4
ARM void ProcessPendingNode020dbfa4(struct Obj020dbfa4* o, int arg1) {
    if (o->word_10 == 2 && o->byte_14 == 0) {
        FindNodeAndProcess02057fb4(func_02057924(), o->word_8, arg1);
        o->byte_14 = 1;
    }
}
