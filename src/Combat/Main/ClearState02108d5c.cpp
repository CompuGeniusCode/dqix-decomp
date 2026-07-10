#include <globaldefs.h>

struct State02070508;
ARM struct State02070508 *ClearAndReturnState020709b4(struct State02070508 *obj);

extern int data_02108d5c;

// USA: func_020e6024
ARM struct State02070508 *ClearState02108d5c(void) {
    return ClearAndReturnState020709b4((struct State02070508 *)&data_02108d5c);
}
