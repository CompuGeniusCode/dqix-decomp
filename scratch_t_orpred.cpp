#include <globaldefs.h>
ARM int TestOrPred(int a, int b, int c) {
    if (a > b || c < b) return 1;
    return 0;
}
