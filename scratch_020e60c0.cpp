#include <globaldefs.h>
#include "System/Random.h"

#pragma define_section initcode ".init" RX

extern char const data_020f0d66[];

// USA: func_020e60c0
extern "C" __declspec(initcode) ARM struct Random* func_020e60c0(void) {
    return CreateRandom(&data_02108ddc, data_020f0d66, 1);
}
