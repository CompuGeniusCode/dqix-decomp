#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_0220afe0
ARM void InitMd5Ctx_0220afe0(void* ctx) {
	VectorizedMemset(ctx, 0, 0x58);
	unsigned int* words = (unsigned int*)ctx;
	words[0] = 0x67452301;
	words[1] = 0xefcdab89;
	words[2] = 0x98badcfe;
	words[3] = 0x10325476;
}
