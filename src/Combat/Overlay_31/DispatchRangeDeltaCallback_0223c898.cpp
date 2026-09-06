#include <globaldefs.h>

struct ParamA020b1d70;
struct Obj020b1d70;
extern int ApplyRangeDeltaCallback020b1d70(struct ParamA020b1d70* paramA, struct Obj020b1d70** paramB, int accA, int accB, int paramE, unsigned short paramF);

extern char* data_ov031_02290d38;

// USA: func_ov031_0223c898
ARM int DispatchRangeDeltaCallback_0223c898(struct ParamA020b1d70* paramA, int accA, int accB, int paramE, unsigned short paramF, int index) {
    struct Obj020b1d70** paramB = (struct Obj020b1d70**)(data_ov031_02290d38 + index * 8);
    return ApplyRangeDeltaCallback020b1d70(paramA, paramB, accA, accB, paramE, paramF);
}
