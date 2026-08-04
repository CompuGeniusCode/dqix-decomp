#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_ov031_022201d8  (semantic: ParsePacketHeaderAndVerifyChecksum_022201d8)
extern "C" THUMB unsigned char* func_ov031_022201d8(unsigned char* p, unsigned int* typeOut, unsigned int* lenOut) {
    unsigned short type = *(unsigned short*)(p + 0);
    unsigned int sum = 0;
    *typeOut = (unsigned short)((unsigned char)(type >> 8) | ((type << 8) & 0xff00));

    unsigned short len = *(unsigned short*)(p + 2);
    unsigned int swappedLen = (unsigned short)((unsigned char)(len >> 8) | ((len << 8) & 0xff00));
    *lenOut = swappedLen;

    unsigned char* end = p + 6 + swappedLen;
    unsigned char* cur = p;
    if (cur < end) {
        do {
            sum += *cur++;
        } while (cur < end);
    }
    unsigned short checksum = *(unsigned short*)end;
    unsigned short swappedChecksum = (unsigned short)((unsigned char)(checksum >> 8) | ((checksum << 8) & 0xff00));
    if ((unsigned short)sum != swappedChecksum)
        return 0;
    return p + 6;
}
