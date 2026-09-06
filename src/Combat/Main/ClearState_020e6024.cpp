#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct State02070508;
extern "C" void _Z27ClearAndReturnState020709b4P13State02070508(struct State02070508* obj);

extern struct State02070508 data_02108d5c;

// USA: func_020e6024
extern "C" __declspec(initcode) ARM void __sinit_020e6024(void) {
    _Z27ClearAndReturnState020709b4P13State02070508(&data_02108d5c);
}
