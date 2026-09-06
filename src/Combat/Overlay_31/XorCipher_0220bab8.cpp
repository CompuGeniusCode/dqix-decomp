#include <globaldefs.h>

// USA: func_ov031_0220bab8  (semantic: XorCipher_0220bab8)
extern "C" ARM void func_ov031_0220bab8(unsigned char *state, unsigned char *data, int len) {
    int k = 0;
    unsigned char i = state[0];
    unsigned char j = state[1];
    unsigned char *s = state + 2;

    if (len > 0) {
        do {
            i = i + 1;
            unsigned char si = s[i];
            j = j + si;
            unsigned char sj = s[j];
            s[i] = sj;
            s[j] = si;
            data[k] ^= s[(unsigned char)(si + sj)];
            k = k + 1;
        } while (k < len);
    }

    state[0] = i;
    state[1] = j;
}
