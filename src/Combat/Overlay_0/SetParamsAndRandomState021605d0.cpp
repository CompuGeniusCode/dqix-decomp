#include <globaldefs.h>
#include "Util/Random.h"

struct Params021605d0 {
	struct Random* random;
	int fieldB;
	int fieldC;
};

// USA: func_ov000_021605d0
ARM void SetParamsAndRandomState021605d0(unsigned char* obj, struct Params021605d0* params) {
	*(struct Random**)(obj + 0x29c) = params->random;
	*(int*)(obj + 0x2a0) = params->fieldB;
	*(int*)(obj + 0x4) = params->fieldC;

	struct Random* random = *(struct Random**)(obj + 0x29c);
	if (random == NULL) return;
	*(unsigned int*)(obj + 0x6000 + 0xe3c) = GetRandomStateHi(random);
	*(unsigned int*)(obj + 0x6000 + 0xe40) = GetRandomStateLo(random);
}
