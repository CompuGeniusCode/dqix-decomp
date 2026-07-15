#include <globaldefs.h>

extern "C" unsigned long long _ull_mod(unsigned long long a, unsigned long long b);

// USA: func_ov023_021f6324
ARM void ComputeModHash_021f6324(int count, unsigned char* ptr) {
    unsigned long long acc = 0;
    while (count-- > 0) {
        unsigned char b = *ptr++;
        acc = (acc << 8) + b;
        acc = _ull_mod(acc, 0xc2a030d4ULL);
    }
}
