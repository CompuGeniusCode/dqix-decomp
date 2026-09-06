#include <globaldefs.h>
struct BitArray020839dc { unsigned char pad[0x910]; unsigned char bytes[9]; };
// USA: func_020839dc
ARM int CollectSetBitIndices020839dc(struct BitArray020839dc* s, unsigned char* out, int max) {
    int byteIdx;
    int bit;
    int count;
    count = 0;
    for (byteIdx = 0; byteIdx < 9; byteIdx++) {
        if (s->bytes[byteIdx] == 0) {
            continue;
        }
        for (bit = 0; bit < 8; bit++) {
            if (s->bytes[byteIdx] & (1 << bit)) {
                out[count] = (unsigned char)(bit + byteIdx * 8);
                count++;
                if (count == max) {
                    return count;
                }
            }
        }
    }
    return count;
}
