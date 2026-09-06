#include <globaldefs.h>
int IssueBattleCommandSlot0(int, int, int, int);


// USA: func_020d4f8c
ARM int CallFunc020d4fa4Flag(int a, int b, int c, int d) {
    int v = 1;
    if (d == 0) v |= 2;
    return IssueBattleCommandSlot0((int)(a), (int)(b), (int)(c), (int)(v));
}
