#include <globaldefs.h>
#include "System/Random.h"

struct Wrapper_02203120 { unsigned char pad[0x68]; struct Random rng; };
extern struct Wrapper_02203120 data_ov031_0224c980;

// USA: func_ov031_02203120  (semantic: AdvanceEmbeddedRandom_02203120)
extern "C" ARM unsigned int func_ov031_02203120(void) {
	data_ov031_0224c980.rng.lcg_state = data_ov031_0224c980.rng.lcg_multiplier * data_ov031_0224c980.rng.lcg_state + data_ov031_0224c980.rng.lcg_increment;
	return data_ov031_0224c980.rng.lcg_state >> 32u;
}
