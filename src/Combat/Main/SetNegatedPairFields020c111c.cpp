#include <globaldefs.h>

struct NegatedPairStruct020c111c {
    int field0;
    int field4;
    int field8;
    int fieldc;
};

// USA: func_020c111c  (semantic: SetNegatedPairFields020c111c)
extern "C" THUMB void func_020c111c(struct NegatedPairStruct020c111c* obj, int b, int c) {
    obj->field0 = c;
    obj->field4 = b;
    obj->field8 = -b;
    obj->fieldc = c;
}
