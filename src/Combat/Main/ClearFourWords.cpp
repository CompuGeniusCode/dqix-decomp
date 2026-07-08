#include <globaldefs.h>

struct FourWords {
    int field0;
    int field4;
    int field8;
    int fieldc;
};

// USA: func_020c805c
ARM void ClearFourWords(struct FourWords* p) {
    p->field4 = 0;
    p->field0 = 0;
    p->field8 = 0;
    p->fieldc = 0;
}
