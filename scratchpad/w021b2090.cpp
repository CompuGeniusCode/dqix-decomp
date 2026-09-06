#include <globaldefs.h>

struct PackedPos_021b2090 {
    unsigned int low : 12;
    unsigned int fieldB : 4;
    unsigned int fieldC : 5;
    unsigned int fieldD : 5;
    unsigned int fieldE : 6;
};

// USA: func_ov017_021b2090
ARM int ComparePackedPosition_021b2090(struct PackedPos_021b2090 a, struct PackedPos_021b2090 b) {
    if (a.low < b.low) return 1;
    if (a.low > b.low) return 0;

    unsigned int aTierB = a.fieldB * 1000000;
    unsigned int bTierB = b.fieldB * 1000000;
    unsigned int aTierC = aTierB + a.fieldC * 10000;
    unsigned int bTierC = bTierB + b.fieldC * 10000;
    unsigned int aTierD = aTierC + a.fieldD * 100;
    unsigned int bTierD = bTierC + b.fieldD * 100;
    unsigned int totalA = aTierD + a.fieldE;
    unsigned int totalB = bTierD + b.fieldE;

    return totalA < totalB;
}
