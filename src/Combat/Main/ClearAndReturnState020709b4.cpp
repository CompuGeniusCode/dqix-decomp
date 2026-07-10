#include <globaldefs.h>

struct State02070508;
void ClearState02070508(struct State02070508 *obj);

// USA: func_020709b4
ARM struct State02070508 *ClearAndReturnState020709b4(struct State02070508 *obj) {
    ClearState02070508(obj);
    return obj;
}
