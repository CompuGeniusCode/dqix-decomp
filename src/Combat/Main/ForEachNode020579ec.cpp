#include <globaldefs.h>
void MaybeSwapPairTables020555a0(struct Obj020555a0*);


struct Node020579ec {
    char pad[0x1ec];
    Node020579ec* next;  // 0x1ec
};

// USA: func_020579ec
ARM void ForEachNode020579ec(Node020579ec** pp) {
    Node020579ec* n = *pp;
    while (n != NULL) {
        MaybeSwapPairTables020555a0((struct Obj020555a0*)(n));
        n = n->next;
    }
}
