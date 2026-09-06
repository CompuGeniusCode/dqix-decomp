#include <globaldefs.h>

struct Md5State020c0328 {
    unsigned int a, b, c, d;   /* 0x0,0x4,0x8,0xc */
    unsigned int countLow;      /* 0x10 */
    unsigned int countHigh;     /* 0x14 */
};

// USA: func_020c0328
ARM void InitMd5State(struct Md5State020c0328* state) {
    state->a = 0x67452301;
    state->b = 0xefcdab89;
    state->c = 0x98badcfe;
    state->d = 0x10325476;
    state->countLow = 0;
    state->countHigh = 0;
}
