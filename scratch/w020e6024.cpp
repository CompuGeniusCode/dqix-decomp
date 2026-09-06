#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct State02070508;
ARM struct State02070508 *ClearAndReturnState020709b4(struct State02070508 *obj);

extern struct State02070508 data_02108d5c;

// USA: func_020e6024
extern "C" __declspec(initcode) ARM struct State02070508* func_020e6024(void) {
    return ClearAndReturnState020709b4(&data_02108d5c);
}
